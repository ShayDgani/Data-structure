#include "Client.h"

Client::Client(int id[9], string name, int age, string client_type,
	BankAccount* regular, LimitedBankAccount* limited, OverDraftAccount* over) {
	this->setId(id);
	this->setName(name);
	this->setAge(age);
	this->setClientType(client_type);
	this->_bankAccount = regular;
	this->_limitedAccount = limited;
	this->_overDraftAccount = over;
}

string Client::getClientType() {
	return this->_client_type;
}

BankAccount* Client::getBankAccount() {
	return this->_bankAccount;
}

LimitedBankAccount* Client::getLimitedAccount() {
	return this->_limitedAccount;
}

OverDraftAccount* Client::getOverDraftAccount() {
	return this->_overDraftAccount;
}

void Client::setBankAccount(BankAccount* Ba) {
	this->_bankAccount = Ba;
}

void Client::setLimitedAccount(LimitedBankAccount* Lbc) {
	this->_limitedAccount = Lbc;
}

void Client::setOverDraftAccount(OverDraftAccount* Oda) {
	this->_overDraftAccount = Oda;
}

void Client::setClientType(string type) {
	this->_client_type = type;
}

Client* Client::getNext() {
	return this->_next;
}

void Client::setNext(Client* cl) {
	Client* tempCl = this;
	while (tempCl != NULL){
		tempCl = tempCl->_next;
	}
	tempCl = cl;
}