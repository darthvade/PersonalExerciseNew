#ifndef __STRING_H__
#define __STRING_H__

#include <cstddef>
#include <cstring>
#include <iostream>

class String {
public:
	String();
	String(const char *);
	String(const String&);
	~String();
	String& operator=(const String &);
	String& operator=(const char *);
	String operator+(const String &) const;
	bool operator==(const String &) const;
	std::size_t size() const;
	const char * c_str() const;
	void debug() const;
	char &operator[](const int &);
	const char &operator[](const int &) const;

	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);

	friend std::ostream& operator<<(std::ostream &, const String &);
	friend std::istream& operator>>(std::istream &, String &);
private:
	char *_str;
};

inline bool operator>(const String &a, const String &b) {
	return 	(strcmp(a._str, b._str) > 0 ) ? true : false ; 
}

inline bool operator<(const String &a, const String &b) {
	return 	(strcmp(a._str, b._str) < 0 ) ? true : false ; 
}

inline bool operator>=(const String &a, const String &b) {
	return !(a < b);
}

inline bool operator<=(const String &a, const String &b) {
	return !(a > b);
}

inline std::ostream& operator<<(std::ostream &os, const String &s) {
	os << s._str;
	return os;
}

inline std::istream& operator>>(std::istream &os, String &s) {
	char buf[1024];
	os >> buf;
	s = buf;
	return os;
}

#endif
