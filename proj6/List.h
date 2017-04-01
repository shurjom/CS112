/* List.h contains the class declarations and methods
 * Student Name:Shurjo Maitra
 * Date:3.28.16
 * Joel Adams, for CS 112 at Calvin College.
 */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <stdexcept>

using namespace std;
typedef double Item;

template<class Item>
class List {
public:
	List();
	int getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	virtual ~List();
	List(const List<Item>& original);
	List<Item>& operator=(const List<Item>& original);
	bool operator!=(const List<Item>& original);
	void writeTo(ostream& out) const;
	void readFrom(const string& fileName);
	int getIndexOf(Item it) const;
	Item remove(int index);
	bool operator==(const List<Item>& other);
	void readFrom(istream& in);
	void writeTo(string fileName);
	void prepend(const Item& it);
	void insert(unsigned index, const Item& it);
	bool insertAfter(const Item& otherPersonsName, const Item& yourName);
	bool insertBefore(const Item& otherPersonsName, const Item& yourName);
	void congaWriteTo(ostream& out) const;
	friend ostream& operator<<(ostream &out, List<Item> list) {
		list.congaWriteTo(out);
		return out;
	}

private:
	struct Node {
		Item myItem;
		Node* myNext;
		Node();
		Node(const Item& it, Node* next);
		virtual ~Node();
	};
	int mySize;
	Node* myFirst;
	Node* myLast;
	friend class ListTester;
};

/*Default constructor method creates a List
 * Return: empty list with size = 0
 */
template<class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

/*Node Default constructor method creates a List
 * Return: empty list with size = 0 with linked nodes
 */
template<class Item>
List<Item>::Node::Node() {
	myItem = 0;
	myNext = NULL;
}
/*Node Explicit constructor method creates a List
 * Return: empty list with size = 0 with linked nodes explicitly
 */
template<class Item>
List<Item>::Node::Node(const Item& it, Node* next) {
	myItem = it;
	myNext = next;
}

/*getSize constructor for list class
 * Return: size of list
 */
template<class Item>
int List<Item>::getSize() const {
	return mySize;
}

/*getFirst constructor for list class
 * Return: gets the first value in the list and returns it into myItem
 */
template<class Item>
Item List<Item>::getFirst() const {
	if (mySize < 0 || myFirst == NULL) {
		throw underflow_error("Size of List is too small");
	} else {
		return myFirst->myItem;
	}
}
/*getLast constructor for list class
 * Return: gets the last value in the list and returns it into myItem
 */
template<class Item>
Item List<Item>::getLast() const {
	if (mySize < 0 || myLast == NULL) {
		throw underflow_error("Size of List can't be negative");
	} else {
		return myLast->myItem;
	}
}

/*Append operator for list class
 * @Param: nodePtr
 * Return: list with item added at the end
 */
