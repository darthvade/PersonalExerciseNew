#include <iostream>
#include <vector>
#include <string>

template <typename T>
struct Node {
	Node() = default;
	Node(T idata, struct Node *inext) : data(idata), next(inext) {}
	T data;
	struct Node *next;
};

template <typename T>
class SingleLinkedList {
public:
	SingleLinkedList() : _length(0) {
		//_phead = new struct Node<T>(0, NULL);	
		_phead = new struct Node<T>(T(), NULL);	
	}
	SingleLinkedList(std::vector<T> &input) {
		_phead = new struct Node<T>(T(), NULL);	
		for(auto p = input.rbegin(); p != input.rend(); ++p) {
			auto temp = new struct Node<T>(*p, _phead->next);	
			_phead->next = temp;
			++_length;
		}	
	}
	~SingleLinkedList() {
		auto p = _phead->next;
		while(p) {
			auto temp = p;
			p = p->next;
			delete temp;
		}	
		delete _phead;
	}
	void print() {
		auto p = _phead->next;
		while(p) {
			std::cout << p->data << "-->";
			p = p->next;	
		}	
		std::cout << std::endl;
	}
private:
	int _length;
	struct Node<T> *_phead;
};

int main() {
	std::vector<std::string> input{"hehe", "doubi", "nm", "OS"};
	SingleLinkedList<std::string> mylist(input);
	mylist.print();
	std::vector<int> input2{1, 2, 3, 4, 5};
	SingleLinkedList<int> mylist2(input2);
	mylist2.print();
	SingleLinkedList<int> mylist3;
	mylist3.print();
	return 0;
}
