#include "repo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Repo* create_repo() {
	Repo* repo = malloc(sizeof(Repo));
	if (repo != NULL) {
		repo->size = 0;
		repo->next_id = 1;
	}
	return repo;
}

void repo_add_car(Repo* repo, Car* car) {
	car->ID = repo->next_id++;
	repo->car[repo->size++] = *car;
}

void destroy_repo(Repo* repo) {
	for (int i = 0; i < get_size(repo); i++) {
		destroy_car(&repo->car[i]);
	}
	free(repo);
}

int get_size(Repo* repo) {
	return repo->size;
}

Car* find_by_id(Repo* repo, int id) {
	for (int i = 0; i < get_size(repo); i++) {
		if (repo->car[i].ID == id) {
			return &repo->car[i];
		}
	}
	return NULL;
}

Car* find_by_index(Repo* repo, int index) {
	if (index < 0 || index >= get_size(repo)) {
		return NULL;
	}
	return &repo->car[index];
}

bool update_license(Repo* repo, int id, const char* license) {
	Car* car = find_by_id(repo, id);
	if (car == NULL) {
		return false;
	}
	set_license(car, license);
	return true;
}

bool update_model(Repo* repo, int id, const char* model) {
	Car* car = find_by_id(repo, id);
	if (car == NULL) {
		return false;
	}
	set_model(car, model);
	return true;
}

bool update_category(Repo* repo, int id, const char* category) {
	Car* car = find_by_id(repo, id);
	if (car == NULL) {
		return false;
	}
	set_category(car, category);
	return true;
}

bool update_is_rented(Repo* repo, int id, bool is_rented) {
	Car* car = find_by_id(repo, id);
	if (car == NULL) {
		return false;
	}
	set_is_rented(car, is_rented);
	return true;
}