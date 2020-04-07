#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int N, M;
vector <int> a;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	for (int j = 0; j < M; j++) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	int sz = a.size();
	for (int i = 0; i < sz; i++) {
		printf("%d ", a[i]);
	}
}