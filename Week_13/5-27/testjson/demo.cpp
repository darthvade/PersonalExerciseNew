#include "./json/json.h"
#include <iostream>

using namespace std;

int main() {

	Json::Value result;
	result["title"] = "One title";
	result["Content"] = "xxoo vs ooxx";

	//cout << result.toStyledString() << endl;
	Json::StyledWriter stlwriter;
	cout << stlwriter.write(result) << endl;

	return 0;
}
