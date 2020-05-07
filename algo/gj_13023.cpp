#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, M;
bool visited[2100] = { false, };
vector<int> v[2100];
int cnt = 0;
int result = 0;

void dfs(int start, int depth) {
	if (depth == 4) {
		cnt = 4;
		return;
	}
	int vs = v[start].size();
	for (int i = 0; i < vs; i++) {
		if (visited[v[start][i]]) continue;
		visited[v[start][i]] = true;
		dfs(v[start][i], depth + 1);
		visited[v[start][i]] = false;
		if (cnt == 4) break;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	for (int i = 0; i < N; i++) {
		visited[i] = true;
		dfs(i, 0);
		if (cnt == 4) {
			result = 1;
			break;
		}
		visited[i] = false;
	}
	printf("%d", result);
}