#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)


int main() {
	int bfr = 1;
	int n;
	int tmp;
	int max = 0;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (bfr > tmp) {
			max = (sum > max) ? sum : max;
			sum = 0;
		}
		bfr = tmp;
		sum++;
	}
	if (max == 0) max = sum;
	printf("%d", max);
}
