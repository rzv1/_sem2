#include <iostream>

typedef int TElem;

class Nod {
public:
    TElem valoare;
    Nod* urm;
    Nod* prec;

    Nod(int v, Nod* u = nullptr, Nod* p = nullptr)
        : valoare(v), urm(u), prec(p) {
    }
};

class DoubleLinkedList {
private:
    Nod* cap;   // pointer la primul nod
    Nod* coada; // pointer la ultimul nod
    int dim;    // dimensiunea listei

public:
    DoubleLinkedList()
        : cap(nullptr), coada(nullptr), dim(0) {
    }

    ~DoubleLinkedList() {
        Nod* curent = cap;
        while (curent) {
            Nod* temp = curent;
            curent = curent->urm;
            delete temp;
        }
    }

    bool eVida() const {
        return (dim == 0);
    }

    int dimensiune() const {
        return dim;
    }

    void inserareInceput(TElem valoare) {
        Nod* nou = new Nod(valoare, cap, nullptr);
        if (cap == nullptr) {
            cap = nou;
            coada = nou;
        }
        else {
            cap->prec = nou;
            cap = nou;
        }
        dim++;
    }

    void inserareSfarsit(TElem valoare) {
        if (coada == nullptr) {
            inserareInceput(valoare);
            return;
        }
        Nod* nou = new Nod(valoare, nullptr, coada);
        coada->urm = nou;
        coada = nou;
        dim++;
    }

    Nod* cauta(TElem valoare) const {
        Nod* curent = cap;
        while (curent != nullptr) {
            if (curent->valoare == valoare)
                return curent;
            curent = curent->urm;
        }
        return nullptr;
    }

    void stergeNod(Nod* deSters) {
        if (deSters == nullptr)
            return;
        if (deSters == cap && deSters == coada) {
            cap = nullptr;
            coada = nullptr;
        }
        else if (deSters == cap) {
            cap = cap->urm;
            cap->prec = nullptr;
        }
        else if (deSters == coada) {
            coada = coada->prec;
            coada->urm = nullptr;
        }
        else {
            deSters->prec->urm = deSters->urm;
            deSters->urm->prec = deSters->prec;
        }
        delete deSters;
        dim--;
    }

    bool stergeValoare(TElem valoare) {
        Nod* gasit = cauta(valoare);
        if (gasit) {
            stergeNod(gasit);
            return true;
        }
        return false;
    }

    Nod* inceput() const {
        return cap;
    }
};
