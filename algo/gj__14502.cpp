#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, M;
int input[10][10];
int copy_input[10][10];
bool visited[10][10] = { false, };

class Case {
public:
	int y;
	int x;
};

vector<Case> zero;
vector<Case> wall;
queue<Case> virus;



int result = 0;

void show() {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%d ", copy_input[i][j]);
		}
		printf("\n");
	}
}

void check() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (copy_input[i][j] == 0) {
				cnt++;
			}
		}
	}
	result = max(result, cnt);
}

void bfs() {
	bool bfsvisited[10][10] = { false, };
	memcpy(copy_input, input, sizeof(input));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] == 2) virus.push({ i,j });
		}
	}

	while (!virus.empty()) {
		Case C = virus.front();
		virus.pop();
		if (C.y <= 0 || C.x <= 0 || C.y > N || C.x > M) continue;
		if (input[C.y][C.x] == 1) continue;
		if (bfsvisited[C.y][C.x]) continue;
		bfsvisited[C.y][C.x] = true;
		copy_input[C.y][C.x] = 2;
		virus.push({ C.y + 1,C.x });
		virus.push({ C.y - 1,C.x });
		virus.push({ C.y ,C.x + 1 });
		virus.push({ C.y ,C.x - 1 });
	}
	check();
}

void makeWall(int y, int depth) {
	for (int i = y; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] != 0) continue;
			if (visited[i][j]) continue;
			visited[i][j] = true;
			input[i][j] = 1;

			// 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
			if (depth == 3) {
				bfs();
			}
			else {
				makeWall(i, depth + 1);
			}

			visited[i][j] = false;
			input[i][j] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	makeWall(1, 1);

	printf("%d", result);
	return 0;
}