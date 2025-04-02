#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "domain.h"

using std::vector;
using std::string;

class RepoException {
private:
	string message;
public:
	RepoException(string message) : message{ message } {}
	string get_message() {
		return message;
	}
};

class Repo {
private:
	vector<Carte> carti;
	int next_id = 1;
public:
	Repo() = default;
	void add(Carte carte) {
		carte.set_id(next_id++);
		carti.push_back(carte);
	}
	void remove(int id) {
		auto it = std::find_if(carti.begin(), carti.end(), [id](const Carte& c) {return c.get_id() == id; });
		if (it == carti.end()) {
			throw RepoException("Cartea nu exista!");
		}
		else
		carti.erase(it);
	}
	const vector<Carte> get_all() {
		return carti;
	}
};