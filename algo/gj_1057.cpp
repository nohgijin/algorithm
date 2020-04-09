#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int N, a, b;
	int check = 1;
	scanf("%d %d %d", &N, &a, &b);
	while (!(a % 2 == 1 && b % 2 == 0 && b == a + 1) && !(b % 2 == 1 && a % 2 == 0 && a == b + 1)) {
		a = ceil((double)a / 2);
		b = ceil((double)b / 2);
		check++;
	}
	printf("%d", check);
}