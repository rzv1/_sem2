#pragma once
#include "repo.h"
#include "domain.h"
#include <string>
using std::string;
class Service {
private:
	Repo repo;
public:
	Service(Repo repo) : repo{ repo } {}
	void add_book(const string title, const string author, const string genre, int year) {
		Carte c{ title, author, genre, year };
		repo.add(c);
	}
	void remove_book(int id) {
		repo.remove(id);
	}
	const vector<Carte> get_all() {
		return repo.get_all();
	}
};