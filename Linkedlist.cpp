#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Node
{
    friend class LinkedList;
public:
    Node();
    Node(int val);
    Node(int val, Node* next);

    void setValue(int inVal) {
        this->_value = inVal;
    }
    void setNext(Node* _inNext) {
        this->_pNext = _inNext;
    }
    int getValue() {
        return _value;
    }
    Node* getNext() {
        return this->_pNext;
    }
private:
    int _value;
    Node *_pNext;
};

Node::Node() :_pNext(NULL), _value(NULL) {}
Node::Node(int val) : _pNext(NULL), _value(val) {}
Node::Node(int val, Node *next) : _pNext(next), _value(val) {}


class LinkedList {
private:
    Node* _pHead;
    Node* _pTail;
public:
    LinkedList();
    LinkedList(int inVal);
    ~LinkedList() {
        Node* p;
        Node* pCurrent = this->_pHead;
        while (pCurrent != NULL) {
            p = pCurrent->_pNext;
            delete pCurrent;
            pCurrent = p;
        }

        this->_pHead = NULL;
    }
    void printList();
    void AddNode(int inVal);
    void DeleteTail();
    void headInsert(int inVal);
    bool searchKey(int inKey);
};
LinkedList::LinkedList() :_pHead(NULL), _pTail(NULL) {}
LinkedList::LinkedList(int inVal) {
    this->_pHead = new Node(inVal);
    this->_pTail = this->_pHead;
}
void LinkedList::AddNode(int inVal) {
    Node* p = this->_pHead;
    if (this->_pHead == NULL) {
        this->_pTail = this->_pHead = new Node(inVal);
    }
    else {
        this->_pTail->_pNext = new Node(inVal);
        this->_pTail = this->_pTail->_pNext;
    }

}
void LinkedList::headInsert(int inVal) {
    if (this->_pHead == NULL) {
        this->_pTail = this->_pHead = new Node(inVal);
        return;
    }

    Node *p = new Node(inVal);
    p->_pNext = this->_pHead;
    this->_pHead = p;
}
void LinkedList::printList() {
    Node *p = this->_pHead;
    if (this->_pHead == NULL) {
        cout << "The list is empty.." << endl;
        return;
    }
    cout << "LinkedList: ";
    while (p != NULL) {
        cout << p->getValue() <<" ";
        p = p->getNext();
    }

    cout << endl;
}
bool LinkedList::searchKey(int inKey) {
    Node* p = this->_pHead;
    if (this->_pHead == NULL) {
        cout << "The list is empty.." << endl;
        return -1;
    }

    while (p != NULL) {
        if (p->_value == inKey)
            return true;
        p = p->_pNext;
    }


    return false;
}
void LinkedList::DeleteTail() {
    if (this->_pHead == NULL) {
        cout << "The list is empty.." << endl;
        return;
    }
    Node *p = this->_pHead;
    while (p->_pNext->_pNext != NULL)
        p = p->_pNext;

    p->_pNext = NULL;
    this->_pTail = p;
}
int main()
{
    /* Create an empty list */
    LinkedList *list1 = new LinkedList();
    cout << "[+] Created an empty list named list1." << endl;
    /* output the result */
    cout << "list1:" << endl;
    list1->printList();
    list1->AddNode(5);
    list1->printList();
    list1->~LinkedList();
    list1->printList();
    /* Create a list with only one node */
    LinkedList list2(10);
    cout << "[+] Created a list named list2 with only one node." << endl;
    list2.AddNode(5);
    list2.AddNode(12);
    /* output the result */
    cout << "list2:" << endl;
    list2.printList();
    list2.DeleteTail();
    list2.printList();
    list2.AddNode(15);
    list2.printList();
    list2.headInsert(-3);
    list2.printList();
    list2.AddNode(99);
    if (list2.searchKey(99))
        cout << "15 is found." << endl;
    list2.printList();
    list2.DeleteTail();
    if (list2.searchKey(99))
        cout << "15 is found." << endl;
    list2.printList();
    return 0;
}

