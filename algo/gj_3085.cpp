#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int N;
char input[51][51];
int cnt = 0;
int nmax = 0;

void check() {
	for (int i = 0; i < N; i++) { //가로체크
		for (int j = 0; j < N; j++) {
			cnt = 1;
			while (input[i][j] == input[i][j + 1]) {
				cnt++;
				j++;
				if (j >= N) break;
			}
			nmax = nmax > cnt ? nmax : cnt;
		}
	}

	for (int j = 0; j < N; j++) { //세로체크
		for (int i = 0; i < N; i++) {
			cnt = 1;
			while (input[i][j] == input[i + 1][j]) {
				cnt++;
				i++;
				if (i >= N) break;
			}
			nmax = nmax > cnt ? nmax : cnt;
		}
	}
}

void saero(int i) {
	for (int j = 0; j < N - 1; j++) {
		char tmp = input[i][j];
		input[i][j] = input[i + 1][j];
		input[i + 1][j] = tmp;
		check();
		input[i + 1][j] = input[i][j];
		input[i][j] = tmp;
	}
	if (i + 1 < N) saero(i + 1);
}

void garo(int i) {
	for (int j = 0; j < N - 1; j++) {
		char tmp = input[i][j];
		input[i][j] = input[i][j + 1];
		input[i][j + 1] = tmp;
		check();
		input[i][j + 1] = input[i][j];
		input[i][j] = tmp;
	}
	if (i + 1 < N) garo(i + 1);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &input[i][j]);
		}
	}
	garo(0);
	saero(0);
	printf("%d", nmax);
}
