#include <iostream>
using namespace std;

typedef int TElem;
class Stiva {
private:
	TElem* elems;
	int size;
	int capacity;
public:
	Stiva();

	void adauga(TElem e);

	TElem element() const;
};



int main() {

}