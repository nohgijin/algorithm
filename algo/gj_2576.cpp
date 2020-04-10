#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int n;
int sum = 0;
bool chk = false;
vector<int> v;

int main() {
	for (int i = 0; i < 7; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp % 2 != 0) {
			sum += tmp;
			v.push_back(tmp);
		}
	}
	if (sum != 0) {
		chk = true;
		sort(v.begin(), v.end());
		printf("%d\n", sum);
		printf("%d\n", v[0]);
	}
	if (!chk) printf("-1\n");
}