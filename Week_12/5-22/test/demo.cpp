#include <vector>

using namespace std;

int main() {

	vector<vector<int> > vec(2);
	vector<vector<int> >::iterator iter = vec.begin();
	iter->push_back(1);

	return 0;
}
