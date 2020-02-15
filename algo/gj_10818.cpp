#include <iostream>
#include <string.h>

using namespace std;

#pragma warning( disable : 4996 )

int N;
int input;
int main() {
	int max, min;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (i == 0) {
			max = input;
			min = input;
		}
		else {
			max = (max >= input) ? max : input;
			min = (min <= input) ? min : input;
		}
	}
	printf("%d %d", min, max);
}
