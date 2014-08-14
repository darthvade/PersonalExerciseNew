#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

string add(string &a, string &b) {
	int pre = 0;
	stack<char> result;
	string::reverse_iterator itera, iterb;
	for(itera = a.rbegin(), iterb = b.rbegin(); itera != a.rend() && iterb != b.rend(); ++itera, ++iterb) {
		int temp = *itera - '0' + *iterb - '0' + pre;
		if(temp >= 10) {
			pre = temp / 10;	
			temp %= 10;
		} else {
			pre = 0;
		}
		result.push(temp + '0');
	}
	while(itera != a.rend()) {
		int temp = *itera - '0' + pre;
		if(temp >= 10) {
			pre = temp / 10;	
			temp %= 10;
		} else {
			pre = 0;
		}
		result.push(temp + '0');
		++itera;	
	}
	while(iterb != b.rend()) {
		int temp = *iterb - '0' + pre;
		if(temp >= 10) {
			pre = temp / 10;	
			temp %= 10;
		} else {
			pre = 0;
		}
		result.push(temp + '0');
		++iterb;	
	}
	if(pre) {
		result.push(pre + '0');
	}	
	string real_result;
	while(!result.empty()) {
		real_result.push_back(result.top());
		result.pop();	
	}
	return real_result;
}

string mult_n(string a, int n) {
	string result("0");
	while(n--) {
		result = add(result, a);	
	}
	return result;
}

string mult(string a, string b) {
	string result;
	string::reverse_iterator iter;
	int counter = 0;
	for(iter = b.rbegin(); iter != b.rend(); ++iter) {
		string temp;
		temp = mult_n(a, *iter - '0');
		int temp_counter = counter;
		while(temp_counter--) {
			temp.push_back('0');
		}
		counter++;
		result = add(temp, result);
	}
	return result;
}

string int_power(string a, int n) {
	string result("1");
	while(n--) {
		result = mult(result, a);	
	}
	return result;
}

string float_power(string a, int n) {
	int point_pos = 0;
	size_t float_counter = 0;
	for(size_t i = 0; i < a.size(); ++i) {
		if(a[i] == '.') {
			point_pos = i;
			float_counter = (a.size() - i - 1) * n;
			break;
		}	
	}
	string temp_result = int_power(a.erase(point_pos, 1), n);
	//debug
	//cout << float_counter << endl;
	if(temp_result.size() < float_counter) {
		size_t gap = float_counter - temp_result.size();	
		while(gap--) {
			temp_result.insert(0, "0");	
		}
		temp_result.insert(0, ".");
	} else {
		temp_result.insert(temp_result.size() - float_counter, ".");
	}
	int delete_zeros_pos = temp_result.size() - 1;
	int delete_n_zeros = 0;
	while(temp_result[delete_zeros_pos] == '0') {
		if(temp_result[delete_zeros_pos - 1] == '.') {
			break;
		}
		delete_n_zeros++;
		delete_zeros_pos--;	
	}
	temp_result.erase(delete_zeros_pos + 1, delete_n_zeros);
	int front_delete_zeros_pos = 0;
	int front_delete_n_zeros = 0;
	while(temp_result[front_delete_zeros_pos] == '0') {
		front_delete_n_zeros++;
		front_delete_zeros_pos++;
	}
	return temp_result.erase(0, front_delete_n_zeros);
}

int main() {
	string a;
	int n;
	while(cin >> a >> n) {
		cout << float_power(a, n) << endl;
	}
	return 0;
}
