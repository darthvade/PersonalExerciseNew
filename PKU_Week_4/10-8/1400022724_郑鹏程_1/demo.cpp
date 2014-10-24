#include "SingleLinkedList.h"
#include <vector>
#include <string>
#include "ProgramTasks.hpp"


int main() {
	//第一题
	std::vector<int> veca{-99, -1, -1, 1, 2, 1, 3, 5, 6, 10};	
	std::vector<int> vecb{-3, 0, 0, 1, 4, 4, 6, 6, 8, 8, 999999};	
	SingleLinkedList<int> la(veca);
	SingleLinkedList<int> lb(vecb);
	std::cout << "LinkA: ";
	la.printAll();
	std::cout << "LinkB: ";
	lb.printAll();
	ProgramTasks::MergeNondescList<int>(la, lb);
	std::cout << "Result: ";
	la.printAll();
	
	//第二题
	std::cout << "---" << std::endl;
	std::vector<int> vec1{0, 0, 0, 0, 0, 1, 1, 1, 2};	
	std::vector<int> vec2{0, 0, 0, 0, 0, 1, 1, 2, 3};	
	SingleLinkedList<int> mylist1(vec1);
	SingleLinkedList<int> mylist2(vec2);
	std::cout << "LinkA: ";
	mylist1.printAll();
	std::cout << "LinkB: ";
	mylist2.printAll();
	ProgramTasks::MergeNonincList<int>(mylist1, mylist2);
	std::cout << "Result: ";
	mylist1.printAll();

	//第三题
	std::cout << "---" << std::endl;
	std::vector<int> vec3{100, 6, 0, 67, 0, 99, 1, 7, 1, 2};	
	SingleLinkedList<int> mylist3(vec3);
	std::cout << "LinkA: ";
	mylist3.printAll();
	std::cout << "Result: ";
	std::cout << ProgramTasks::findMax<int>(mylist3) << std::endl;

	//第四题
	std::cout << "---" << std::endl;
	std::cout << "LinkA: ";
	mylist3.printAll();
	std::cout << "Result: ";
	ProgramTasks::reverseList(mylist3);
	mylist3.printAll();

	//第五题
	std::cout << "---" << std::endl;
	std::vector<int> vec4{0, 0, 0, 0, 0, 1, 1, 2, 3, 3, 5, 54, 99, 101, 1999, 24242};	
	SingleLinkedList<int> mylist4(vec4);
	std::cout << "LinkA: ";
	mylist4.printAll();
	int left = -1;
	int right = 101;
	std::cout << "Remove Range: [" << left << ", " << right << "]" << std::endl;
	ProgramTasks::removeRange(mylist4, left, right);
	std::cout << "Result: ";
	mylist4.printAll();

	return 0;
}
