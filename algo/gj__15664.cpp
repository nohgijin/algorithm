#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int N, M;
vector<int> input;
bool global_visited[10010] = { false, };
vector<int> v;

void printvec() {
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void dfs(int start, int depth) {
	bool local_visited[10010] = { false, };
	v.push_back(input[start]);
	//1
	global_visited[start] = true;
	if (depth == M) {
		printvec();
	}
	else {
		for (int i = start + 1; i < N; i++) {
			if (global_visited[i]) continue;
			if (local_visited[input[i]]) continue;
			local_visited[input[i]] = true;
			dfs(i, depth + 1);
		}
	}
	v.pop_back();
	global_visited[start] = false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		input.push_back(t);
	}
	sort(input.begin(), input.end());

	bool local_visited[10010] = { false, };
	for (int i = 0; i < N; i++) {
		//2
		if (local_visited[input[i]]) continue;
		local_visited[input[i]] = true;
		dfs(i, 1);
	}
}