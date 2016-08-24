#include "BankAccount.h"

BankAccount::BankAccount() {
	this->_balance = 0.0;
	this->_account_type = "Regular";
}

BankAccount::~BankAccount() {
	this->_balance = 0.0;
	this->_account_type = "";
}

string BankAccount::getAccountType(void) {
	return this->_account_type;
}

double BankAccount::getBalance(void) {
	return this->_balance;
}

bool BankAccount::withdraw(double Cash) {
	if ((this->_balance - Cash) < 0) {
		cout << "cant withdraw... you will be in Minus" << endl;
		return false;
	}

	this->_balance -= Cash;
	return true;
}

void BankAccount::deposit(double Cash) {
	cout << "You have depois t" << Cash << endl;
	this->_balance += Cash;
}