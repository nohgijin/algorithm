#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

class Item {
public:
	int number;
	int depth;
};

int n, m;
bool input[510][510] = { false, };
bool visited[510] = { false, };
int cnt = 0;

void dfs(int start, int depth) {
	if (!visited[start]) {
		visited[start] = true;
		cnt++;
	}

	if (depth == 2) return;

	for (int i = 1; i <= n; i++) {
		if (!input[start][i]) continue;
		dfs(i, depth + 1);
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

	dfs(1, 0);
	printf("%d", cnt - 1);
}