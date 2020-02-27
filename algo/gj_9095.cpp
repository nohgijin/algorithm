#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int T;
int n;
int cnt;
int sum;

void bang(int sum) {
	if (sum == 0) {
		cnt++;
		return;
	}

	for (int i = 1; i <= sum; i++) {
		if (i > 3) break;
		bang(sum - i);
	}
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		cnt = 0;
		sum = 0;
		scanf("%d", &n);
		bang(n);
		printf("%d\n", cnt);
	}
}