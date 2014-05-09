#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <map>

class TextQuery {
public:
	typedef std::vector<std::string>::size_type line_no;
	void read_file(std::istream &is) {
		store_file(is);
		build_map();
	}
	std::set<line_no> run_query(const std::string) const;
	std::string text_line(line_no) const;
private:
	void store_file(std::istream& is);
	void build_map();
	std::vector<std::string> lines_of_text;
	std::map< std::string, std::set<line_no> > word_map;
};


#endif
