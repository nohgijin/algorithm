#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int N, M, V;
bool visited[1010] = { false, };
bool ganseon[1010][1010] = { false, };
vector<int> v;
vector<int> track;
queue<int> q;
int mini;

void dfs(int start) {
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		if (ganseon[start][i]) {
			visited[i] = true;
			v.push_back(i);
			dfs(i);
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (visited[num]) continue;
		visited[num] = true;
		track.push_back(num);
		for (int i = 1; i <= N; i++) {
			if (ganseon[num][i]) {
				if (visited[i]) continue;
				q.push(i);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ganseon[a][b] = true;
		ganseon[b][a] = true;
	}

	// DFS
	v.push_back(V);
	visited[V] = true;
	dfs(V);

	memset(visited, false, 1010);

	// BFS
	q.push(V);
	bfs();

	int vs = v.size();
	for (int i = 0; i < vs; i++) printf("%d ", v[i]);
	printf("\n");
	int ts = track.size();
	for (int i = 0; i < ts; i++) printf("%d ", track[i]);
}