#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#pragma warning( disable : 4996 )

int N;
int A[60];
int B[60];

int main(void) {
	int result = 0;
	int q;
	int maxB;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	sort(A, A + N);

	for (int k = 0; k < N; k++) {
		maxB = -1;
		for (int p = 0; p < N; p++)
		{
			if (maxB <= B[p]) {
				maxB = B[p];
				q = p;
			}
		}
		B[q] = -1;
		result += A[k] * maxB;
	}

	printf("%d", result);


	return 0;
}