template<class Item>
void List<Item>::append(const Item& it) {
	Node * nodePtr = new Node(it, NULL);
	if (mySize == 0) {
		myFirst = nodePtr;
	} else {
		myLast->myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize++;
}

/*Destructor for list class
 * Return: empty list
 */
template<class Item>
List<Item>::~List() {
	delete myFirst; // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}

/*Node destructor for list class
 * Return: empty node
 */
template<class Item>
List<Item>::Node::~Node() {
	delete myNext;  // delete the next node, invoking ~Node() in it
					// (does nothing if myNext == NULL)
	myNext = NULL;  // clear myNext (optional)
//	myItem = 0;     // clear myItem (optional)
}

/*Copy constructor for list class
 * Return: list copied and stored in nodes
 */
template<class Item>
List<Item>::List(const List& original) {
	myFirst = myLast = NULL;          //  set pointers
	mySize = 0;                       //   and size to 'empty' values
	if (original.getSize() > 0) {     //  if there are nodes to copy:
		Node* oPtr = original.myFirst; //  start at the first node
		while (oPtr != NULL) {         //  while there are more nodes:
			append(oPtr->myItem);       //   append the item in that node
			oPtr = oPtr->myNext;        //   advance to next node
		}
	}
}

/* Assignment operator for list class
 * @checks if list is equal to another list
 * Param: list pointers
 */
template<class Item>
List<Item>& List<Item>::operator =(const List& original) {
	if (this != &original) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		if (original.getSize() > 0) {
			Node* oPtr = original.myFirst;
			while (oPtr != NULL) {
				append(oPtr->myItem);
				oPtr = oPtr->myNext;
			}
		}
	}
	return *this;
}

/*Equality operator for list class
 * checks if the first and second list is equal
 * @Param: list1 and list2, list3(empty)
 * Return: true or false
 */
template<class Item>
bool List<Item>::operator ==(const List& original) {
	if (original.getSize() != mySize) {
		return false;
	} else {
		Node * nodePtr1 = myFirst;
		Node * nodePtr2 = original.myFirst;
		for (int i = 0; i < mySize; i++) {
			if (nodePtr1->myItem != nodePtr2->myItem) {
				return false;
			}
			nodePtr1 = nodePtr1->myNext;
			nodePtr2 = nodePtr2->myNext;
		}
	}
	return true;
}

/*Inequality operator for list class
 * checks if the first and second list are unequal
 * @Param: list1 and list2, list3(empty)
 * Return: true or false
 */
template<class Item>
bool List<Item>::operator !=(const List& original) {
	if (this == &original) {
		return false;
	} else if (this->mySize != original.mySize) {
		return true;
	}
	for (int i = 0; i < mySize; i++) {
		Node* oPtr = original.myFirst;
		if (this->myFirst != oPtr) {
			return true;
		}
	}
	return false;
}

/*readFrom() function for list class
 * @param: an istream to read from
 * Postcondition: the string is read to the list
 */
template<class Item>
void List<Item>::readFrom(istream& in) {
	if (mySize != 0) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
	}
	string line;
	getline(in, line);
	string storage;
	for (unsigned i = 0; i < line.length(); i++) {
		if (line[i] != ' ') {
			storage += line[i];
		} else if (line[i] == ' ' and line.length() - 1 != i) {
			Item it = atof(storage.c_str());
			append(it);
			storage.clear();
		}
		if (i == line.length() - 1) {
			Item it = atof(storage.c_str());
			append(it);
			storage.clear();
		}
	}
}
/*writeTo() function for list class
 * @param: an istream to write to
 * Postcondition: the string is written to the list
 */
template<class Item>
void List<Item>::writeTo(ostream& cout) const {
	Node* oPtr = myFirst;
	for (int i = 0; i < mySize; i++) {
		if (oPtr->myNext == NULL) {
			cout << oPtr->myItem << '\n';
		} else {
			cout << oPtr->myItem << '\t';

			oPtr = oPtr->myNext;
		}
	}
}
/*readFrom function to read a list from a file
 * @param: fileName, a const string&
 * Postcondition: a list is initialized from the file
 */
template<class Item>
void List<Item>::readFrom(const string& fileName) {

	if (mySize != 0) {
		delete myFirst;
		myFirst = NULL;
		myLast = NULL;
		mySize = 0;
	}
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	while (!fin.eof()) {
		if (fin.peek() == '\n') {
			break;
		}

		Item it;
		fin >> it;
		append(it);
	}
	fin.close();
}

/*getIndexOf method to get index of a value in list
 * @param: item, const Item&
 * Postcondition: value at index returned
 * Return: i, index of value (or -1 if Out of range)
 */
template<class Item>
int List<Item>::getIndexOf(Item it) const {
	Node* oPtr = myFirst;
	for (int i = 0; i < mySize; i++) {
		if (it == oPtr->myItem) {
			return i;
		} else if (it != oPtr->myItem) {
			oPtr = oPtr->myNext;
		}
	}
	return -1;
}

/*remove() method to get rid of an item from list and return
 *@param: index, const int&
 *Postcondition: item at specified index removed and returned
 *Return: temp, item removed
 */
template<class Item>
Item List<Item>::remove(int index) {
	Item temp;
	if (mySize == 0) {
		return 0;
	}

	else if (mySize == 1) {
		temp = myFirst->myItem;
		myFirst = NULL;
		myLast = NULL;
		mySize = 0;
		return temp;
	} else if (index >= mySize) {
		Node* oPtr = myFirst;
		temp = myLast->myItem;
		mySize = mySize - 1;
		for (int i = 0; i < mySize; i++) {
			oPtr = oPtr->myNext;
		}
		myLast = oPtr;
		delete oPtr->myNext;
		myLast->myNext = NULL;
		return temp;
	} else if (index <= 0) {
		Node* oPtr = myFirst;
		temp = myFirst->myItem;
		mySize = mySize - 1;
		myFirst = oPtr->myNext;
		oPtr->myNext = NULL;
		delete oPtr;
		return temp;
	} else {
		Node* oPtr = myFirst;
		for (int i = 1; i < index; i++) {
			oPtr = oPtr->myNext;
		}
		temp = oPtr->myNext->myItem;
		mySize = mySize - 1;
		Node* tPtr = oPtr->myNext;
		oPtr->myNext = tPtr->myNext;
		tPtr->myNext = NULL;
		delete tPtr;
		return temp;
	}
}

