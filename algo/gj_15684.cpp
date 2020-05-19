#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, M, H;
bool input[50][50][50] = { false, };
bool checkVisited[50][50] = { false, };
int last;
int mini = 3;
bool once = false;

void check(int y, int x) {
	if (y == H + 1) {
		last = x;
		return;
	}
	checkVisited[y][x] = true;
	if (input[y][x][x + 1]) {
		if (checkVisited[y][x + 1]) {
			check(y + 1, x);
			return;
		}
		else {
			check(y, x + 1);
			return;
		}
	}
	else if (input[y][x][x - 1]) {
		if (checkVisited[y][x - 1]) {
			check(y + 1, x);
			return;
		}
		else {
			check(y, x - 1);
			return;
		}
	}
	else {
		check(y + 1, x);
		return;
	}
}

bool isConnect(int y, int x) {
	if (input[y][x][x + 1]) return true;
	if (input[y][x][x - 1]) return true;
	return false;
}

void insert(int y, int depth) {
	for (int i = y; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (isConnect(i, j) || isConnect(i, j + 1)) continue;

			input[i][j][j + 1] = true;
			input[i][j + 1][j] = true;

			int cnt = 0;
			for (int p = 1; p <= N; p++) {
				memset(checkVisited, false, sizeof(checkVisited));
				check(1, p);
				if (last == p) cnt++;
				else break;
			}
			if (cnt == N) {
				once = true;
				mini = mini > depth ? depth : mini;
			}

			if (depth != 3) insert(i, depth + 1);

			input[i][j][j + 1] = false;
			input[i][j + 1][j] = false;

		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		input[a][b][b + 1] = true;
		input[a][b + 1][b] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		memset(checkVisited, false, sizeof(checkVisited));
		check(1, i);
		if (last == i) cnt++;
		else break;
	}

	if (cnt == N) {
		printf("0\n");
	}
	else {
		insert(1, 1);
		if (once) {
			printf("%d\n", mini);
		}
		else {
			printf("-1\n");
		}
	}

}