#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)
int N;

int main() {
	scanf("%d", &N);
	int jinN = N;
	int cnt = 0;
	while (true) {
		if (N % 5 != 0) {
			N -= 3;
			cnt++;
		}
		else {
			cnt += N / 5;
			break;
		}
	}
	if (N < 0) {
		cnt = -1;
	}
	printf("%d", cnt);
}