/*WriteTo() method writes values to a file
 *@param: string fileName where values are written to
 *Postcondition: values of list written to the file
 */
template<class Item>
void List<Item>::writeTo(string fileName) {
	if (mySize != 0) {
		ofstream fout(fileName.c_str());
		Node * nodePtr = myFirst;
		for (int i = 0; i < mySize; i++) {
			if (i < mySize - 1) {
				fout << nodePtr->myItem << " " << flush;
				nodePtr = nodePtr->myNext;
			} else {
				fout << nodePtr->myItem << flush;
			}
		}
	}
}

/*prepend() adds Item to front of a list
 *@param: const Item& item
 *Precondition: a list must be present
 *Postcondition: list with value added to the front
 */
template<class Item>
void List<Item>::prepend(const Item& it) {
	Node * nodePtr = new Node(it, myFirst);
	if (mySize == 0) {
		myLast = nodePtr;
	}
	myFirst = nodePtr;
	mySize++;
}

/*insert() adds value at a given index
 *@param: unsinged index, const Item& it
 *Precondition: index must be positive
 *Postcondition: input value is inserted at list index and size is refreshed
 */
template<class Item>
void List<Item>::insert(unsigned index, const Item& it) {
	if (index == 0) {
		this->prepend(it);
	} else if (index == this->mySize - 1) {
		this->append(it);
	} else {
		Node * n1 = new Node(it, NULL);
		Node * ptr = this->myFirst;
		for (unsigned i = 0; i < index; i++) {
			ptr = ptr->myNext;
		}
		n1->myNext = ptr->myNext;
		ptr->myNext = n1;
	}
	this->mySize++;
}

/*insertBefore() puts a name before another in a list
 *@param: otherPersonsName, yourName, const Item&s
 *Postcondition: yourName is inserted before otherPersonsName
 *return: bool, true/false
 */
template<class Item>
bool List<Item>::insertBefore(const Item& otherPersonsName,
		const Item& yourName) {
	int index = getIndexOf(otherPersonsName);
	if (index == -1) {
		return false;
	} else {
		this->insert(index, yourName);
		return true;
	}
}

/*insertAfter() puts a name after another in a list
 *@param: otherPersonsName, yourName, const Item&s
 *Postcondition: yourName is inserted after otherPersonsName
 *Return: bool, true/false
 ToDo: Still pretty buggy
 */

template<class Item>
bool List<Item>::insertAfter(const Item& otherPersonsName, const Item& yourName) {
//	Node * currentPtr = myFirst;
//	Node * newItem = new Node(yourName, NULL);
//
//	while (currentPtr) {
//		if (mySize == 0) {
//			return false;
//		} else {
//			for (int i = 0; i < mySize; i++) {
//				if (currentPtr->myItem == otherPersonsName) {
//					if (mySize == 1) {
//						this->append(yourName);
//					}
//					newItem->myNext = currentPtr->myNext;
//					currentPtr->myNext = newItem;
//					mySize += 1;
//					return true;
//				}
//
//				currentPtr = currentPtr->myNext;
//			}
//		}
//		return false;
//	}
//}
	Node* nPtr = myFirst;
	while (nPtr) {

		if (nPtr->myItem == otherPersonsName) {

			Node* newPtr = new Node(yourName, nPtr->myNext);
			nPtr->myNext = newPtr;
			mySize++;
			return true;
		}
		nPtr = nPtr->myNext;
	}

	return false;
}

/*congaWriteTo() outputs the names in the CongaLine
 *@param: out, ostream&
 *Postcondition: items in CongaLine are pushed in ostream seperated with a space
 */
template<class Item>
void List<Item>::congaWriteTo(ostream& out) const {
	Node* nPtr = myFirst;
	if (mySize == 0) {
		out << nPtr->myItem << "\t" << flush;
	} else {
		while (nPtr) {
			if (nPtr == myLast) {
				out << nPtr->myItem;
			} else {
				out << nPtr->myItem;
			}
			nPtr = nPtr->myNext;
		}
	}

}
