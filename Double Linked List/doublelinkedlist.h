#include <iostream>
using namespace std;
#pragma once

struct node {
	int data;
	node* next;
	node* prev;
};


class dlinkedlist {

private:
	node* head;
	node*tail;
	int size;

public:
	dlinkedlist();
	dlinkedlist(int val);
	dlinkedlist(const dlinkedlist& rhs);
	~dlinkedlist();
	void printList()const;
	void pushBack(int data);
	void pushFront(int data);
	void popFront();
	void popBack();
	void insert(int index, int val);
	void deleteDuplicates(int val);
	int mtoLastElement(int val);
	int Size() const;
	friend ostream& operator<<(ostream& out, const dlinkedlist& rhs);
	dlinkedlist& operator=(const dlinkedlist& rhs);
	void reverseList();


};