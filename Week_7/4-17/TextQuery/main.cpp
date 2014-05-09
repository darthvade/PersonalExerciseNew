#include "TextQuery.h"
#include <fstream>

std::string make_plural(std::size_t ctr, const std::string &word, const std::string &ending);

void print_results(const std::set<TextQuery::line_no>& locs, const std::string& sought, const TextQuery &file);

std::ifstream& open_file(std::ifstream &in, const std::string &file);

using namespace std;

int main(int argc, char *argv[]) {
	ifstream infile;
	if(argc < 2 || !open_file(infile, argv[1])) {
		cerr << "No input file!" << endl;
		return -1;
	}
	TextQuery tq;
	tq.read_file(infile);
	while(true) {
		cout << "enter word to look for, or q to quit: " << endl;
		string s;
		cin >> s;
		if(!cin || s == "q") {
			break;
		}
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}
	return 0;
}

void print_results(const std::set<TextQuery::line_no>& locs, const std::string& sought, const TextQuery &file) {
	typedef set<TextQuery::line_no> line_num;
	line_num::size_type size = locs.size();
	cout << "\n" << sought << " occurs" << size << " " << make_plural(size, "time", "s") << endl;
	line_num::const_iterator it = locs.begin();
	for(; it != locs.end(); ++it) {
		cout << "\t(line" << (*it) + 1 << ")" << file.text_line(*it) << endl;
	}
}

std::ifstream& open_file(std::ifstream &in, const std::string &file) {
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

std::string make_plural(std::size_t ctr, const std::string &word, const std::string &ending) {
	return (ctr == 1) ? word : word + ending;
}
