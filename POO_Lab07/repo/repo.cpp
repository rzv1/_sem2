#include "../repo.h"
#include <iostream>

/*
Functie care adauga o carte validata in repo
*/
void Repo::add(Carte& book) {
	book.set_id(next_id++);
	books.push_back(book);
}

/*
Functia care sterge cartea cu id-ul dat din repo
throw: Cartea cu ID nu exista in repo
*/
void Repo::remove(int id) {
	bool gasit = false;
	if (!books.empty())
	for (size_t i = 0; i < books.get_size() && !gasit; i++) {
		if (books[i].get_id() == id) {
			books.remove(i);
			gasit = true;
		}
	}
	if (!gasit)
		throw RepoException("Cartea cu id-ul dat nu exista!");
}

/*
Functia actualizeaza titlul unei carti
*/
void Repo::update_title(int id, const string& title) {
	Carte& c = get_by_id(id);
	c.set_title(title);
}

/*
Functia actualizeaza autorul unei carti\
*/
void Repo::update_author(int id, const string& author) {
	Carte& c = get_by_id(id);
	c.validate_author(author);
	c.set_author(author);
}

/*
Functia actualizeaza gen-ul unei carti
*/
void Repo::update_genre(int id, const string& genre) {
	Carte& c = get_by_id(id);
	c.validate_genre(genre);
	c.set_genre(genre);
}

/*
Functia actualizeaza anul unei carti
*/
void Repo::update_year(int id, const int year) {
	Carte& c = get_by_id(id);
	c.set_year(year);
}

/*
Functia returneaza cartea cu id-ul dat
throw: Cartea cu ID nu se afla in repo
*/
Carte& Repo::get_by_id(int id) {
	for (size_t i = 0; i < books.get_size(); i++) {
		if (books[i].get_id() == id)
			return books[i];
	}
	throw RepoException("Id-ul nu exista!");
}