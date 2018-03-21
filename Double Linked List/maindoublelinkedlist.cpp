/*
This program is a double linked list of int data type. It is a menu driven program with the following operations. 
next and prev are two pointers refering to the node in  a double linked list.
*/

#include "doublelinkedlist.h"

int main() {

	dlinkedlist one;
	dlinkedlist four;
	int value;
	int index;
	int choice;
	do {

		cout << endl;
		cout << "0)Copy Constructor" << "\t" << "1)Exit" << "\t\t\t" << "2)PushFront" << "\n" << "3)PushBack" << "\t\t";
		cout << "4)PopFront" << "\t\t" << "5)PopBack" << "\n";
		cout << "6)insert(index,value)" << "\t" << "7)deleteDuplicates(val)" << "\t" << "8)mtoLastElement(M)" << "\n";
		cout << "9)size()" << "\t\t";
		cout << "10)reverseList()" << "\t" << "11)Print operator<<" << "\n" << "12)Overloaded=" << "\t\t";
		cout << "13)Argumented constructor" << "\n";
		cout << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 13)
		{
			cout << "Argumented Constructor in list 2" << endl << "Enter the value: " << " ";
			cin >> value;
			dlinkedlist two(value);
			cout << "List 2: " << two;
			cout << endl;
			cout << endl;
			continue;

		}

		if (choice == 0)
		{
			cout << "Copy constructor called. Third copied from one" << endl;
			dlinkedlist three(one);
			cout << "Third list is: " << three;
			cout << endl;
			continue;
		}
		switch (choice)
		{
		case 1:	cout << "Destructor called" << endl;
			exit(0);
			break;
		case 2: cout << "Insert the value in front: " << endl;
			cin >> value;
			one.pushFront(value);
			break;
		case 3: cout << "Insert value in the back: " << endl;
			cin >> value;
			one.pushBack(value);
			break;
		case 4:one.popFront();
			break;
		case 5:one.popBack();
			break;
		case 6:	cout << "Insert the value at the index :" << endl;
			cin >> index;
			cout << "Enter the value to be inserted: " << endl;
			cin >> value;
			one.insert(index, value);
			break;
		case 7: cout << "Enter the value to be deleted: " << endl;
			cin >> value;
			one.deleteDuplicates(value);
			break;
		case 8: cout << "Enter the mth value :" << endl;
			cin >> index;
			value = one.mtoLastElement(index);
			cout << "Value is: " << value;
			break;
		case 9:	cout << "Size :" << one.Size();
			break;
		case 10:one.reverseList();
			break;
		case 11:cout << "List 1 : ";
			cout << one;
			break;
		case 12:cout << "Overloaded= called" << endl;
			four = one;
			cout << "4th list is:" << four;
			break;
		default:cout << "Wrong input.Please try again" << endl;
			break;
		}

	} while (choice != 1);
	return 0;
}