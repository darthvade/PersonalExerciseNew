#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	virtual void print() { 
		cout << "id: " << _id << " name: " << _name << endl;   
	}	
	void setinfo(int id, const string &s) {
		_id = id;
		_name = s;
	}
private:
	int _id;
	string _name;
};

class Student : public Person {
public:
	void print() {
		cout << "school: " << _school << endl;
	}
	void setschool(const string& s) {
		_school = s;
	}
private:
	string _school;
};

int main() {
	Student s;
	s.setinfo(1, "Kevin");
	s.setschool("UUUU");
	s.Person::print();
	s.print();

	Person *p = &s;
	p->print();

	Person &pp = s;
	pp.print();
	return 0;
}
