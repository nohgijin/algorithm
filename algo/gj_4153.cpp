#include <stdio.h>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int a, b, c;
	while (true) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) break;
		if (a*a + b * b == c * c) printf("right\n");
		else printf("wrong\n");
	}
}