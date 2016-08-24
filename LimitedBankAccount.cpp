#include "LimitedBankAccount.h"

LimitedBankAccount::LimitedBankAccount(double _inCome) {
	this->_limit = _inCome;
}

LimitedBankAccount::~LimitedBankAccount() {
	this->_limit = 0.0;
}

void LimitedBankAccount::setLimit(double _inLimit) {
	this->_limit = _inLimit;
}

double LimitedBankAccount::getLimit() {
	return this->_limit;
}

bool LimitedBankAccount::withdraw(double _inDraw) {
	if (this->_limit < _inDraw) {
		cout << "this draw is over the limit.." << endl;
		return false;

	}
		

	if (this->getBalance() - _inDraw < 0) {
		cout << "You will be in minus.." << endl;
		return false;
	}
		
	cout << "Successfully drawed " << _inDraw << endl;
	this->_balance -= _inDraw;
	return true;
}