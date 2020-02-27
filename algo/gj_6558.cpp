#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#pragma warning(disable:4996)

int n;
int a = 0;
int b = 0;
int output = 0;

bool prime[1000002] = { true, };

void as() {
	for (int i = 2; i < 1000002; i++) prime[i] = true;
	//	fill_n(prime, 100002, 1);
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i]) {
			for (int j = i + i; j <= 1000000; j += i) {
				prime[j] = false;
			}
		}
	}
}

void gold() {
	for (int i = 3; i <= n / 2; i = i + 2) { //증가감소수정
		a = i;
		b = n - a;
		if (prime[a] && prime[b]) return;

		/*
		if(prime[a]){
			for (int j = n - a; j >= n / 2; j = j - 2) {
				b = j;
				if (a + b == n) {
					if (prime[b]) return;
				}
			}
		}
		*/
	}
}

int main() {
	as();
	while (true) {
		scanf("%d", &n);
		if (n == 0) return 0;
		a = b = 0;
		gold();
		if (a == 0 || b == 0) printf("Goldbach's conjecture is wrong.");
		else printf("%d = %d + %d\n", n, a, b);
	}
	return 0;
}