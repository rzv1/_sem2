#include "VectorDinamic.h"
#include "IteratorVectorDinamic.h"
#include <exception>

using namespace std;

VectorDinamic::VectorDinamic(int cp) {
	this->cp = cp;
	this->lg = 0;
	this->elems = new TElem[cp];
}

int VectorDinamic::dim() const{
	return lg;
}

void VectorDinamic::redim() {
	cp *= 2;
	TElem* new_elems = new int[cp];

	for (int i = 0; i < lg; i++)
		new_elems[i] = elems[i];

	delete[] elems;
	elems = new_elems;
}

TElem VectorDinamic::element(int i) const{
	if (i < 0 || i > lg)
		throw exception("Index invalid!");
	return elems[i];
}

void VectorDinamic::adauga(int i, TElem e) {
	if (i < 0 || i > lg)
		throw exception("Index invalid!");
	if (cp == lg)
		redim();
	for (int k = lg++; k > i; k--)
		elems[k] = elems[k - 1];
	elems[i] = e;
}

void VectorDinamic::adaugaSfarsit(TElem e) {
	if (cp == lg)
		redim();
	elems[lg++] = e;
}

TElem VectorDinamic::sterge(int i) {
	if (i < 0 || i > lg)
		throw exception("Index invalid!");
	else if (lg == 0)
		throw exception("Vector gol!");
	TElem e = element(i);
	for (int k = i; k < lg - 1; k++)
		elems[k] = elems[k + 1];
	lg = lg - 1;
	return e;
}

TElem VectorDinamic::modifica(int i, TElem e) {
	if (i < 0 || i > lg)
		throw exception("Index invalid!");
	else if (lg == 0)
		throw exception("Vector gol!");
	TElem aux = sterge(i);
	adauga(i, e);
	return aux;
}

IteratorVectorDinamic VectorDinamic::iterator() {
	return IteratorVectorDinamic(*this);
}

VectorDinamic::~VectorDinamic() {
	delete[] elems;
}