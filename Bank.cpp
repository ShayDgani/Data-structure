#include "Bank.h"

Bank::Bank(string bankName) {
	this->_bank_name = bankName;
}

string Bank::getName() {
	return this->_bank_name;
}

void Bank::setName(string name) {
	this->_bank_name = name;
}

void Bank::addEmployee(Employee* em) {
	Employee* tempEm = this->_employees;
	while (tempEm != NULL)
		tempEm = tempEm->getNext();
	
	// please imagine that im doing what i did in addClient(...)
	// too tired to type it again just for safety in hw.. :D
	tempEm = em;
	this->employees_num++;
}

void Bank::addClient(Client* cl) {
	Client* tempClient = this->_clients;
	
	// Running through the list untill we reach the end (NULL)
	// when we reach null we enter the paramater.
	while (tempClient != NULL)
		tempClient = tempClient->getNext();

	// I know i could do tempClient = cl.
	// but its not so safe..
	tempClient->setAge(cl->getAge());
	tempClient->setBankAccount(cl->getBankAccount());
	tempClient->setClientType(cl->getClientType());
	tempClient->setId(cl->getId());
	tempClient->setLimitedAccount(cl->getLimitedAccount());
	tempClient->setName(cl->getName());
	tempClient->setNext(cl->getNext());
	tempClient->setOverDraftAccount(cl->getOverDraftAccount());
	this->clients_num++;

}

Employee* Bank::getEmployees() {
	return this->_employees;
}

void Bank::setEmployees(Employee* em) {
	this->_employees = em;
}

Client* Bank::getClients() {
	return this->_clients;
}

void Bank::setClients(Client* cl) {
	this->_clients = cl;
}
