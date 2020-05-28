#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int N, M;
char input[260][260];
bool visited[260][260] = { false, };

class Case {
public:
	int y;
	int x;
};

queue<Case>Q;
vector<char>v;
int totalWolf = 0;
int totalSheep = 0;

void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%2c", input[i][j]);
		}
		printf("\n");
	}
}


void bfs(int y, int x) {
	int sheep = 0;
	int wolf = 0;
	Q.push({ y,x });
	while (!Q.empty()) {
		Case C = Q.front();
		Q.pop();
		if (C.y <= 0 || C.x <= 0 || C.y > N || C.x > M) continue;
		if (input[C.y][C.x] == '#') continue;
		if (visited[C.y][C.x]) continue;
		visited[C.y][C.x] = true;
		Q.push({ C.y + 1,C.x });
		Q.push({ C.y - 1,C.x });
		Q.push({ C.y,C.x + 1 });
		Q.push({ C.y,C.x - 1 });
		if (input[C.y][C.x] == 'v') wolf++;
		else if (input[C.y][C.x] == 'o') sheep++;
	}

	if (sheep > wolf) {
		totalSheep += sheep;
	}
	else totalWolf += wolf;
}


int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &input[i][1]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] != '#' && visited[i][j] == false) {
				v.clear();
				bfs(i, j);
			}
		}
	}

	printf("%d %d", totalSheep, totalWolf);

}