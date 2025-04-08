#include "../repo.h"
#include <iostream>

void Repo::add(Carte& book) {
	book.set_id(next_id++);
	books.push_back(book);
}

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

void Repo::update_title(int id, const string& title) {
	Carte& c = get_by_id(id);
	c.set_title(title);
}
void Repo::update_author(int id, const string& author) {
	Carte& c = get_by_id(id);
	c.validate_author(author);
	c.set_author(author);
}
void Repo::update_genre(int id, const string& genre) {
	Carte& c = get_by_id(id);
	c.validate_genre(genre);
	c.set_genre(genre);
}
void Repo::update_year(int id, const int year) {
	Carte& c = get_by_id(id);
	c.set_year(year);
}

Carte& Repo::get_by_id(int id) {
	for (size_t i = 0; i < books.get_size(); i++) {
		if (books[i].get_id() == id)
			return books[i];
	}
	throw RepoException("Id-ul nu exista!");
}