#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#pragma warning( disable : 4996 )

void last(int a, int b) {

	if (a % 10 == 0) {
		printf("10\n");
		return;
	}

	a = a % 10;

	if (a == 1) {
		printf("1\n");
	}
	if (a == 2) {
		int tmplist[4] = { 2,4,8,6 };
		if (b % 4 == 0) {
			printf("%d\n", tmplist[3]);
			return;
		}
		int tmp = b % 4 - 1;
		printf("%d\n", tmplist[tmp]);
		return;
	}
	if (a == 3) {
		int tmplist[4] = { 3,9,7,1 };
		if (b % 4 == 0) {
			printf("%d\n", tmplist[3]);
			return;
		}
		int tmp = b % 4 - 1;
		printf("%d\n", tmplist[tmp]);
		return;
	}
	if (a == 4) {
		int tmplist[2] = { 4,6 };
		if (b % 2 == 0) {
			printf("%d\n", tmplist[1]);
			return;
		}
		int tmp = b % 2 - 1;
		printf("%d\n", tmplist[tmp]);
		return;
	}
	if (a == 5) {
		printf("5\n");
		return;
	}
	if (a == 6) {
		printf("6\n");
		return;
	}
	if (a == 7) {
		int tmplist[4] = { 7,9,3,1 };
		if (b % 4 == 0) {
			printf("%d\n", tmplist[3]);
			return;
		}
		int tmp = b % 4 - 1;
		printf("%d\n", tmplist[tmp]);
		return;
	}
	if (a == 8) {
		int tmplist[4] = { 8,4,2,6 };
		if (b % 4 == 0) {
			printf("%d\n", tmplist[3]);
			return;
		}
		int tmp = b % 4 - 1;
		printf("%d\n", tmplist[tmp]);
		return;
	}
	if (a == 9) {
		int tmplist[2] = { 9,1 };
		if (b % 2 == 0) {
			printf("%d\n", tmplist[1]);
			return;
		}
		int tmp = b % 2 - 1;
		printf("%d\n", tmplist[tmp]);
		return;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		last(a, b);
	}
}