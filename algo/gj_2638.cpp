#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

using namespace std;

class Case {
public:
	int y;
	int x;
};

int N, M;
int input[110][110];
bool visited[110][110] = { false, };

vector<Case> cheese;

void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%2d ", input[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void dfs(int y, int x) {
	if (input[y][x] == 1 || input[y][x] == 2) return;
	if (y <= 0 || x <= 0 || y > N || x > M) return;
	if (visited[y][x]) return;
	visited[y][x] = true;
	input[y][x] = -1;
	dfs(y + 1, x);
	dfs(y - 1, x);
	dfs(y, x + 1);
	dfs(y, x - 1);
}

//진짜공기-1
//가짜공기0
//치즈1
//구멍치즈2

int connectCheck(int y, int x) {
	int cnt = 0;
	if (input[y - 1][x] == -1) cnt++;
	if (input[y + 1][x] == -1) cnt++;
	if (input[y][x - 1] == -1) cnt++;
	if (input[y][x + 1] == -1) cnt++;
	return cnt;
}

void cheeseChange() {
	//치즈 바꿔줌
	int cs = cheese.size();
	for (int i = 0; i < cs; i++) {
		if (connectCheck(cheese[i].y, cheese[i].x) >= 2) {
			input[cheese[i].y][cheese[i].x] = 2;
		}
	}
}

void melt() {
	//구멍치즈 진짜공기로 만들고 새치즈 넣음
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] == 2) input[i][j] = -1;
			else if (input[i][j] == 1) {
				cheese.push_back({ i,j });
			}
		}
	}
}

int main() {
	int time = 0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] == 1) cheese.push_back({ i,j });
		}
	}

	while (!cheese.empty()) {
		memset(visited, false, sizeof(visited));
		time++;
		dfs(1, 1);//공기유무파악
		cheeseChange();//닿는면적2이상이면 치즈를 구멍치즈로 변경
		//show();//보여줌
		cheese.clear();//치즈초기화해줌
		melt();//구멍치즈 녹임
	}

	printf("%d", time);
}