int main() {
	double pi = 3.14;
	const int &ref = pi;
	enum POS {north = 1, south, west, east};
	POS p = north;
	p = west;
	return 0;
}
