#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int input[60][60];
int copy_input[60][60];
int N, M;
int vs;

class Case {
public:
	int y;
	int x;
	int time = 0;
};

vector<Case> v;
vector<Case> virus;
bool dfsVisited[14] = { false, };
int result = INT_MAX;
// 벽 1 빈공간 0 바이러스 -1 

void bfs() {
	int tmpResult;
	bool all = true;
	bool bfsVisited[60][60] = { false, };
	queue<Case> Q;
	int vvs = virus.size();
	for (int i = 0; i < vvs; i++) {
		Q.push({ virus[i].y,virus[i].x });
	}

	while (!Q.empty()) {
		Case C = Q.front();
		Q.pop();
		if (C.y <= 0 || C.x <= 0 || C.y > N || C.x > N) continue;
		if (copy_input[C.y][C.x] == 1) continue;
		if (bfsVisited[C.y][C.x]) continue;
		bfsVisited[C.y][C.x] = true;
		tmpResult = C.time;
		copy_input[C.y][C.x] = -1;
		Q.push({ C.y + 1,C.x,C.time + 1 });
		Q.push({ C.y - 1,C.x,C.time + 1 });
		Q.push({ C.y ,C.x + 1,C.time + 1 });
		Q.push({ C.y ,C.x - 1,C.time + 1 });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (copy_input[i][j] == 0) {
				all = false; //빈공간있음, 바이러스안퍼짐
				break;
			}
		}
	}

	if (all) result = min(result, tmpResult);
}

void change() {
	virus.clear();
	for (int i = 0; i < vs; i++) {
		if (dfsVisited[i]) {
			//바이러스 대상자일경우
			copy_input[v[i].y][v[i].x] = -1;
			virus.push_back({ v[i].y,v[i].x });
		}
		else {
			//바이러스 대상자 아닐경우
			copy_input[v[i].y][v[i].x] = 0;
		}
	}
	bfs();
}

void dfs(int start, int depth) {
	if (dfsVisited[start]) return;
	dfsVisited[start] = true;

	if (depth != M) {
		for (int i = start; i < vs; i++) {
			if (dfsVisited[i]) continue;
			dfs(i, depth + 1);
		}
	}

	//가능한공간조합 나오면 그 조합을 바이러스(-1)로 바꾸기
	else change();
	memcpy(copy_input, input, sizeof(input));
	dfsVisited[start] = false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}

	vs = v.size();
	memcpy(copy_input, input, sizeof(input));

	//가능한공간 조합 dfs
	for (int i = 0; i < vs; i++) {
		dfs(i, 1);
	}

	if (result == INT_MAX) result = -1;
	printf("%d", result);
}