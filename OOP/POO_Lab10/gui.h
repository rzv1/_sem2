#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QString>
#include <map>

#include "Service.h"
#include "Tests.h"

constexpr int ID = Qt::UserRole;
constexpr int TITLE = Qt::UserRole + 1;
constexpr int AUTHOR = Qt::UserRole + 2;
constexpr int GENRE = Qt::UserRole + 3;
constexpr int YEAR = Qt::UserRole + 4;

class ShopGUI : public QWidget {
    Q_OBJECT
public:
    explicit ShopGUI(Service& srv, QWidget* parent = nullptr)
        : QWidget(parent), service{ srv }
    {
        initWidgets();
        initLayouts();
        initConnections();
        rebuildDynamicButtons();
        setWindowTitle("Book shop GUI");
        resize(780, 420);
        reloadList();
    }

private:
    Service& service;

    QListWidget  listBox;

    QLabel lblId{ "Id" }, lblTitle{ "Title" }, lblAuthor{ "Author" }, lblGenre{ "Genre" }, lblYear{ "Year" };
    QLineEdit editId, editTitle, editAuthor, editGenre, editYear;

    QPushButton  btnAdd{ "Add" }, btnUpdate{ "Update" },
        btnRemove{ "Remove" }, btnSortTitle{ "SortByTitle" }, btnSortYearGenre{ "SortByYearGenre" },
        btnFilterTitle{ "FilterByTitle" }, btnFilterYear{ "FilterByYear" },
        btnUndo{ "Undo" };

    QVBoxLayout dynButtonsLayout;

    QGridLayout gridForm;
    QHBoxLayout hAddUpd, hSort, hFilter;
    QVBoxLayout vRight, vLeft;
    QHBoxLayout mainLayout;

    void initWidgets()
    {
        listBox.setMinimumSize(320, 240);
    }

    void initLayouts()
    {
        gridForm.addWidget(&lblId, 0, 0); gridForm.addWidget(&editId, 0, 1);
        gridForm.addWidget(&lblTitle, 1, 0); gridForm.addWidget(&editTitle, 1, 1);
        gridForm.addWidget(&lblAuthor, 2, 0); gridForm.addWidget(&editAuthor, 2, 1);
        gridForm.addWidget(&lblGenre, 3, 0); gridForm.addWidget(&editGenre, 3, 1);
        gridForm.addWidget(&lblYear, 4, 0); gridForm.addWidget(&editYear, 4, 1);

        hAddUpd.addWidget(&btnAdd);
        hAddUpd.addWidget(&btnUpdate);

        hFilter.addWidget(&btnFilterTitle);
        hFilter.addWidget(&btnFilterYear);

        vRight.addLayout(&gridForm);
        vRight.addLayout(&hAddUpd);
        vRight.addLayout(&hFilter);
        vRight.addLayout(&dynButtonsLayout);
        vRight.addStretch();

        hSort.addWidget(&btnRemove);
        hSort.addWidget(&btnSortTitle);
        hSort.addWidget(&btnSortYearGenre);

        vLeft.addWidget(&listBox);
        vLeft.addLayout(&hSort);
        vLeft.addStretch();

        mainLayout.addLayout(&vLeft);
        mainLayout.addLayout(&vRight);
        setLayout(&mainLayout);
    }

    void initConnections()
    {
        connect(&btnAdd, &QPushButton::clicked, this, [this] {
            try {
                service.add(editTitle.text().toStdString(),
                    editAuthor.text().toStdString(),
                    editGenre.text().toStdString(),
                    editYear.text().toInt());
                reloadList();
                rebuildDynamicButtons();
            }
            catch (const std::exception& ex) {
                QMessageBox::warning(this, "Error", ex.what());
            }
            });

        connect(&btnUpdate, &QPushButton::clicked, this, [this] {
            try {
                const int id = editId.text().toInt();
                if (!editTitle.text().isEmpty())  service.update_title(id, editTitle.text().toStdString());
                if (!editAuthor.text().isEmpty()) service.update_author(id, editAuthor.text().toStdString());
                if (!editGenre.text().isEmpty())  service.update_genre(id, editGenre.text().toStdString());
                if (!editYear.text().isEmpty())   service.update_year(id, editYear.text().toInt());
                reloadList();
                rebuildDynamicButtons();
            }
            catch (const std::exception& ex) {
                QMessageBox::warning(this, "Error", ex.what());
            }
            });

        connect(&btnRemove, &QPushButton::clicked, this, [this] {
            if (auto* it = listBox.currentItem()) {
                try {
                    service.remove(it->data(ID).toInt());
                    reloadList();
                    rebuildDynamicButtons();
                }
                catch (const std::exception& ex) {
                    QMessageBox::warning(this, "Error", ex.what());
                }
            }
            });

        connect(&btnSortTitle, &QPushButton::clicked, this, [this] {
            populate(service.sort_title());
            });
        connect(&btnSortYearGenre, &QPushButton::clicked, this, [this] {
            populate(service.sort_year_and_genre());
            });

        connect(&btnFilterTitle, &QPushButton::clicked, this, [this] {
            populate(service.filter_title(editTitle.text().toStdString()));
            });
        connect(&btnFilterYear, &QPushButton::clicked, this, [this] {
            populate(service.filter_year(editYear.text().toInt()));
            });

        connect(&listBox, &QListWidget::itemSelectionChanged, this, [this] {
            if (auto* it = listBox.currentItem()) {
                editId.setText(it->data(ID).toString());
                editTitle.setText(it->data(TITLE).toString());
                editAuthor.setText(it->data(AUTHOR).toString());
                editGenre.setText(it->data(GENRE).toString());
                editYear.setText(it->data(YEAR).toString());
            }
            });
    }

    void rebuildDynamicButtons()
    {
        while (auto item = dynButtonsLayout.takeAt(0)) {
            auto* w = item->widget();
            if (w)
                delete w;
            delete item;
        }
        const auto raport = service.get_map();
        for (const auto& [type, dto] : raport) {
            auto* btn = new QPushButton(QString::fromStdString(type));
            dynButtonsLayout.addWidget(btn);
            connect(btn, &QPushButton::clicked, this, [this, type] {
                try {
                    int f = service.get_map().at(type).get_freq();
                    QMessageBox::information(this, "Frecventa",
                        QString::fromStdString(type + " apare de " + std::to_string(f) + " ori"));
                }
                catch (const std::exception& ex) {
                    QMessageBox::warning(this, "Error", ex.what());
                }
                });
        }
        dynButtonsLayout.addStretch();
    }

    void reloadList() { populate(service.sort_title()); }
    void populate(const std::vector<Carte>& books)
    {
        listBox.clear();
        for (const auto& b : books) {
            auto* item = new QListWidgetItem(QString::fromStdString(b.get_title()));
            item->setData(ID, b.get_id());
            item->setData(TITLE, QString::fromStdString(b.get_title()));
            item->setData(AUTHOR, QString::fromStdString(b.get_author()));
            item->setData(GENRE, QString::fromStdString(b.get_genre()));
            item->setData(YEAR, b.get_year());
            listBox.addItem(item);
        }
    }
};