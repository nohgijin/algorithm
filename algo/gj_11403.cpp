#include <iostream>
#include <stdio.h>

using namespace std;
#pragma warning(disable:4996)

int input[110][110];
int output[110][110];

int N;
int root;

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", output[i][j]);
		}
		printf("\n");
	}
}

void path(int start) {
	for (int i = 1; i <= N; i++) {
		if (output[root][i] == 1) continue;
		if (input[start][i] == 1) {
			output[root][i] = 1;
			path(i);
		}
	}
}



int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			scanf("%d", &tmp);
			input[i][j] = tmp;
		}
	}
	for (int i = 1; i <= N; i++) {
		root = i;
		path(i);
	}

	print();
}