//POJ 1003

#include <cstdio>

int func(double input) {
	int counter = 1;
	double temp = 0.0;
	while(1) {
		if(temp > input) {
  			return counter - 1;
		}
		temp += 1.0 / (counter + 1);
		counter++;
	}
}

int main() {
	double input;
	while(scanf("%lf", &input) != EOF) {
		if(input == 0.0) {
			break;
		}
		printf("%d card(s)\n", func(input));
	}
	return 0;
}
