#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int N;
int input[60];
vector<int> child[60];
int target;
int cnt = 0;

void dfs(int root) {
	if (!child[root].empty()) {
		int rs = child[root].size();
		for (int i = 0; i < rs; i++) {
			dfs(child[root][i]);
		}
	}
	else {
		cnt++;
	}
}

int main() {
	int root;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
		if (input[i] == -1) root = i;
	}
	scanf("%d", &target);
	if (input[target] != -1) {
		for (int i = 0; i < N; i++) {
			if (i == root) continue;
			if (target == i) continue;
			child[input[i]].push_back(i);
		}
		dfs(root);
	}
	printf("%d", cnt);
}