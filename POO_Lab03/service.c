#include "service.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool service_add_car(Repo* repo, const char* license, const char* model, const char* category) {
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
	return update_category(repo, id, category);
}

bool service_update_is_rented(Repo* repo, int id, bool is_rented) {
	return update_is_rented(repo, id, is_rented);
}

Repo* service_filter_by_model(Repo* repo, const char* model) {
	Repo* filtered = create_repo();
	for (int i = 0; i < get_size(repo); i++) {
		if (strcmp(get_model(&repo->car[i]), model) == 0) {
			repo_add_car(filtered, &repo->car[i]);
		}
	}
	return filtered;
}

Repo* service_filter_by_category(Repo* repo, const char* category) {
	Repo* filtered = create_repo();
	for (int i = 0; i < get_size(repo); i++) {
		if (strcmp(get_category(&repo->car[i]), category) == 0) {
			repo_add_car(filtered, &repo->car[i]);
		}
	}
	return filtered;
}

Repo* service_sort_by_model(Repo* repo) {
	Repo* sorted = create_repo();
	for (int i = 0; i < get_size(repo); i++) {
		repo_add_car(sorted, &repo->car[i]);
	}
	for (int i = 0; i < get_size(sorted) - 1; i++) {
		for (int j = i + 1; j < get_size(sorted); j++) {
			if (strcmp(get_model(&sorted->car[i]), get_model(&sorted->car[j])) > 0) {
				Car aux = sorted->car[i];
				sorted->car[i] = sorted->car[j];
				sorted->car[j] = aux;
			}
		}
	}
	return sorted;
}