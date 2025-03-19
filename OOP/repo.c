#include <stdio.h>  
#include <stdlib.h>  
#include "entities.c"

/*repository care permite gestionarea unor masini cu operatii CRUD*/
struct Repository {
   struct Car* cars;
   int size;
   int capacity;
};

/*Functie care creeaza un repository de masini*/
struct Repository create_repository(int capacity);

struct Repository create_repository(int capacity)
{
   struct Repository repo;
   repo.cars = (struct Car*)malloc(capacity * sizeof(struct Car));
   repo.size = 0;
   repo.capacity = capacity;
   return repo;
}

/*Functie care adauga o masina in repository*/
void add_car(struct Repository* repo, struct Car car);

void add_car(struct Repository* repo, struct Car car)
{
   if (repo->size == repo->capacity) {
       printf("Repository is full!\n");
       return;
   }
   repo->cars[repo->size++] = car;
}

/*Functie care returneaza toate masinile din repository*/
struct Car* get_all_cars(struct Repository* repo);

struct Car* get_all_cars(struct Repository* repo)
{
	return repo->cars;
}

/*Functie care returneaza numarul de masini din repository*/
int get_size(struct Repository* repo);

int get_size(struct Repository* repo)
{
	return repo->size;
}

