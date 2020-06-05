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

int K;
int W, H;
int input[210][210];

class Case {
public:
	int y;
	int x;
	int cnt = 0;
	int horse;

};

void show() {
	printf("\n");
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			printf("%d ", input[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int bfs() {
	bool visited[210][210][35] = { false, };
	queue<Case> Q;
	Q.push({ 1,1,0,K });
	while (!Q.empty()) {
		Case C = Q.front();
		Q.pop();
		if (C.y <= 0 || C.x <= 0 || C.y > H || C.x > W) continue;
		if (input[C.y][C.x]) continue;
		if (C.y == H && C.x == W) return C.cnt;
		if (visited[C.y][C.x][C.horse]) continue;
		visited[C.y][C.x][C.horse] = true;
		Q.push({ C.y + 1,C.x,C.cnt + 1,C.horse });
		Q.push({ C.y - 1,C.x,C.cnt + 1,C.horse });
		Q.push({ C.y,C.x + 1,C.cnt + 1,C.horse });
		Q.push({ C.y,C.x - 1,C.cnt + 1,C.horse });
		if (C.horse > 0) {
			Q.push({ C.y - 1,C.x - 2,C.cnt + 1,C.horse - 1 });
			Q.push({ C.y - 2,C.x - 1,C.cnt + 1,C.horse - 1 });
			Q.push({ C.y - 1,C.x + 2,C.cnt + 1,C.horse - 1 });
			Q.push({ C.y - 2,C.x + 1,C.cnt + 1,C.horse - 1 });
			Q.push({ C.y + 1,C.x - 2,C.cnt + 1,C.horse - 1 });
			Q.push({ C.y + 2,C.x - 1,C.cnt + 1,C.horse - 1 });
			Q.push({ C.y + 1,C.x + 2,C.cnt + 1,C.horse - 1 });
			Q.push({ C.y + 2,C.x + 1,C.cnt + 1,C.horse - 1 });
		}
	}
	return -1;
}

int main() {
	scanf("%d", &K);
	scanf("%d %d", &W, &H);
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	printf("%d", bfs());
	//	show();
}