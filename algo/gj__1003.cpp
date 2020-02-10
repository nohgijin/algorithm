#include <stdio.h>
#include <iostream>
#pragma warning( disable : 4996 )
int number[41][2] = {0, };

int main() {
	int T, N;
	scanf("%d", &T);
	number[0][0] = 1; number[1][1] = 1;
	for (int k = 2; k <= 40; k++) {
		number[k][0] = number[k - 1][0] + number[k - 2][0];
		number[k][1] = number[k - 1][1] + number[k - 2][1];
	}
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		printf("%d %d", number[N][0], number[N][1]);
		printf("\n");
	}
}