#include "domain.h"
#include "repo.h"
#include <cassert>

void test_get_title() {
	Carte c{ "A", "B", "C", 2000 };
	assert(c.get_title() == "A");

	Carte c2{ "D", "E", "F", 2000 };
	assert(c2.get_title() == "D");

	Carte c3{ "G", "H", "I", 2000 };
	assert(c3.get_title() == "G");
}

void test_get_author() {
	Carte c{ "A", "B", "C", 2000 };
	assert(c.get_author() == "B");
	Carte c2{ "D", "E", "F", 2000 };
	assert(c2.get_author() == "E");
	Carte c3{ "G", "H", "I", 2000 };
	assert(c3.get_author() == "H");
}

void test_get_genre() {
	Carte c{ "A", "B", "C", 2000 };
	assert(c.get_genre() == "C");
	Carte c2{ "D", "E", "F", 2000 };
	assert(c2.get_genre() == "F");
	Carte c3{ "G", "H", "I", 2000 };
	assert(c3.get_genre() == "I");
}

void test_get_year() {
	Carte c{ "A", "B", "C", 2000 };
	assert(c.get_year() == 2000);
	Carte c2{ "D", "E", "F", 2001 };
	assert(c2.get_year() == 2001);
	Carte c3{ "G", "H", "I", 2002 };
	assert(c3.get_year() == 2002);
}

void test_get_id() {
	Carte c{ "A", "B", "C", 2000 };
	assert(c.get_id() == 1);
	Carte c2{ "D", "E", "F", 2000 };
	assert(c2.get_id() == 2);
	Carte c3{ "G", "H", "I", 2000 };
	assert(c3.get_id() == 3);
}

void test_set_title() {
	Carte c{ "A", "B", "C", 2000 };
	c.set_title("D");
	assert(c.get_title() == "D");
	Carte c1{ "E", "F", "G", 2000 };
	c1.set_title("H");
	assert(c1.get_title() == "H");
}

void test_set_author() {
	Carte c{ "A", "B", "C", 2000 };
	c.set_author("D");
	assert(c.get_author() == "D");
	Carte c1{ "E", "F", "G", 2000 };
	c1.set_author("H");
	assert(c1.get_author() == "H");
}

void test_set_genre() {
	Carte c{ "A", "B", "C", 2000 };
	c.set_genre("D");
	assert(c.get_genre() == "D");
	Carte c1{ "E", "F", "G", 2000 };
	c1.set_genre("H");
	assert(c1.get_genre() == "H");
}

void test_set_year() {
	Carte c{ "A", "B", "C", 2000 };
	c.set_year(2001);
	assert(c.get_year() == 2001);
	Carte c1{ "E", "F", "G", 2000 };
	c1.set_year(2001);
	assert(c1.get_year() == 2001);
}

void test_set_id() {
	Carte c{ "A", "B", "C", 2000 };
	c.set_id(1);
	assert(c.get_id() == 1);
	Carte c1{ "E", "F", "G", 2000 };
	c1.set_id(2);
	assert(c1.get_id() == 2);
}

void test_repo_add() {
	Repo r;
	Carte c{ "A", "B", "C", 2000 };
	r.add(c);
	assert(r.get_all().size() == 1);
	Carte c1{ "D", "E", "F", 2000 };
	r.add(c1);
	assert(r.get_all().size() == 2);
	Carte c2{ "G", "H", "I", 2000 };
	r.add(c2);
	assert(r.get_all().size() == 3);
}

void test_repo_remove() {
	Repo r;
	Carte c{ "A", "B", "C", 2000 };
	r.add(c);
	Carte c1{ "D", "E", "F", 2000 };
	r.add(c1);
	Carte c2{ "G", "H", "I", 2000 };
	r.add(c2);
	r.remove(1);
	assert(r.get_all().size() == 2);
	r.remove(2);
	assert(r.get_all().size() == 1);
	r.remove(3);
	assert(r.get_all().size() == 0);
	try {
		r.remove(1);
		assert(false);
	}
	catch (RepoException& e) {
		assert(true);
	}
}

void tests() {
	test_get_title();
	test_get_author();
	test_get_genre();
	test_get_year();
	test_get_id();
	test_set_title();
	test_set_author();
	test_set_genre();
	test_set_year();
	test_set_id();
	test_repo_add();
	test_repo_remove();
}