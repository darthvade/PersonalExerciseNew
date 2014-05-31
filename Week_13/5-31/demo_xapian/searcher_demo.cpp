#include <xapian.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	if(argc < 3) {
		return 1;
	}
	try {
		Xapian::Database db(argv[1]);
		Xapian::Enquire enquire(db);
		Xapian::Query query(Xapian::Query::OP_OR, argv + 2, argv + argc);
		//DEBUG
		cout << "Performing query {" << query.get_description() << "}" << endl;
		
		enquire.set_query(query);
		Xapian::MSet matches = enquire.get_mset(0, 5);

		//DEBUG
		cout << "Result Size: " << matches.size() << endl;

		for(auto i = matches.begin(); i != matches.end(); ++i) {
			Xapian::Document doc = i.get_document();	
			cout << "DocID: " << *i << '\t' << i.get_percent() << "%" << 
				"[" << doc.get_data() << "]" << "[" << doc.get_value(0) << "]" <<endl;	
		}
	
	} catch (const Xapian::Error &error) {
		cout << "Exception: " << error.get_msg() << endl;
	}
	
	return 0;
}
