#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, M;
vector<int> input;
vector<int> v;
bool visited[10100] = { false, };

void printvec() {
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void dfs(int start, int depth) {
	v.push_back(input[start]);
	visited[input[start]] = true;
	if (depth == M) {
		printvec();
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visited[input[i]]) continue;
			dfs(i, depth + 1);
		}
	}
	v.pop_back();
	visited[input[start]] = false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		input.push_back(t);
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < N; i++) {
		dfs(i, 1);
	}
}