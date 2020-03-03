include <iostream>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

int N;
int result = 0;
int tmp;

void eao(int N) {
	int cnt = 0;
	int tmp = N;
	while (tmp) { //자리수 구함
		tmp /= 10;
		cnt++;
		if (tmp < 1) break;
	}
	int jincnt = cnt; //자리수 저장

	int i = 1;
	if (cnt == 1) {
		result = N;
		return;
	}
	while (cnt) {
		result += i * 9 * pow(10, i - 1);
		i++;
		cnt--;
		if (cnt <= 1) break;
	}

	result += (N - pow(10, jincnt - 1) + 1)*jincnt;
}

int main() {
	scanf("%d", &N);
	eao(N);
	printf("%d", result);
}