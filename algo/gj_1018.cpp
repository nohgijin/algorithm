#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#pragma warning( disable : 4996 )

using namespace std;

int N, M;
char chess[10][10];
char input[51][51];

int re(char bfr, int i, int j) {
	int sum = 0;
	for (int p = i; p < i + 8; p++) {
		for (int q = j; q < j + 8; q++) {

			if (q == j) {
				if (bfr != input[p][q]) {
					sum++;
					continue;
				}
			}

			else {
				if (bfr == input[p][q]) {
					sum++;
					bfr = (bfr == 'W') ? 'B' : 'W';
					continue;
				}
				bfr = input[p][q];
			}
		}
	}
	return sum;
}

int main() {
	char ch;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", input[i]);
	}
	int minre = 2500;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			minre = min(minre, re('W', i, j));
			minre = min(minre, re('B', i, j));
		}
	}

	printf("%d", minre);
}