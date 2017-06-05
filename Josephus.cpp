#include <iostream>
#include <utility>
using namespace std;

class Node{
public:
	Node *next;
	int val;
};

class CircularLinkedList{
private:
	Node *first;
public:	
	CircularLinkedList(){
		this->first = nullptr;
	}
	void append(int value){
		Node *element = new Node;
		element->val = value;
		if (first == nullptr){
			this->first = element; 
			element->next = this->first;
		} else {
			Node *lel;
			lel = this->first;
			lel = lel->next;
			while (lel->next != this->first && lel->next->val < value){
				lel = lel->next;
			}
			if (lel->next == this->first && lel->val < value){
				lel->next = element;
				element->next = this->first;
			} else if (lel->val > value){
				element->next = lel;
				//this->first = element;
				lel = lel->next;
				while(lel->next != this->first)
					lel = lel->next;
				lel->next = element;
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
		if (i == 0){
			while (lel->next != this->first){
				lel = lel->next;
			}
			prev = prev->next;
			lel->next = prev;
			this->first->next = nullptr;
			this->first = prev;
		} else {
			for(int j = 1; j < i; j++){
				lel = lel->next;
				prev = prev->next;
			}
			prev->next = lel->next;
			lel->next = nullptr;
			this->first = prev->next;
			//delete lel;
		}
	}
	void print(){
		Node *lel;
		lel = this->first;
		cout << lel->val << " ";
		lel = lel->next;
		while (lel != this->first){
			cout << lel->val << " ";
			lel = lel->next;
		}
		cout << endl;
	}
	//friend pair<int, int> Josephus(int muertos, int soldados){
	/*friend CircularLinkedList Josephus(int muertos, int soldados){
		CircularLinkedList A;
		for (int i = 0; i < soldados; i++)
			A.append(i);
		int ded = 0;
		for (soldados; soldados > 2; soldados--){
			A.del(ded % soldados);
			ded += muertos;
		}
		return A;
	}*/
};

CircularLinkedList Josephus(int muertos, int soldados){
	CircularLinkedList A;
	for (int i = 0; i < soldados; i++)
		A.append(i);
	int ded = muertos-1;
	for (soldados; soldados > 2; soldados--){
		if (soldados == 3) break;
		A.del(ded);
		ded = ded + (muertos-1);
		cout << "ded: " << ded << endl;
		cout << "soldados: " << soldados-1 << endl;
		ded = ded % (soldados-1);
		cout << "ded mod soldados: " << ded << endl;
	}
	return A;
}

int main(int argc, char *argv[]) {
	CircularLinkedList jos;
	/*jos.append(1);
	jos.print();
	jos.append(2);
	jos.print();
	jos.append(3);
	jos.print();*/
	jos = Josephus(3, 9);
	jos.print();
	return 0;
}

