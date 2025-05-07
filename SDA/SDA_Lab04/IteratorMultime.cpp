#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& m) : multime(m) {
	curent = multime.elemente.inceput();
}

// Complexitate O(1) - muta cursorul pe primul element
void IteratorMultime::prim() {
	curent = multime.elemente.inceput();
}

// Complexitate O(1) - muta cursorul pe elementul anterior
void IteratorMultime::anterior() {
	if (!valid()) {
		throw std::exception();
	}
	if (curent == multime.elemente.inceput()) {
		curent = -1;
		return;
	}
	int prev = multime.elemente.inceput();
	while (prev != -1 && multime.elemente.at(prev).next != curent) {
		prev = multime.elemente.at(prev).next;
	}
}

// Complexitate O(1) - muta cursorul pe elementul urmator
void IteratorMultime::urmator() {
	if (!valid()) {
		throw std::exception();
	}
	curent = multime.elemente.at(curent).next;
}

// Complexitate O(1) - returneaza elementul curent
TElem IteratorMultime::element() const {
	if (!valid()) {
		throw std::exception();
	}
	return multime.elemente.at(curent).valoare;
}

// Complexitate O(1) - verifica daca iteratorul e valid
bool IteratorMultime::valid() const {
	return (curent != -1);
}
