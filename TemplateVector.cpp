#include <iostream>
#include <string>
using namespace std;

template <class T> class Vector {
private:
	T *_data;
	size_t _size;
	void reset();
	void allocate(int inSize);
	void copy(const T *v);
public:
	// overloading C'tors.
	Vector(int size = 0, T initVal = T());
	Vector(const Vector& inVector);
	// d'tor
	~Vector();
	void set(T val);
	// Operators overloading.
	Vector &operator=(const Vector &v);
	T& operator[](int i);

	// input & output functions
	void print();

	
};
template<class T> void Vector<T>::print() {
	for (size_t i = 0; i < this->_size; i++)
		cout << this->_data[i] << " ";
	cout << endl;
}
template <class T> T& Vector<T>::operator[](int i) {
	return this->_data[i];
}
template <class T> Vector<T>& Vector<T>::operator=(const Vector<T> &v) {
	if (this != &v) {
		delete[] this->_data;
		allocate(v._size);
		copy(v._data);
	}
	return *this;
}
template <class T> Vector<T>::~Vector() {
	delete[] this->_data;
	this->reset();
}
template <class T> void Vector<T>::set(T val) {
	for (size_t i = 0; i < this->_size; i++)
		this->_data[i] = val;
}
template <class T> Vector<T>::Vector(const Vector<T>& inVector) {
	if (inVector._size != 0) {
		this->allocate(inVector._size);
		this->copy(inVector._data);
	}
	else
		this->reset();
}
template <class T> Vector<T>::Vector(int size = 0, T initVal = T()) {
	if (size != 0) {
		this->allocate(size);
		this->set(initVal);
	}
}
template <class T> void Vector<T>::reset() {
	this->_size = 0;
	this->_data = 0;
}
template <class T> void Vector<T>::allocate(int inSize) {
	this->_size = inSize;
	this->_data = new T[this->_size];
}
template <class T> void Vector<T>::copy(const T *inV) {
	for (size_t i = 0; i < this->_size; i++)
		this->_data[i] = inV[i];
}


void main() {

}