#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int n, m;
bool input[510][510] = { false, };
bool visited[510] = { false, };
vector<int> v;

void bfs() {
	queue<int> q;

	visited[1] = true;

	for (int i = 1; i <= n; i++) {
		if (!input[1][i]) continue;
		visited[i] = true;
		q.push(i);
		v.push_back(i);
	}

	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (!input[p][i]) continue;
			if (visited[i]) continue;
			visited[i] = true;
			v.push_back(i);
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		input[t1][t2] = true;
		input[t2][t1] = true;
	}

	bfs();

	printf("%d", v.size());
}