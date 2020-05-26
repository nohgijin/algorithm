#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

using namespace std;
int N, M;
int input[110][110] = { 0, };

bool visited[110][110] = { false, };


class Cheese {
public:
	int y;
	int x;
};

vector<Cheese> v;
int lastChz = 0;

void show() {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%2d ", input[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool holeCheese(int y, int x) {
	if (input[y + 1][x] == -1 || input[y - 1][x] == -1 || input[y][x + 1] == -1 || input[y][x - 1] == -1) return true;
	return false;
}

void checkCheese() {
	lastChz = 0;
	v.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] == 1) v.push_back({ i,j });
		}
	}

	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		if (holeCheese(v[i].y, v[i].x)) {
			lastChz++;
			input[v[i].y][v[i].x] = 2;
		}
	}
}

bool isCheese() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] == 1) return true;
		}
	}
	return false;
}

void dfs(int y, int x) {
	if (y <= 0 || x <= 0 || y > N || x > M) return;
	if (input[y][x] == 1 || input[y][x] == 2) return;
	if (visited[y][x]) return;
	visited[y][x] = true;
	input[y][x] = -1;
	dfs(y + 1, x);
	dfs(y - 1, x);
	dfs(y, x + 1);
	dfs(y, x - 1);
}

void replaceCheese() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] == 2) input[i][j] = -1;
		}
	}
}


//바깥공기 -1 
//안공기 0
//치즈 1
//구멍치즈 2

int main() {
	int sec = 0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	input[1][1] = -1;

	while (isCheese()) {
		sec++;
		memset(visited, 0, sizeof(visited));
		replaceCheese();
		dfs(1, 1);
		checkCheese();
		//show();
	}

	printf("%d\n%d", sec, lastChz);
}