#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int N, M;
vector<int> v;
bool visited[10] = { false, };

void printvec() {
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void dfs(int start, int depth) {
	v.push_back(start);
	visited[start] = true;
	if (depth == M) {
		printvec();
	}
	else {
		for (int i = start + 1; i <= N; i++) {
			if (visited[i]) continue;
			dfs(i, depth + 1);
		}
	}
	v.pop_back();
	visited[start] = false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		dfs(i, 1);
	}
}