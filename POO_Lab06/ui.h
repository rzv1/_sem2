#pragma once
#include "service.h"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

class UI {
private:
	Service service;
public:
	UI(Service service) : service{ service } {}
	void print_menu() {
		cout << "1. Add book\n";
		cout << "2. Remove book\n";
		cout << "3. Print all\n";
		cout << "0. Exit\n";
	}

	void ui_add() {
		string title, author, genre;
		int year;
		cout << "Title: ";
		cin >> title;
		cout << "Author: ";
		cin >> author;
		cout << "Genre: ";
		cin >> genre;
		cout << "Year: ";
		cin >> year;
		service.add_book(title, author, genre, year);
	}

	void ui_remove() {
		int id;
		cout << "ID: ";
		cin >> id;
		service.remove_book(id);
	}

	void ui_print() {
		vector<Carte> carti = service.get_all();
		for (const auto& c : carti) {
			cout << c.get_id() << " " << c.get_title() << " " << c.get_author() << " " << c.get_genre() << " " << c.get_year() << "\n";
		}
	}

	void ruleaza() {
		while (true) {
			cout << "1. Add book\n";
			cout << "2. Remove book\n";
			cout << "3. Print all\n";
			cout << "0. Exit\n";
			int cmd;
			cin >> cmd;
			switch (cmd) {
			case 1:
				ui_add();
				break;
			case 2:
				ui_remove();
				break;
			case 3:
				ui_print();
				break;
			case 0:
				return;
			}
		}
	}
}