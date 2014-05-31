#include <xapian.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	if(argc < 4) {
		return 1;
	}
	try {
		Xapian::WritableDatabase database(argv[1], Xapian::DB_CREATE_OR_OPEN);
		Xapian::Document newdocument;
		newdocument.set_data(string(argv[2]));	
		for(int  i = 3; i < argc; ++i) {
			newdocument.add_posting(argv[i], i - 2);
		}	
		database.add_document(newdocument);
	} catch (const Xapian::Error &error) {
		cout << "Exception: " << error.get_msg() << endl;
	}
	return 0;
}
