#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
int N;
queue<char *> q;

int main() {
	scanf("%d", &N);
	bool suc = false;
	int K = -1;

	for (int i = 0; i < 10; i++) {
		char *str = new char[3];
		str[0] = i + '0';
		str[1] = '\0';
		q.push(str);
		K++;
		if (K == N) {
			suc = true;
			printf("%s", str);
		}
	}

	while (!q.empty() && !suc) {
		char *str = q.front();
		q.pop();
		int len = strlen(str);
		int tmp = str[len - 1] - '0';
		for (int i = 0; i < tmp; i++) {
			char *n = new char[len + 2];
			strcpy(n, str);
			n[len] = i + '0';
			n[len + 1] = '\0';
			q.push(n);
			K++;
			if (K == N) {
				suc = true;
				printf("%s", n);
			}
		}
		delete str;
	}
	if (!suc) printf("-1");
}