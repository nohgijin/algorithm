#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#pragma warning(disable:4996)

int N, M;
int u, v;
int input[1010][1010];
bool visited[1010] = { 0, };
int start, root;
int cnt = 0;

void connect(int start) {
	visited[start] = true;
	for (int i = 1; i <= N; i++) {
		if (input[start][i]) {
			if (visited[i]) continue;
			connect(i);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		input[u][v] = 1;
		input[v][u] = 1;
	}

	for (int i = 1; i <= N; i++) {
		root = i;
		if (visited[root]) continue;
		cnt++;
		connect(root);
	}

	printf("%d", cnt);
}