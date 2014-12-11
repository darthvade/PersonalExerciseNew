#ifndef __MYSORT_HPP__
#define __MYSORT_HPP__

#include <string>
#include <vector>

namespace MySort {
	
//交换两个变量的值
template <typename T> 
inline void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

//起比较作用的函数对象模板类
//以INC初始化代表升序排列
//以DESC初始化代表降序排列
//被排序对象需要定义大于小于运算符
template <typename T>
class Cmp {
public:
	Cmp() : _sortway("INC") {}
	Cmp(const std::string &sortway) : _sortway(sortway) {}
	bool operator () (T a, T b) {
		if(_sortway == std::string("INC")) {
			return a > b;	
		} else if(_sortway == std::string("DESC")) {
			return a < b;	
		}
		return false;
	}
private:
	std::string _sortway;
};

//冒泡排序
template <typename T>
void BubbleSort(std::vector<T> &input, const std::string &sortway) {
	Cmp<T> cmp(sortway);
	for(int i = 0; i < input.size() - 1; ++i) {
		bool flag = true;
		for(int j = input.size() - 1; j > i; --j) {
			if(cmp(input[j - 1], input[j])) {
				flag = false;	
				swap(input[j - 1], input[j]);
			}	
		}	
		if(flag) {
			return;
		}
	}
}

//直接插入排序
template <typename T>
void StraightInsertionSort(std::vector<T> &input, const std::string &sortway) {
	Cmp<T> cmp(sortway);
	for(int i = 1; i < input.size(); ++i) {
		T temp = input[i];	
		int j;
		for(j = i - 1; cmp(input[j], temp) && j >= 0; --j) {
			input[j + 1] = input[j];	
		}
		input[j + 1] = temp;
	}	
}

//简单选择排序
template <typename T>
void SimpleSelectionSort(std::vector<T> &input, const std::string &sortway) {
	Cmp<T> cmp(sortway);
	for(int i = 0; i < input.size(); ++i) {
		int select = i;
		for(int j = i + 1; j < input.size(); ++j) {
			if(cmp(input[select], input[j])) {
				select = j;	
			}		
		}
		if(select != i) {	
			swap(input[i], input[select]);
		}
	}
}

}
#endif
