#pragma once
#include <string>
using std::string;

class Carte {
private:
	string title;
	string author;
	string genre;
	int year;
	int id;
public:
	Carte(const string& title, const string& author, const string& genre, int year) : title{ title }, author{ author }, genre{ genre }, year{ year } {}

	string get_title() const {
		return title;
	}
	string get_author() const {
		return author;
	}
	string get_genre() const {
		return genre;
	}
	int get_year() const {
		return year;
	}
	int get_id() const {
		return id;
	}

	void set_title(const string& title) {
		this->title = title;
	}
	void set_author(const string& author) {
		this->author = author;
	}
	void set_genre(const string& genre) {
		this->genre = genre;
	}
	void set_year(int year) {
		this->year = year;
	}
	void set_id(int id) {
		this->id = id;
	}
};