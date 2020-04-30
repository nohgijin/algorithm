#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int input[6][6];
char num[6];
int cnt = 0;
map<string, int> m;

void dfs(int y, int x, int depth) {
	if (depth == 6) {
		if (m[num]) return;
		m[num] = 1;
		cnt++;
		return;
	}
	if (y <= 0 || x <= 0 || y > 5 || x > 5) return;
	num[depth] = input[y][x] + '0';
	dfs(y + 1, x, depth + 1);
	dfs(y - 1, x, depth + 1);
	dfs(y, x + 1, depth + 1);
	dfs(y, x - 1, depth + 1);
}

int main() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			dfs(j, i, 0);
		}
	}
	printf("%d", cnt);
}