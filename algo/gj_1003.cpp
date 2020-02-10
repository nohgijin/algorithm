#include <stdio.h>
#include <iostream>
#pragma warning( disable : 4996 )
int number[2] = { 0, };

int fibo(int T) {
	if (T == 0) {
		number[0]++;
	}
	else if (T == 1) {
		number[1]++;
	}
	else return fibo(T - 1) + fibo(T - 2);
}

int main() {
	int T,N;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%d", &N);
		fibo(N);
		printf("%d %d", number[0], number[1]);
		printf("\n");
		number[0]=0; number[1]=0;
	}
}