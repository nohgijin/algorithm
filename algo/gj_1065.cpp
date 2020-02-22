#include <stdio.h>
#include <iostream>
using namespace std;

#pragma warning(disable:4996)

int N;
int result = 99;

int hansu() {
	if (N <= 99) result = N;
	else if (N <= 110) result = 99;
	else if (N > 110) {
		for (int i = 111; i <= N; i++) {
			int first = i / 100;
			int tmp = i / 10;
			int second = tmp % 10;
			int third = i % 10;
			if ((first - second) == (second - third))
				result++;
		}
	}
	return result;
}

int main() {
	scanf("%d", &N);
	result = hansu();
	printf("%d", result);
}