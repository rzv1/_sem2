#pragma once
#include "VectorDinamic.h"

class IteratorVectorDinamic {

	friend class VectorDinamic;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container

	IteratorVectorDinamic(const VectorDinamic& vec) : v{ vec } {
		prim();
	};

	//contine o referinta catre containerul pe care il itereaza
	const VectorDinamic& v;

	size_t cursor;

public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid() const;

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element() const;

};