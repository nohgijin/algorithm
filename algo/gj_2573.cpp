#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

class Pos {
public:
	int y;
	int x;
};

int N, M;
int input[310][310] = { 0, };
int copy_input[310][310] = { 0, };
bool visited[310][310] = { false, };
int num = 0;

void check(int y, int x) {
	if (y <= 0 || x <= 0 || y > N || x > M) return;
	if (copy_input[y][x] == 0) num++;
}

void dec(int y, int x) {
	num = 0;

	check(y - 1, x); //범위 맞는지 체크
	check(y + 1, x);
	check(y, x - 1);
	check(y, x + 1);

	input[y][x] -= num;
	if (input[y][x] < 0) input[y][x] = 0;
}

void bfs(int y, int x) { //섬의 개수
	queue<Pos> Q;
	Q.push({ y, x });
	while (!Q.empty()) {
		Pos P = Q.front();
		Q.pop();
		if (P.y <= 0 || P.x <= 0 || P.y > N || P.x > M) continue;
		if (visited[P.y][P.x]) continue;
		visited[P.y][P.x] = true;
		if (input[P.y][P.x] == 0) continue;

		Q.push({ P.y + 1,P.x });
		Q.push({ P.y - 1,P.x });
		Q.push({ P.y,P.x + 1 });
		Q.push({ P.y,P.x - 1 });
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	memcpy(copy_input, input, sizeof(input));

	int y = 0;
	int cnt = 0;

	while (1) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (input[i][j]) dec(i, j);
			}
		} //감소시킴
		y++; //년수 증가
		memcpy(copy_input, input, sizeof(input)); //input변경하면 같은 년도에 영향받으므로 복사본 만듬
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (visited[i][j]) continue;
				if (input[i][j]) {
					bfs(i, j); //bfs로 섬개수 구함
					cnt++;
				}
			}
		}
		if (cnt >= 2) break;
		//모두다 0(1->1->1->...->0도 포함)
		if (cnt == 0) {
			y = 0;
			break;
		}
	}

	printf("%d", y);
}