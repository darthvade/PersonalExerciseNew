//POJ-1799

#include <cstdio>
#include <cmath>

#define PI 3.1415926535

using namespace std;

int main() {
	int n = 0;
	scanf("%d", &n);
	int counter = 1;
	while(n--) {
		double big_r;
		int num;
		scanf("%lf%d", &big_r, &num);
		double mid = sin(PI / num);
		printf( "Scenario #%d:\n%.3lf\n\n", counter++, (big_r * mid) / (1 + mid));
	}
	return 0;
}
