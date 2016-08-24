#include <stdio.h>
#include "Bank.h"
#include "BankAccount.h"
#include "Client.h"
#include <string>

using namespace std;

void checkBankAccount() {
	BankAccount *bank = new BankAccount();
	cout << bank->getBalance() << endl;
	bank->deposit(5);
	cout << bank->getBalance() << endl;
	bank->withdraw(5);
	cout << bank->getBalance() << endl;
	bank->withdraw(100);
	cout << bank->getBalance() << endl;
}
void checkLimitedBank() {
	LimitedBankAccount *Lbank = new LimitedBankAccount(1200.0);
	cout << Lbank->getBalance() << endl;
	cout << Lbank->getLimit() << endl;
	Lbank->deposit(500);
	cout << Lbank->getBalance() << endl;
	Lbank->withdraw(1300);
	cout << Lbank->getBalance() << endl;
}
void checkOverDraftAccount() {
	OverDraftAccount *oBank = new OverDraftAccount(500.0);
	cout << oBank->getMax() << endl;
	cout << oBank->getBalance() << endl;
	oBank->deposit(500);
	cout << oBank->getBalance() << endl;
	oBank->withdraw(800);
	cout << oBank->getBalance() << endl;
	oBank->withdraw(400);
	cout << oBank->getBalance() << endl;
}
void checkPerson() {
	Client *Cl;
	BankAccount *bank = new BankAccount();
	LimitedBankAccount *Lbank = new LimitedBankAccount(1200.0);
	OverDraftAccount *oBank = new OverDraftAccount(500.0);
	int id[9];
	string _name;
	int age;
	string client_Type;
	cout << "Enter ID(/enter for each num), Name, Age, Client_Type" << endl;
	for (size_t i = 0; i < 9; i++)
		cin >> id[i];

	cin >> _name >> age >> client_Type;
	Cl = new Client(id, _name, age, client_Type,bank,Lbank,oBank);
	cout << Cl->getAge();
	Cl->setAge(15);
	cout <<Cl->getAge();
	Cl->setNext(NULL);
	cout << Cl->getNext() << endl;
	}
void main() {
	//checkPerson();
	//checkBankAccount();
	//checkLimitedBank();
	checkOverDraftAccount();
}