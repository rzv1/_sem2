#include "masina.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Car create_car(const char* license, const char* model, const char* category) {
	Car car;
	car.ID = 0;
	car.is_rented = false;
	car.license = malloc(strlen(license) + (size_t)1);
	if (car.license == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	else {
		memset(car.license, 0, strlen(license) + (size_t)1);
		strcpy(car.license, license);
	}
	car.model = malloc(strlen(model) + (size_t)1);
	if (car.model == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	else {
		memset(car.model, 0, strlen(model) + (size_t)1);
		strcpy(car.model, model);
	}
	car.category = malloc(strlen(category) + (size_t)1);
	if (car.category == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	else {
		memset(car.category, 0, strlen(category) + (size_t)1);
		strcpy(car.category, category);
	}
	return car;
}

//bool validate_car(Car* car) {
//	if (car == NULL) {
//		return false;
//	}
//	if (strlen(car->license) != 8) {
//		return false;
//	}
//	if (strlen(car->model) == 0) {
//		return false;
//	}
//	if (strlen(car->category) == 0) {
//		return false;
//	}
//	return true;
//}

void destroy_car(Car* car) {
	free(car->license);
	free(car->model);
	free(car->category);
}

int get_id(Car* car) {
	return car->ID;
}

const char* get_license(Car* car) {
	return car->license;
}

const char* get_model(Car* car) {
	return car->model;
}

const char* get_category(Car* car) {
	return car->category;
}

bool get_is_rented(Car* car) {
	return car->is_rented;
}

void set_license(Car* car, const char* license) {
	free(car->license);
	car->license = malloc(strlen(license) + (size_t)1);
	if (car->license == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	else {
		memset(car->license, 0, strlen(license) + (size_t)1);
		strcpy(car->license, license);
	}
}

void set_model(Car* car, const char* model) {
	free(car->model);
	car->model = malloc(strlen(model) + (size_t)1);
	if (car->model == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	else {
		memset(car->model, 0, strlen(model) + (size_t)1);
		strcpy(car->model, model);
	}
}

void set_category(Car* car, const char* category) {
	free(car->category);
	car->category = malloc(strlen(category) + (size_t)1);
	if (car->category == NULL) {
		printf("malloc error\n");
		exit(EXIT_FAILURE);
	}
	else {
		memset(car->category, 0, strlen(category) + (size_t)1);
		strcpy(car->category, category);
	}
	strcpy(car->category, category);
}

void set_is_rented(Car* car, bool is_rented) {
	car->is_rented = is_rented;
}