#include "ui.h"
#include <stdbool.h>

void show_menu() {
	printf("1. Adauga masina\n");
	printf("2. Actualizeaza masina\n");
	printf("3. Inchiriaza masina\n");
	printf("4. Returneaza masina\n");
	printf("5. Afiseaza masini\n");
	printf("6. Filtrare masini\n");
	printf("7. Sortare masini\n");
	printf("8. Exit\n");
}

void show_update_menu() {
	printf("1. Actualizeaza numar de inmatriculare\n");
	printf("2. Actualizeaza model\n");
	printf("3. Actualizeaza categorie\n");
	printf("4. Actualizeaza starea de inchiriere\n");
	printf("5. Inapoi\n");
}

void show_filter_menu() {
	printf("1. Filtrare dupa model\n");
	printf("2. Filtrare dupa categorie\n");
	printf("3. Inapoi\n");
}

void show_sort_menu() {
	printf("1. Sortare dupa model\n");
	printf("2. Inapoi\n");
}

void run() {
	Repo* repo = create_repo();
	int option;
	do {
		show_menu();
		printf("Optiune: ");
		scanf("%d", &option);
		switch (option) {
		case 1: {
			char license[9], model[50], category[50];
			printf("Numar de inmatriculare: ");
			scanf("%s", license);
			printf("Model: ");
			scanf("%s", model);
			printf("Categorie: ");
			scanf("%s", category);
			service_add_car(repo, license, model, category);
			break;
		}
		case 2: {
			int id;
			show_update_menu();
			printf("Optiune: ");
			scanf("%d", &option);
			if (option == 5) {
				break;
			}
			printf("ID: ");
			scanf("%d", &id);
			char license[9], model[50], category[50];
			switch (option) {
			case 1:
				printf("Numar de inmatriculare: ");
				scanf("%s", license);
				service_update_license(repo, id, license);
				break;
			case 2:
				printf("Model: ");
				scanf("%s", model);
				service_update_model(repo, id, model);
				break;
			case 3:
				printf("Categorie: ");
				scanf("%s", category);
				service_update_category(repo, id, category);
				break;
			case 4:
				bool is_rented;
				printf("Inchiriata (1/0): ");
				scanf("%d", &is_rented);
				service_update_is_rented(repo, id, is_rented);
				break;
			}
			break;
		}
		case 3: {
			int id;
			printf("ID: ");
			scanf("%d", &id);
			service_update_is_rented(repo, id, true);
			break;
		}
		case 4: {
			int id;
			printf("ID: ");
			scanf("%d", &id);
			service_update_is_rented(repo, id, false);
			break;
		}
		}
	}
} while (option != 8);