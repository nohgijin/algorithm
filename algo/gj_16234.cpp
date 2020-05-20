#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, L, R;
int input[60][60];
int visited[60][60] = { 0, };

class Pos {
public:
	int y;
	int x;
};

vector<Pos> p[2600];


void showVisited() {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", input[i][j]);
		}
		printf("\n");
	}
}

void showInput() {

	printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}


void diff(int y, int x, int depth) {
	if (y <= 0 || x <= 0 || y > N || x > N) return;
	if (visited[y][x]) return;
	visited[y][x] = depth;
	p[depth].push_back({ y,x });

	int cur = input[y][x];
	int right = input[y][x + 1];
	int under = input[y + 1][x];
	int left = input[y][x - 1];
	int up = input[y - 1][x];
	if (abs(right - cur) >= L && abs(right - cur) <= R) diff(y, x + 1, depth);
	if (abs(under - cur) >= L && abs(under - cur) <= R) diff(y + 1, x, depth);
	if (abs(left - cur) >= L && abs(left - cur) <= R) diff(y, x - 1, depth);
	if (abs(up - cur) >= L && abs(up - cur) <= R) diff(y - 1, x, depth);
}

bool isEnd() {
	int com = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] == com) {
				com++;
				continue;
			}
			else return false;
		}
	}
	return true;
}

void cal(int value) {
	//	vector<Pos> p[2600]; value, y, x
	int total = 0;
	int num = 0;
	int ps = p[value].size();
	if (ps == 1) return;

	for (int i = 0; i < ps; i++) {
		int y = p[value][i].y;
		int x = p[value][i].x;

		total += input[y][x];
		num++;
	}

	int avg = total / num;

	for (int i = 0; i < ps; i++) {
		int y = p[value][i].y;
		int x = p[value][i].x;
		input[y][x] = avg;
	}
}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	int result = 0;
	int bfrdepth = 0;

	while (true) {
		int depth = 1;
		for (int i = 0; i <= bfrdepth; i++) p[i].clear();
		memset(visited, 0, sizeof(visited));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visited[i][j]) continue;
				diff(i, j, depth);
				depth++;
			}
		}

		for (int i = 1; i < depth; i++) cal(i);

		bfrdepth = depth;
		if (isEnd()) break;
		result++;
	}

	printf("%d", result);
}