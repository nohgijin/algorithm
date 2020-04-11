#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
#pragma warning(disable:4996)

int N;
int M;
map<int, int> m;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		long long tmp;
		scanf("%d", &tmp);
		m[tmp] = tmp;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (m[tmp]) printf("1\n");
		else printf("0\n");
	}
}