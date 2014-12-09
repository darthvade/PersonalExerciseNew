#ifndef __MYSORT_HPP__
#define __MYSORT_HPP__

#include <string>
#include <vector>

namespace MySort {
	
template <typename T> 
inline void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

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

template <typename T>
void BubbleSort(std::vector<T> &input, const std::string &sortway) {
	Cmp<T> cmp(sortway);
	for(std::size_t i = 0; i != input.size() - 1; ++i) {
		bool flag = true;
		for(std::size_t j = input.size() - 2; j != i; --j) {
			if(cmp(input[j], input[j + 1])) {
				flag = false;	
				swap(input[j], input[j + 1]);
			}	
		}	
		if(flag) {
			return;
		}
	}
}

}
#endif
