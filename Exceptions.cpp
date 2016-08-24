#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "Exceptions.h"

using namespace std;

class myException : public exception
{
public:
	const char* myException::what() const {
		return "myException's what function.";
	}
};

bool isOdd(int x) throw(int) {
	/*
		[!] If x % 2 != 0 that means that its odd number, if so returns true.
		[!] else - which means its even number.. throw x but we still need to return false afterward
		[!] because according to 'C11' if function should return something,
						every part of the function should return ! - that why i putted the return false at the end.
	*/
	if (x % 2 != 0)
		return true;
	else {
		throw x;
	}
	return false;


}

bool isLetter(char ch) throw(char) {
	/*
		[!] If ch ascii value is between a ~ z OR A ~ Z that means that its a letter, if so returns true.
		[!] else - which means its not a  letter.. throw ch but we still need to return false afterward
		[!] because according to 'C11' if function should return something,
					every part of the function should return ! - that why i putted the return false at the end.
	*/
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	else
		throw ch;
	return false;
}
bool isWholeNumber(double x) throw(double) {
	/*
		[!] for example x = 4.3 : 
			4.3 - 4 = 0.3 .. so if its not intergar number (x-(int)x) != 0..
	*/
	double Leftover;
	Leftover = x - (int)x;
	if (Leftover == 0)
		return true;
	else {
		throw x;
	}
	return false;
}
bool isExist(string filename) throw(string) {
	ifstream f(filename);
	if (f.good()) {
		f.close();
		return true;
	}
	else
		throw filename;

	return false;
}

bool isOk(bool flag)throw(myException) {
	myException ex;
	if (flag)
		return true;

	throw ex;
	return false;
}
void main() {
	int IntergarValue = 0;
	char CharacterValue = 0;
	double DoubleValue = 0.0;
	string StringValue = "";
	bool BooleanValue = false;

	cout << "Enter integar, char , double, string , bool (by this order) " << endl;
	cin >> IntergarValue >> CharacterValue >> DoubleValue >> StringValue >> BooleanValue;
	
	try
	{
		isOdd(IntergarValue);
		isLetter(CharacterValue);
		isWholeNumber(DoubleValue);
		isExist(StringValue);
		isOk(BooleanValue);
	}
	catch (int ex)
	{
		cerr << "int Exception " <<  ex << endl;;
	}
	catch (char ex) {
		cout << "char Exception " << ex << endl;
	}
	catch (double ex) {
		cerr << " double Exception " << ex << endl;
	}
	catch (string ex) {
		cerr << "string Exception " << ex << endl;
	}
	catch (myException ex) {
		cerr << ex.what() << endl;
	}
}