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

int N, M, T;
int input[110][110];
bool visited[110][110] = { false, };

class Case {
public:
	int y;
	int x;
	int sec = 0;
};

Case G;

void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%2d", input[i][j]);
		}
		printf("\n");
	}
}

int direct() {
	queue<Case> Q;
	Q.push({ 1,1 });
	while (!Q.empty()) {
		Case C = Q.front();
		Q.pop();
		if (C.y == N && C.x == M) return C.sec;
		if (C.y <= 0 || C.x <= 0 || C.y > N || C.x > M) continue;
		if (input[C.y][C.x] == 1) continue;
		if (visited[C.y][C.x]) continue;
		visited[C.y][C.x] = true;
		Q.push({ C.y + 1,C.x,C.sec + 1 });
		Q.push({ C.y - 1,C.x,C.sec + 1 });
		Q.push({ C.y,C.x + 1,C.sec + 1 });
		Q.push({ C.y,C.x - 1,C.sec + 1 });
	}
	return 0;
}

int gram() {
	queue<Case> Q;
	Q.push({ 1,1 });
	while (!Q.empty()) {
		Case C = Q.front();
		Q.pop();
		if (input[C.y][C.x] == 2) {
			G = { C.y,C.x };
			return C.sec;
		}
		if (C.y <= 0 || C.x <= 0 || C.y > N || C.x > M) continue;
		if (input[C.y][C.x] == 1) continue;
		if (visited[C.y][C.x]) continue;
		visited[C.y][C.x] = true;
		Q.push({ C.y + 1,C.x,C.sec + 1 });
		Q.push({ C.y - 1,C.x,C.sec + 1 });
		Q.push({ C.y,C.x + 1,C.sec + 1 });
		Q.push({ C.y,C.x - 1,C.sec + 1 });
	}
	return 0;
}

int nondirect() {
	queue<Case> Q;
	Q.push({ G.y,G.x });
	while (!Q.empty()) {
		Case C = Q.front();
		Q.pop();
		if (C.y == N && C.x == M) return C.sec;
		if (C.y <= 0 || C.x <= 0 || C.y > N || C.x > M) continue;
		if (visited[C.y][C.x]) continue;
		visited[C.y][C.x] = true;
		Q.push({ C.y + 1,C.x,C.sec + 1 });
		Q.push({ C.y - 1,C.x,C.sec + 1 });
		Q.push({ C.y,C.x + 1,C.sec + 1 });
		Q.push({ C.y,C.x - 1,C.sec + 1 });
	}
	return 0;
}

int main() {
	int dir;
	int nondir;
	int nondirAndPrin;

	scanf("%d %d %d", &N, &M, &T);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	dir = direct();
	memset(visited, false, sizeof(visited));
	nondir = gram();
	memset(visited, false, sizeof(visited));
	if (dir) { //직접 공주에게 갈 수 있음
		if (nondir) {
			//검 가질 경우
			nondirAndPrin = nondir + nondirect();
			int result = min(nondirAndPrin, dir);
			if (result <= T) printf("%d", result);
			else printf("Fail");
		}
		else {
			//검못가짐
			if (dir <= T) printf("%d", dir);
			else printf("Fail");
		}
	}
	else {
		if (nondir) {
			//검 가질 경우
			nondirAndPrin = nondir + nondirect();
			if (nondirAndPrin <= T) printf("%d", nondirAndPrin);
			else printf("Fail");
		}
		else {
			printf("Fail");
		}
	}

}