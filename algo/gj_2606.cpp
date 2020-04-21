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

void bfs() {
	q.push(1);
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (visited[p]) continue;
		visited[p] = true;
		virus++;
		for (int i = 1; i <= N; i++) {
			if (map[p][i]) {
				q.push(i);
				map[p][i] = false;
				map[i][p] = false;
			}
		}
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
	bfs();
	printf("%d", virus);
}