#include "Person.h"

Person::Person(int _id[9], string name, int age) {
	this->_age = age;
	this->setId(_id);
	
	this->_name = name;
}

int* Person::getId() {
	return this->_id;
}

string Person::getName() {
	return this->_name;
}

int Person::getAge() {
	return this->_age;
}

void Person::setId(int id[9]) {
	for (size_t i = 0; i < 9; i++)
		this->_id[i] = id[i];
}

void Person::setName(string name) {
	this->_name = name;
}
void Person::setAge(int age) {
	this->_age = age;
}