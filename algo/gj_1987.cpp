#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int R, C;
char input[25][25];
bool visited[200] = { false, };
int cnt = 0;
vector<char> v;

void check() {
	cnt = cnt > v.size() ? cnt : v.size();
}

void dfs(int y, int x) {
	if (y <= 0 || x <= 0 || y > R || x > C) return;
	if (visited[input[y][x]]) return;
	visited[input[y][x]] = true;
	v.push_back(input[y][x]);
	dfs(y + 1, x);
	dfs(y - 1, x);
	dfs(y, x + 1);
	dfs(y, x - 1);
	check();
	visited[input[y][x]] = false;
	v.pop_back();
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		scanf("%s", &input[i][1]);
	}
	dfs(1, 1);
	printf("%d", cnt);
}