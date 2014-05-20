#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
	ifstream content("/home/kevin/SpiderData/dmoz/pageTermContent.data");
	vector<pair<unsigned int, string> > contentvec;
	string docid;
	string data;
	while(getline(content, docid)) {
		getline(content, data);	
		contentvec.push_back(make_pair(atoi(docid.c_str()), data));
		content.clear();
	}
	content.close();

	ofstream con("hehe");
	typedef vector<pair<unsigned int, string> >::iterator Iter;
	Iter iter = contentvec.begin();
	while(iter != contentvec.end()) {
		con << iter->first << endl << iter->second << endl;	
		++iter;
	}
	con.close();
	return 0;
}
