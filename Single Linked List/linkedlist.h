#include <iostream>

using namespace std;
#pragma once

struct node {
	double data;
	node* next;
};


class linkedlist {

private:
	node* head;
	int size;

public:
	linkedlist();
	linkedlist(double val);
	linkedlist(const linkedlist& rhs);
	~linkedlist();
	void printList()const;
	void pushBack(double data);
	void pushFront(double data);
	void popFront();
	void popBack();
	void insert(int index, double val);
	void deleteDuplicates(double val);
	double mtoLastElement(int M);
	int Size() const;
	friend ostream& operator<<(ostream& out, const linkedlist& rhs);
	linkedlist& operator=(const linkedlist& rhs);
	void reverseList();


};

