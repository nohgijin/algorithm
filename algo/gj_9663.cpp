#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;
#pragma warning(disable:4996)

int N;
bool visited[20][20] = { false, };
bool avail = true;
int answer = 0;

class Case {
public:
	int y;
	int x;
};

void show() {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}

void fill(int y, int x, int dy, int dx) {
	if (y <= 0 || x <= 0 || y > N || x > N) return;
	visited[y + dy][x + dx] = true;
	fill(y + dy, x + dx, dy, dx);
}

void dfs(int y) {
	if (y == N + 1) {
		answer++;
		return;
	}

	bool copy_visited[20][20] = { false, };
	memcpy(copy_visited, visited, sizeof(visited));

	for (int x = 1; x <= N; x++) {
		if (visited[y][x]) continue;
		visited[y][x] = true;

		fill(y, x, 1, 0);
		fill(y, x, 1, -1);
		fill(y, x, 1, 1);
		fill(y, x, -1, 0);
		fill(y, x, -1, -1);
		fill(y, x, -1, 1);
		fill(y, x, 0, 1);
		fill(y, x, 0, -1);

		dfs(y + 1);
		visited[y][x] = false;
		memcpy(visited, copy_visited, sizeof(copy_visited));
	}
}

int main() {
	//int answer = 0;
	scanf("%d", &N);
	dfs(1);
	printf("%d", answer);
}