#include <iostream>

using namespace std;

class Node {
public:
	double	data;		// data
	Node*		next;		// pointer to next
};

class List {
public:
	List(void) { head = NULL; }	// constructor
//	~List(void);				// destructor

	bool IsEmpty() { return head == NULL; }
	Node* InsertNode(int index, double x);
	void DisplayList(void);
    void Concatenate(List *l2);
    int FindNode(double x);
    double MaxVal();
    int removeDuplicates();
private:
	Node *head;

};


Node* List::InsertNode(int index, double x) {
	if (index < 0 || x < 0) return NULL;

	int currIndex	=	1;
	Node* currNode	=	head;
	while (currNode && index > currIndex) {
		currNode	=	currNode->next;
		currIndex++;
	}
	if (index > 0 && currNode == NULL) return NULL;

	Node* newNode	=	new	Node;
	newNode->data	=	x;
	if (index == 0) {
		newNode->next	=	head;
		head		=	newNode;
	}
	else {
		newNode->next	=	currNode->next;
		currNode->next	=	newNode;
	}
	return newNode;
}

void List::DisplayList()
{
   int num		=	0;
   Node* currNode	=	head;
   while (currNode != NULL){
	cout << currNode->data << endl;
	currNode	=	currNode->next;
	num++;
   }
   cout << "Number of nodes in the list: " << num << endl;
}

int List::FindNode(double x) {
    Node* currNode	=	head;
    int currIndex	=	1;
    while (currNode && currNode->data != x) {
        currNode	=	currNode->next;
        currIndex++;
    }
    if (currNode) return currIndex;
    return 0;
}

void List::Concatenate(List *list2) {
    Node *currNode = head;
    while (currNode->next != NULL) {
        currNode = currNode->next;
    }
    currNode->next = list2->head;
}

int List::removeDuplicates() {
    if(head == NULL) {
        return -1;
    }
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;

        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

double List::MaxVal() {
    if(head == NULL) {
        return -1;
    }
    Node *currNode = head;
    double maxValue = 0;
    while (currNode != NULL) {
        if (currNode->data > maxValue) {
            maxValue = currNode->data;
        }
        currNode = currNode->next;
    }
    return maxValue;
}

int main() {
    List list;
    List list2;
    list.InsertNode(0, -1);
    cout << "This is the list of values: " << endl;
    list.DisplayList();

//    double result = list.MaxVal();
//    cout << "max value is: " << result << endl;
//
//    list.removeDuplicates();
//    cout << "This is the new list of values after removing the duplicates: ";
//    list.DisplayList();
//

    return 0;
}
