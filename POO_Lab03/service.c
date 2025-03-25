#include "service.h"
#include "masina.h"
#include "repo.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool service_add_car(Repo* repo, const char* license, const char* model, const char* category) {
	if (validate_category(category) == false) {
		return false;
	}
	Car car = create_car(license, model, category);
	repo_add_car(repo, &car);
	return true;
}

bool service_update_license(Repo* repo, int id, const char* license) {
	return update_license(repo, id, license);
}

bool service_update_model(Repo* repo, int id, const char* model) {
	return update_model(repo, id, model);
}

bool service_update_category(Repo* repo, int id, const char* category) {
	if (validate_category(category) == false) {
		return false;
	}
	return update_category(repo, id, category);
}

bool service_update_is_rented(Repo* repo, int id, bool is_rented) {
	return update_is_rented(repo, id, is_rented);
}

Repo* service_filter_by_model(Repo* repo, const char* model) {
	Repo* filtered = create_repo();
	for (int i = 0; i < get_size(repo); i++) {
		if (strcmp(get_model(find_by_index(repo, i)), model) == 0) {
			repo_add_car(filtered, find_by_index(repo, i));
		}
	}
	return filtered;
}

Repo* service_filter_by_category(Repo* repo, const char* category) {
	Repo *filtered = create_repo();
	for (int i = 0; i < get_size(repo); i++) {
		if (strcmp(get_category(find_by_index(repo, i)), category) == 0) {
			repo_add_car(filtered, find_by_index(repo, i));
		}
	}
	return filtered;
}

bool sort_asc_by_category(Car* car1, Car* car2) {
	return strcmp(get_category(car1), get_category(car2)) < 0;
}

bool sort_desc_by_category(Car* car1, Car* car2) {
	return strcmp(get_category(car1), get_category(car2)) > 0;
}

bool sort_asc_by_model(Car* car1, Car* car2) {
	return strcmp(get_model(car1), get_model(car2)) < 0;
}

bool sort_desc_by_model(Car* car1, Car* car2) {
	return strcmp(get_model(car1), get_model(car2)) > 0;
}

Repo* service_sort(Repo* repo, bool(*cmp_sort)(Car* car1, Car* car2)) {
	Repo* sorted = create_repo();
	for (int i = 0; i < get_size(repo); i++) {
		repo_add_car(sorted, find_by_index(repo, i));
	}
	for (int i = 0; i < get_size(sorted) - 1; i++) {
		for (int j = i + 1; j < get_size(sorted); j++) {
			Car* car1 = find_by_index(sorted, i);
			Car* car2 = find_by_index(sorted, j);
			if (cmp_sort(car1, car2) == false) {
				Car aux = *car1;
				*car1 = *car2;
				*car2 = aux;
			}
		}
	}
	return sorted;
}