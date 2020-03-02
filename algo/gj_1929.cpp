#include <iostream>
#include <math.h>
using namespace std;

#pragma warning(disable:4996)

int M, N;
bool prime[1000100];

void sosu() {
	for (int i = 2; i <= N; i++) {
		if (prime[i]) {
			for (int j = i + i; j <= N; j = j + i) prime[j] = false;
		}
	}
}

int main() {
	scanf("%d %d", &M, &N);
	fill_n(prime, 1000100, true);
	prime[1] = false;
	sosu();
	for (int i = M; i <= N; i++) {
		if (prime[i] == true) printf("%d\n", i);
	}
	return 0;
}