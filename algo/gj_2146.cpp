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

class Case {
public:
	int y;
	int x;
	int cnt = 0;
};

int N;
int input[110][110];
int visited[110][110] = { 0, };
int searchVisited[110][110] = { 0, };
queue<Case> v[10010];

void show() {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf(" %2d", visited[i][j]);
		}
		printf("\n");
	}
}

void dfs(int y, int x, int value) { //섬구분함수
	if (y <= 0 || x <= 0 || y > N || x > N) return;
	if (!input[y][x]) return;
	if (visited[y][x]) return;
	visited[y][x] = value;

	//안쪽에 있는것은 제외

	if (!input[y][x + 1] || !input[y][x - 1] || !input[y + 1][x] || !input[y - 1][x]) {
		v[value].push({ y,x });
		//printf("%d %d\n", y, x);
	}

	dfs(y + 1, x, value);
	dfs(y - 1, x, value);
	dfs(y, x + 1, value);
	dfs(y, x - 1, value);
}

int bfs(int idx) {
	bool bfsVisited[110][110] = { false, };
	while (!v[idx].empty()) {
		Case C = v[idx].front();
		v[idx].pop();
		if (C.y <= 0 || C.x <= 0 || C.y > N || C.x > N) continue;
		if (bfsVisited[C.y][C.x]) continue;
		bfsVisited[C.y][C.x] = true;
		if (visited[C.y][C.x] != idx && visited[C.y][C.x] != 0) {
			while (!v[idx].empty()) v[idx].pop();
			return C.cnt;
		}
		v[idx].push({ C.y + 1,C.x,C.cnt + 1 });
		v[idx].push({ C.y - 1,C.x,C.cnt + 1 });
		v[idx].push({ C.y,C.x + 1,C.cnt + 1 });
		v[idx].push({ C.y,C.x - 1,C.cnt + 1 });
	}
}

int main() {
	int value = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input[i][j]);
		}
	}


	//섬구분
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) continue;
			if (!input[i][j]) continue;
			value++;
			dfs(i, j, value);
			//printf("\n");
		}
	}

	//	show();


	int answer = INT_MAX;

	for (int i = 1; i <= value; i++) {
		answer = min(answer, bfs(i));
	}

	printf("%d", answer - 1);

	//	show();
}