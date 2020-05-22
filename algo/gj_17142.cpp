#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

class Case {
public:
	int y;
	int x;
	int time = 1;
};

int N, M;
int input[55][55];
int copy_input[55][55];
bool dfsVisited[15] = { false, };
vector<Case> v;
int vs;
int jinResult = INT_MAX;
queue<Case> virus;

//벽-1 활성-2 비활성-3

void findMax() {
	int result = INT_MIN;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result = max(result, copy_input[i][j]);
		}
	}
	jinResult = min(jinResult, result - 1);
}

bool zero() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (copy_input[i][j] == 0) return false;
		}
	}
	return true;
}

void bfs() {
	int tmpResult;
	bool bfsVisited[55][55] = { false, };

	while (!virus.empty()) {
		Case C = virus.front();
		virus.pop();
		if (C.y <= 0 || C.x <= 0 || C.y > N || C.x > N) continue;
		if (copy_input[C.y][C.x] == -1) continue;
		if (bfsVisited[C.y][C.x]) continue;
		bfsVisited[C.y][C.x] = true;
		if (copy_input[C.y][C.x] != -3) copy_input[C.y][C.x] = C.time;
		virus.push({ C.y + 1,C.x,C.time + 1 });
		virus.push({ C.y - 1,C.x,C.time + 1 });
		virus.push({ C.y,C.x + 1,C.time + 1 });
		virus.push({ C.y,C.x - 1,C.time + 1 });
	}
	if (zero()) findMax();
}

void power() {
	for (int i = 0; i < vs; i++) {
		if (dfsVisited[i]) { //활성 -2
			copy_input[v[i].y][v[i].x] = -2;
			virus.push({ v[i].y, v[i].x });
		}
		else { //비활성 -3
			copy_input[v[i].y][v[i].x] = -3;
		}
	}
	//show();
	bfs();
}

void dfs(int start, int depth) {
	if (dfsVisited[start]) return;
	dfsVisited[start] = true;

	if (depth != M) {
		for (int i = start + 1; i < vs; i++) {
			if (dfsVisited[i]) continue;
			dfs(i, depth + 1);
		}
	}

	else power();
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
			else if (input[i][j] == 1) {
				input[i][j] = -1;
			}
		}
	}

	memcpy(copy_input, input, sizeof(input));

	vs = v.size();
	for (int i = 0; i < vs; i++) {
		dfs(i, 1);
	}

	if (jinResult == INT_MAX) jinResult = -1;
	printf("%d", jinResult);
}