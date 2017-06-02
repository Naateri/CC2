#include <iostream>
using namespace std;

class Node{
public:
	Node *next;
	int val;
};

class LinkedList{
private:
	Node *first;
public:	
	LinkedList(){
		this->first = nullptr;
		//this->first->val = nullptr;
	}
	void append(int value){
		cout << "Append:\n";
		Node *element = new Node;
		element->val = value;
		cout << "New element created\n";
		if (first == nullptr){
			first = element; 
			element->next = nullptr;
		} else {
			Node *lel;
			lel = first;
			while (lel->next != nullptr && lel->val < value){
				lel = lel->next;
			}
			cout << "out of loop\n";
			if (lel->next == nullptr){
				lel->next = element;
				element->next = nullptr;
			} else {
				element->next = lel->next->next;
				lel->next = element;
			}
		}
	}
	void print(){
		Node *lel;
		lel = this->first;
		while (lel != nullptr){
			cout << lel->val << " ";
			lel = lel->next;
		}
		cout << endl;
	}
};

int main(int argc, char *argv[]) {
	cout << "Main\n";
	LinkedList *A = new LinkedList;
	//LinkedList A;
	cout << "Linked list created\n";
	A->append(3);
	A->append(5);
	A->append(7);
	//A->append(5);
	//A->append(2);
	//A->append(4);
	A->print();
	//delete A;
	return 0;
}

