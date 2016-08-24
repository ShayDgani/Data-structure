#include "MyFile.h"

#include <iostream>
#include <fstream>
using namespace std;

void myFile::printFile(string filename) {
	string temp;
	ifstream myFile(filename);
	if (myFile.is_open()) {
		while (getline(myFile, temp)) {
			cout << temp << endl;
		}
	}
	else
		cout << "[-] Can not open " << filename << ".txt ." << endl;

	myFile.close();
}

void myFile::printWords(string inFile, string outFile) {
	string temp;
	ifstream inputFile(inFile);
	ofstream outputFile(outFile);
	if (inputFile.is_open() && outputFile.is_open()) {
		while (inputFile >> temp)
			outputFile << temp << endl;
	}
	else
		cout << "[-] Can not open " << inFile << " or " << outFile << endl;
	
	inputFile.close();
	outputFile.close();
}