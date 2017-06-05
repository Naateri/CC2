#include <iostream>
#include <utility>
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
	}
	void append(int value){
		Node *element = new Node;
		element->val = value;
		if (first == nullptr){
			first = element; 
			element->next = nullptr;
		} else {
			Node *lel;
			lel = first;
			while (lel->next != nullptr && lel->next->val < value){
				lel = lel->next;
			}
			if (lel->next == nullptr && lel->val < value){
				lel->next = element;
				element->next = nullptr;
			} else if (lel->val > value){
				element->next = lel;
				this->first = element;
			} else {
				element->next = lel->next;
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
	LinkedList operator+(const LinkedList &B){
		LinkedList C;
		Node *lel;
		lel = this->first;
		while (lel->next != nullptr){
			C.append(lel->val);
			lel = lel->next;
		}
		C.append(lel->val);
		lel = B.first;
		while (lel->next != nullptr){
			C.append(lel->val);
			lel = lel->next;
		}
		C.append(lel->val);
		return C;
	}
	friend pair<int, int> Josephus(int muertos, int soldados){
		pair<int, int> a;
		LinkedList A;
		for (int i = 0; i < soldados; i++)
			A.append(i);
		return a;
	}
};

int main(int argc, char *argv[]) {
	LinkedList A, B, C;
	//LinkedList A;
	cout << "Linked list created\n";
	A.append(2);
	A.append(4);
	A.append(6);
	A.append(8);
	A.append(10);
	//A->append(5);
	//A->append(2);
	//A->append(4);
	A.print();
	B.append(1);
	B.append(3);
	B.append(5);
	B.append(7);
	B.append(15);
	B.print();
	C = A + B;
	C.print();
	//delete A;
	return 0;
}

