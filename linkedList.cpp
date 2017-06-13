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
	void del(int i){
		Node* lel;
		Node* prev;
		lel = this->first;
		prev = lel;
		lel = lel->next;
		int j = 1;
		if (i == 0){
			prev->next = nullptr;
			this->first = lel;
			cout << "Borrado: " << prev->val << endl;
		} else {
			while(j < i && lel->next != nullptr){
				lel = lel->next;
				prev = prev->next;
				j++;
			}
			if (lel->next == nullptr){
				prev->next = nullptr;
			} else {
				prev->next = lel->next;
				lel->next = nullptr;
			}
			cout << "Borrado: " << lel->val << endl;
			delete lel;
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
	LinkedList operator+=(const LinkedList &B){
		Node *lel;
		Node *lal;
		lel = this->first;
		lal = B.first;
		if (lel->val > lal->val){
			this->first = lal;
			lel->next = lel->next->next;
			lal->next = lel;
		}
		while(lel != nullptr && lal != nullptr){
			if (lel->val < lal-> val){
				lel->next = lel->next->next;
				lal->next = lel;
			} else {
				;
			}
		}
	}
};

LinkedList Josephus(int muertos, int soldados){
	LinkedList A;
	for (int i = 1; i <= soldados; i++)
		A.append(i);
	int ded = (muertos-1) % soldados;
	for (soldados; soldados > 2; soldados--){
		//if (soldados == 3) break;
		A.del(ded);
		ded = ded + (muertos-1);
		ded = ded % (soldados-1);
	}
	return A;
}
int main(int argc, char *argv[]) {
	LinkedList A, B, C;
	//LinkedList A;
	A.append(2);
	A.append(4);
	A.append(8);
	A.append(9);
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
	LinkedList Jos;
	Jos = Josephus(3, 40);
	cout << "Quedan los soldados: ";
	Jos.print();
	//delete A;
	return 0;
}

