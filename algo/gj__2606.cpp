#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N;
int M;
bool map[110][110] = { false, };
bool visited[110] = { false, };
int virus = -1;

queue<int> q;
vector<int> v;

void dfs(int start) {
	if (visited[start]) return;
	visited[start] = true;
	v.push_back(start);
	for (int i = 1; i <= N; i++) {
		if (!map[start][i]) continue;
		map[start][i] = false;
		map[i][start] = false;
		dfs(i);
	}
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int first, second;
		scanf("%d %d", &first, &second);
		map[first][second] = true;
		map[second][first] = true;
	}
	dfs(1);
	printf("%d", v.size());
}