#include "IteratorVectorDinamic.h"
#include "VectorDinamic.h"
#include <cstddef>

void IteratorVectorDinamic::prim() {
	cursor = 0;
}

void IteratorVectorDinamic::urmator() {
	if (valid())
		cursor++;
}

bool IteratorVectorDinamic::valid() const{
	if (cursor < 0 || cursor >= v.lg)
		return false;
	return true;
}

TElem IteratorVectorDinamic::element() const{
	if(valid())
		return v.elems[cursor];
	return NULL;
}