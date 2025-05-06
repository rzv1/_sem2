#pragma once
#include <initializer_list>
using std::initializer_list;
template <typename T>

class IteratorVectorDinamic;

template <typename T>
class VectorDinamic {
private:
	size_t sz;
	size_t capacity;
	T* elements;
	void resize() {
		capacity *= 2;
		T* new_elements = new T[capacity];
		for (size_t i = 0; i < sz; i++) {
			new_elements[i] = elements[i];
		}
		delete[] elements;
		elements = new_elements;
	}
public:
	VectorDinamic() : sz(0), capacity(2) {
		elements = new T[capacity];
	}
	//Constructor care initializiaza vectorul cu o lista de elemente
	VectorDinamic(initializer_list<T> initList) {
		sz = initList.sz();
		capacity = sz * 2;
		elements = new T[capacity];
		int i = 0;
		for (const auto& element : initList) {
			elements[i++] = element;
		}
	}
	VectorDinamic(const VectorDinamic& other) : sz(other.sz), capacity(other.capacity) {
		elements = new T[capacity];
		if (other.sz <= capacity)
			for (size_t i = 0; i < other.sz; i++) {
				elements[i] = other.elements[i];
			}
	}
	VectorDinamic& operator=(const VectorDinamic& other) {
		if (this != &other) {
			delete[] elements;
			sz = other.sz;
			capacity = other.capacity;
			elements = new T[capacity];
			for (int i = 0; i < sz; i++) {
				elements[i] = other.elements[i];
			}
		}
		return *this;
	}
	~VectorDinamic() {
		delete[] elements;
	}
	void add(const T& element) {
		if (sz == capacity) {
			resize();
		}
		elements[sz++] = element;
	}
	T& operator[](size_t index) noexcept {
		return elements[index];
	}
	T& operator[](size_t index) const noexcept {
		return elements[index];
	}
	size_t size() const noexcept {
		return this->sz;
	}
	bool empty() const noexcept {
		return sz == 0;
	}
	void remove(size_t index) {
		for (size_t i = index; i < sz - 1; i++) {
			elements[i] = elements[i + 1];
		}
		sz--;
	}
	T get(int index) const {
		return elements[index];
	}
	friend class IteratorVectorDinamic<T>;
	IteratorVectorDinamic<T> begin() {
		return IteratorVectorDinamic<T>(*this);
	}
	IteratorVectorDinamic<T> end() {
		return IteratorVectorDinamic<T>(*this, sz);
	}
	IteratorVectorDinamic<T> begin() const {
		return IteratorVectorDinamic<T>(*this);
	}
	IteratorVectorDinamic<T> end() const {
		return IteratorVectorDinamic<T>(*this, sz);
	}
};

template <typename T>

class IteratorVectorDinamic {
private:
	const VectorDinamic<T>& v;
	size_t pos;
public:
	IteratorVectorDinamic(const VectorDinamic<T>& v) : v{ v }, pos{ 0 } {}
	IteratorVectorDinamic(const VectorDinamic<T>& v, size_t pos) : v{ v }, pos{ pos } {}
	bool valid() const {
		return pos < v.get_size();
	}
	T& element() const {
		return v[pos];
	}
	void urmator() {
		pos++;
	}
	IteratorVectorDinamic<T>& operator++() {
		urmator();
		return *this;
	}
	T& operator*() const {
		return element();
	}
	bool operator==(const IteratorVectorDinamic<T>& ot) const {
		return pos == ot.pos;
	}
	bool operator!=(const IteratorVectorDinamic<T>& ot) const {
		return !(*this == ot);
	}
};