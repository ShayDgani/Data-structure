void BSNode::printNodes() {
	if (this->_left != NULL) 
		this->_left->printNodes();

	cout << this->_data << endl;

	if (this->_right != NULL)
		this->_right->printNodes();
}