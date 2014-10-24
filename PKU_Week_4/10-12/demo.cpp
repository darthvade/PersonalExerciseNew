#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	struct Node *next;
};

struct Node* initLink(vector<int> &input) {
	struct Node *head = new struct Node;
	for(auto p = input.begin(); p != input.end(); ++p) {
		auto temp = new struct Node;
		temp->data = *p;	
		temp->next = head->next;
		head->next = temp;
	}
	return head;
}

void print(struct Node *input) {
	auto p = input->next;
	while(p) {
		cout << p->data << " | ";	
		p = p->next;
	}
	cout << endl;
}

int main() {
	vector<int> input{1, 2, 3, 4, 5, 6};	
	auto head = initLink(input);
	print(head);
	return 0;
}
