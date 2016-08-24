#include "OverDraftAccount.h"

OverDraftAccount::OverDraftAccount(double _inMax) {
	this->_maxOverDraft = _inMax;
}
OverDraftAccount::~OverDraftAccount() {
	this->_maxOverDraft = 0.0;
}

double OverDraftAccount::getMax(void) {
	return this->_maxOverDraft;
}

void OverDraftAccount::setMax(double _inMax) {
	this->_maxOverDraft = _inMax;
}

bool OverDraftAccount::withdraw(double _inCome) {
	if ( abs(this->getBalance() - _inCome) > this->_maxOverDraft) {
		cout << "You cant because if so u will have lower than you maxLimit lets you" << endl;
		return false;
	}

	this->_balance -= _inCome;
	return true;
}