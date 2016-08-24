#include "BSNode.h"
#include <iostream>
using namespace std;



BSNode::BSNode(string data) {
	this->_data = data;
	this->_left = NULL;
	this->_right = NULL;
	this->_Counter = 0;
}

BSNode::BSNode(const BSNode& other) {
	this->_data = other._data;
	this->_left = other._left;
	this->_right = other._right;
}

BSNode& BSNode::operator=(const BSNode& other) {
	this->_data = other._data;
	this->_left = other._left;
	this->_right = other._right;

	return *this;
}

/* Recursive function that call to d'tor if not NULL.*/
BSNode::~BSNode() {
	if (this->_left != NULL) {
		this->_left->~BSNode();
		this->_data = '\0';
		delete this->_left;
	}
	if (this->_right != NULL) {
		this->_right->~BSNode();
		this->_data = '\0';
		delete this->_right;
	}

}
/* Recursive function that insert a value to his right place.*/
void BSNode::insert(string value) {

	if (value < this->_data) {
		if (this->_left == NULL)
			this->_left = new BSNode(value);
		else
			this->_left->insert(value);
	
	}
	else if (value > this->_data) {
		if (this->_right == NULL)
			this->_right = new BSNode(value);
		else
			this->_right->insert(value);
	}
	else
		this->_Counter++;

}

/**/
bool BSNode::isLeaf() const {
	return !(this->_right && this->_left);
}

string BSNode::getData() const {
	return this->_data;
}

BSNode* BSNode::getLeft() const {
	return this->_left;
}

BSNode* BSNode::getRight() const {
	return this->_right;
}

bool BSNode::search(string val) const {
	if (val == this->_data) {
		return true;
	}
	else if (this->_data < val) {
		if (this->_right != NULL)
			return this->_right->search(val);
		else
			return false;
	
		}
	else if (this->_data > val) {
		if (this->_left != NULL)
			return this->_left->search(val);
		else
			return false;

	}
}

int BSNode::getHeight() const {
	int lHeight = this->_left->getHeight();
	int rHeight = this->_right->getHeight();
	if (rHeight > lHeight)
		return 1 + rHeight;
	else
		return 1 + lHeight;
}


void BSNode::printNodes() {
	if (this->_left != NULL) 
		this->_left->printNodes();

	cout << this->_data << endl;

	if (this->_right != NULL)
		this->_right->printNodes();
}