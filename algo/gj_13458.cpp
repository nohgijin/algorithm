#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
typedef long long ll;

int N, B, C;

int A[1000100];
ll sub = 0;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d %d", &B, &C);
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] > 0) {
			sub += (int)ceil((double)A[i] / (double)C);
		}
	}
	printf("%lld", N + sub);

}