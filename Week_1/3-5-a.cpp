/**
*  程序设计实习 第二周作业
*/
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

class Student {
	private:
		string name;
		int age;
		string id;
		int s_y1;
		int s_y2;
		int s_y3;
		int s_y4;
		int score_avg;
	public:
		Student(string n, int a, string i);
		void setScore(int y1, int y2, int y3, int y4);
		void print_info();
};

int main() {
	string name;
	int age;
	string id;
	int y1;
	int y2;
	int y3;
	int y4;
	string info;
	getline(cin, info);
	info.replace(info.begin(), info.end(), ',', ' ');
	istringstream istr(info);
	istr >> name >> age >> id >> y1 >> y2 >> y3 >> y4;
	Student s(name, age, id);
	s.setScore(y1, y2, y3, y4);
	s.print_info();
	return 0;
}

Student::Student(string n, int a, string i) {
	name = n;
	age = a;
	id = i;
}

void Student::setScore(int y1, int y2, int y3, int y4) {
	s_y1 = y1;
	s_y2 = y2;
	s_y3 = y3;
	s_y4 = y4;
	score_avg = (y1 + y2 + y3 + y4) / 4;
}

void Student::print_info() {
	cout << name << ',' << age << ',' << id << ',' <<  score_avg << endl;
}
