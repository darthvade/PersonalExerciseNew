#include "SingleLinkedList.h"
#include <vector>
#include <string>


int main() {
	std::vector<int> vec1{1, 2, 3, 3, 5, 6};	
	std::vector<std::string> vec2{"AA", "BB", "CC", "DD", "EE"};
	SingleLinkedList<int> mylist1;
	SingleLinkedList<int> mylist2(vec1);
	SingleLinkedList<std::string> mylist3(vec2);
	mylist1.printAll();
	mylist2.printAll();
	mylist3.printAll();
	return 0;
}
