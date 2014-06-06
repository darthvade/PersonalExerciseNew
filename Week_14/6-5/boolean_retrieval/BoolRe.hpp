/*
 *	实现布尔检索查询（AND、OR、AND_NOT）
 */

#include <vector>

namespace BoolRe {
	//AND运算
	std::vector<int> Merge_And(const std::vector<int> &va, const std::vector<int> &vb) {
		std::vector<int> result;
		auto itera = va.begin();
		auto iterb = vb.begin();
		while(itera != va.end() && iterb != vb.end()) {
			if(*itera == *iterb) {
				result.push_back(*itera);
				++itera;
				++iterb;
				continue;
			} else if (*itera < *iterb) {
				++itera;	
				continue;
			} else {
				++iterb;
				continue;
			}
		}
		return result;
	}	
	//OR运算
	std::vector<int> Merge_Or(const std::vector<int> &va, const std::vector<int> &vb) {
		std::vector<int> result;
		auto itera = va.begin();
		auto iterb = vb.begin();	
		while(itera != va.end() && iterb != vb.end()) {
			if(*itera == *iterb) {
				result.push_back(*itera);
				++itera;
				++iterb;
				continue;
			} else if (*itera < *iterb) {
				result.push_back(*itera);
				++itera;
				continue;
			} else {
				result.push_back(*iterb);
				++iterb;
				continue;
			}
		}
		while(itera != va.end()) {
			result.push_back(*itera);
			++itera;
		}
		while(iterb != vb.end()) {
			result.push_back(*iterb);
			++iterb;
		}
		return result;
	}
	//AND_NOT运算
	std::vector<int> Merge_AndNot(const std::vector<int> &va, const std::vector<int> &vb) {
		std::vector<int> result;
		auto itera = va.begin();
		auto iterb = vb.begin();	
		while(itera != va.end() && iterb != vb.end()) {
			if(*itera == *iterb) {
				++itera;
				++iterb;
				continue;
			} else if(*itera < *iterb) {
				result.push_back(*itera);
				++itera;
				continue;
			} else {
				++iterb;
				continue;
			}	
		}
		while(itera != va.end()) {
			result.push_back(*itera);
			++itera;
		}
		return result;
	}
}
