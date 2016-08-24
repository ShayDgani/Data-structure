#include "Employee.h"

Employee::Employee(int _id[9], string _name,
	int _age, string position, int salary, int seniority){
	this->setId(_id);
	this->setName(_name);
	this->setAge(_age);
	this->setPosition(position);
	this->setSalary(salary);
	this->setSeniority(seniority);
}

string Employee::getPosition() {
	return this->_position;
}

int Employee::getSalary() {
	return this->_salary;
}

int Employee::getSeniority() {
	return this->_seniority;
}

void Employee::setPosition(string position) {
	this->_position = position;
}

void Employee::setSalary(int salary) {
	this->_salary = salary;
}

void Employee::setSeniority(int seniority) {
	this->_seniority = seniority;
}

Employee* Employee::getNext() {
	return this->_next;
}

void Employee::setNext(Employee* _inNext) {
	this->_next = _inNext;
}