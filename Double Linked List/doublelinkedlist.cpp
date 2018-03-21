#include "doublelinkedlist.h"

//default constructor
dlinkedlist::dlinkedlist() {

	head = NULL;
	tail = NULL;
	size = 0;
}

//argumented constructor
dlinkedlist::dlinkedlist(int val) {

	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	temp->prev = NULL;
	head = temp;
	tail = temp;
	size = 1;
}
//copy constructor
dlinkedlist::dlinkedlist(const dlinkedlist& rhs)
{
	if (rhs.head == NULL)
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	else
	{
		head = NULL;
		tail = NULL;
		size = 0;
		node* temp = new node;
		node* rhshead = rhs.head;
		//temp->data = rhshead->data;
		head = temp;
		head->data = rhshead->data;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		rhshead = rhshead->next;
		size = 1;

		while (rhshead != NULL) {
			pushBack(rhshead->data);
			rhshead = rhshead->next;
		}
	}
}

//default constructor
dlinkedlist::~dlinkedlist() {
	
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

//printing the list. Used in operator<<
void dlinkedlist::printList() const {
	node* walk = head;
	if (size == 1)
		cout << walk->data;
	else if (size == 0)
	{
		cout << "Empty List";

	}
	else
	{
		while (walk != NULL) {
			cout << walk->data << " ";
			walk = walk->next;
		}
	}
	cout << endl;
}

//Inserts at the back
void dlinkedlist::pushBack(int val) {

	if (size == 0)
	{
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
		size++;

	}

	else
	{
		node* last = new node;
		last->data = val;
		last->next = NULL;
		last->prev = tail;
		tail->next = last;
		tail = last;
		size++;
	}
}

//Inserts in front
void dlinkedlist::pushFront(int val) {

	if (size == 0)
	{
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
		size++;

	}

	else
	{
		node* first = new node;
		first->data = val;
		first->next = head;
		first->prev = NULL;
		head->prev = first;
		head = first;
		size++;
	}
}

//Deletes in front
void dlinkedlist::popFront() {
	if (head == NULL || size == 0)
	{
		cout << "No values found to be deleted" << endl;
		return;
	}
		
	if (size == 1)
	{
		delete head;
		head = NULL;
		tail = NULL;
		size--;
		cout << "Values are delted" << endl;
	}
	else {
		node* first = head;
		head = head->next;
		head->prev = NULL;
		delete first;
		first = NULL;
		size--;
		cout << "Values are deleted" << endl;
	}


}

//Deletes in the back
void dlinkedlist::popBack()
{
	if (tail == NULL)
	{
		cout << "No values found to be deleted" << endl;
		return;
	}

	if (size == 1)
	{
		delete tail;
		tail = NULL;
		head = NULL;
		size--;
		cout << "Values deleted" << endl;
	}
	else
	{
		node*last = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete last;
		last = NULL;
		size--;
		cout << "Values deleted" << endl;

	}
}

//inserts at desired position
void dlinkedlist::insert(int index, int val)
{
	node*current = head;
	node *newnode = new node;
	node*after;
	newnode->data = val;

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
				newnode->next = current->next;
				after = newnode->next;
				after->prev = newnode;
				current->next = newnode;
				newnode->prev = current;
				size++;
			}
			else
			{
				current = current->next;
			}

		}
		cout << "Value inserted at desired position" << endl;
	}


}

//Deletes the duplicate value
void dlinkedlist::deleteDuplicates(int val)
{

	if (size == 0)
		cout << "No values to be deleted" << endl;
	
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
						//dislinking the nodes
						destro->prev->next = destro->next;
						destro->next->prev = destro->prev;
						delete destro;	//deleting the nodes
						destro = NULL;
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

//Prints the mth element in the list
int dlinkedlist::mtoLastElement(int m)
{
	node*temp = head;
	int counter = 0;
	int res = -1;

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
			if (counter == (size - m))
			{
				return temp->data;
			}
		}
		if (counter == (size - m) - 1)
		{
			res= temp->data;
		}
	}
	return res;

}

//<<operator overloaded
ostream& operator<<(ostream& out, const dlinkedlist& rhs) {
	rhs.printList();
	return out;
}
//assignment= operator overloaded
dlinkedlist& dlinkedlist::operator=(const dlinkedlist& rhs) {
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
		tail = NULL;
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
		tail = NULL;
		size = 0;
		node* rhshead = rhs.head;
		temp = new node;
		head = temp;
		head->data = rhshead->data;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
		rhshead = rhshead->next;
		size = 1;

		while (rhshead != NULL) {
			pushBack(rhshead->data);
			rhshead = rhshead->next;
		}
	}
	return *this;
}

//reverselist
void dlinkedlist::reverseList()
{
	
	node*last = head;
	node*temp = head;
	node*first = head;
	int tdata;

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
					//swapping of data
					tdata = last->data;
					last->data = first->data;
					first->data = tdata;
					first = first->next; //increamenting the pointer

				}

			}
		}
		for (int i = 0; i < size; i++)
		{
			while (temp->next != last)
			{
				temp = temp->next;

			}
			if (temp->next == last && (first != last&&first->next != last))
			{
				//swapping of the data
				last = temp;
				tdata = temp->data;
				temp->data = first->data;
				first->data = tdata;
				first = first->next;	//increamenting the pointer
				temp = head;

			}
		}

		cout << "List is reversed. Call print Function";
	}

}

//Return size
int dlinkedlist::Size() const {

	return size;
}
