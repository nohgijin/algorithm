#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)


int N;
vector<char*> dp;
queue<char*> q;


int main() {

	int K = 0;

	scanf("%d", &N);

	bool suc = false;

	for (int i = 0; i <= 9; i++) {
		char *str = new char[3];
		str[0] = i + '0';
		str[1] = '\0';
		q.push(str);
		K++;
		if (N == K) {
			suc = true;
			printf("%s", str);
		}
	}


	while (!q.empty() && !suc) {
		char *str = q.front();
		q.pop();
		int len = strlen(str);
		int last = str[len - 1];
		for (int i = 0; i < last - '0'; i++) {
			char *n = new char[len + 2];
			strcpy(n, str);
			n[len] = i + '0';
			n[len + 1] = '\0';
			q.push(n);
			K++;
			if (N == K) {
				suc = true;
				printf("%s", n);
			}
		}
		delete str;
	}

	if (!suc) printf("-1");
}