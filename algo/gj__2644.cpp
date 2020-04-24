#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int person1, person2;
bool map[110][110] = { false, };
bool visited[110][110] = { false, };
bool visited2[110] = { false, };

int cnt = INT_MAX;

void dfs2(int bfr, int depth) {
	if (bfr == person2) {
		cnt = cnt > depth ? depth : cnt;
		return;
	}
	if (visited2[bfr]) return;
	visited2[bfr] = true;
	for (int i = 1; i <= n; i++) {
		if (!map[bfr][i]) continue;
		dfs2(i, depth + 1);
	}
	visited2[bfr] = false;
}

int main() {
	scanf("%d", &n);
	scanf("%d %d", &person1, &person2);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		map[t1][t2] = true;
		map[t2][t1] = true;
	}

	dfs2(person1, 0);

	if (cnt == INT_MAX) cnt = -1;
	printf("%d", cnt);
}