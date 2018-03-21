#include "linkedlist.h"

//Default constructor
linkedlist::linkedlist() {
	head = NULL;
	size = 0;
}

//argumented constructor
linkedlist::linkedlist(double val) {
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	head = temp;
	size = 1;
}

//copy constructor
linkedlist::linkedlist(const linkedlist& rhs)
{
	if (rhs.head == NULL)
	{

		head = NULL;
		size = 0;
	}
	else
	{
		node* temp = new node;
		head = NULL;
		size = 0;
		node* rhshead = rhs.head;
		head = temp;
		head->data = rhshead->data;
		head->next = NULL;
		rhshead = rhshead->next;
		size = 1;

		while (rhshead != NULL) {
			node* second = new node;
			second->data = rhshead->data;
			second->next = NULL;
			temp->next = second;
			temp = temp->next;
			rhshead = rhshead->next;
			size++;
		}
	}
}

//detroyer
linkedlist::~linkedlist() {
	
	if (head == NULL)
		return;
	node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
	}
	head = NULL;
	size = 0;
}

//Printlist used in operator<<
void linkedlist::printList() const {
	node* walk = head;
	if (size == 1)
		cout << walk->data<<endl;
	else if (size == 0)
	{
		cout << "Empty List";
	}
	if (size > 1)
	{
		while (walk != NULL)
		{
			cout << walk->data << " ";
			walk = walk->next;
		}
		cout << endl;
	}
}

//Inserts at the back
void linkedlist::pushBack(double val) {
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;

	if (head == NULL)
		head = temp;
	else {
		node* last = head;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;

	}

	size++;
}

//inserts at the front
void linkedlist::pushFront(double val) {
	node* first = new node;
	first->data = val;
	first->next = head;
	head = first;
	size++;
}

//pops front element
void linkedlist::popFront() {

	if (head == NULL || size == 0)
	{
		cout << "No values in front to be deleted" << endl;;
		return;
	}
	if (size == 1)
	{
		delete head;
		head = NULL;
		size--;
		cout << "Value deleted"<<endl;
	}
	else {
		node* first = head;
		head = head->next;
		delete first;
		first = NULL;
		size--;
		cout << "Value deleted" << endl;
		
	}
}

//pops last element
void linkedlist::popBack()
{
	if (head == NULL || size == 0)
	{
		cout << "No values deleted in back" << endl;
		return;
	}

	if (size == 1)
	{
		delete head;
		head = NULL;
		size--;
		cout << "Value deleted"<<endl;
	}
	else
	{
		node* last = head;
		node* temp = new node;
		temp = head;
		while (last->next->next != NULL)
		{
			last = last->next;
		}

		temp = last;
		last = last->next;
		delete last;
		last = NULL;
		temp->next = NULL;
		size--;
		cout << "Value deleted" << endl;
	}
}

//inserts at desired position
void linkedlist::insert(int index, double val)
{
	node* temp = head;
	node *currentnode = new node;

	currentnode->data = val;

	int counter = 0;
	if (index == 0)
	{
		pushFront(val);
		cout << "Value inserted in front" << endl;

	}
	else if (index > size - 1)
	{
		pushBack(val);
		cout << "Value inserted at the back" << endl;
	}
	else
	{
		while (counter != index)
		{
			counter++;
			if (counter == index)
			{
				currentnode->next = temp->next;
				temp->next = currentnode;
				size++;
			}
			else
			{
				temp = temp->next;
			}
		}
		cout << "Value inserted at the desired position" << endl;
	}
}

//deletes duplicate
void linkedlist::deleteDuplicates(double val)
{
	if (size == 0)
		cout << "No elements found to be deleted"<<endl;
	else
	{
		
		
		while (head->data == val)
		{
			popFront();
			if (size == 0)
				return;
		}
		node*temp = new node;
		node *destro = new node;
		if (head == NULL)
			return;
		else
		{
			temp = head;
			destro = head;
			while (temp->next != NULL)
			{
				destro = destro->next;
				if (destro->data == val)
				{

					if (destro->next != NULL)
					{
						temp->next = temp->next->next;
						delete destro;
						destro = temp;

						size--;
					}
					

					if (destro->next == NULL)
					{
						popBack();
					}

				}
				else
				{
					temp = temp->next;
				}
			}
		}
	}
}

//Deletes the m to last element in the list
double linkedlist::mtoLastElement(int m)
{
	node*temp = head;
	int counter = 0;
	double res = -1;

	if (m < 0 || m >= size)
	{
		cout << "Invalid value of m" << endl;
		
	}
	else
	{
		while (counter != (size - m) - 1)
		{
			temp = temp->next;
			counter++;
		}
		if (counter == (size - m) - 1)
		{
			res=temp->data;
		}
	}
	return res;
}

//overloaded<<
ostream& operator<<(ostream& out, const linkedlist& rhs) {
	rhs.printList();
	return out;
}

//overloaded=
linkedlist& linkedlist::operator=(const linkedlist& rhs) {
	if (rhs.head == NULL)
	{
		node* temp;
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
			temp = NULL;
		}
		head = NULL;
		size = 0;
	}
	else
	{
		node* temp = new node;
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
			temp = NULL;
		}
		head = NULL;
		size = 0;
		node* rhshead = rhs.head;
		head = temp;
		head->data = rhshead->data;
		head->next = NULL;
		rhshead = rhshead->next;
		size = 1;

		while (rhshead != NULL) {
			node* second = new node;
			second->data = rhshead->data;
			second->next = NULL;
			temp->next = second;
			temp = temp->next;
			rhshead = rhshead->next;
			size++;
		}
	}
	return *this;
}

//reverselist
void linkedlist::reverseList()
{
	node*last = head;
	node*temp = head;
	node*first = head;
	double tdata;

	if (size == 0)
		cout << "Empty list can not be reversed";
	else
	{
		for (int i = 0; i < 1; i++)
		{
			while (last->next != NULL)
			{
				last = last->next;

				if (last->next == NULL)
				{
					//swaps the data
					tdata = last->data;
					last->data = first->data;
					first->data = tdata;
					first = first->next;	//increaments the pointer by one
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			while (temp->next != last)
			{
				temp = temp->next;
			}
			if (temp->next == last&&(first!=last&&first->next!=last))
			{
				//Swaps the data
				last = temp;
				tdata = temp->data;
				temp->data = first->data;
				first->data = tdata;
				first = first->next; //increaments the pointer by one
				temp = head;
			}
			
		}

		cout << "List is reversed. Call print Function";
	}
}

//Size
int linkedlist::Size() const {

	return size;
}
