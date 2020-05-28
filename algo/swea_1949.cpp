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

int T;
int N, K;
int input[10][10] = { 0, };
bool visited[10][10] = { false, };
class Case {
public:
	int y;
	int x;
	Case(int y, int x) {
		this->x = x;
		this->y = y;
	}
};

vector<Case>v; //최대봉오리 좌표가 들어감

int dfsResult = 0;


void dfs(int y, int x, int bfr, int cnt) {
	if (input[y][x] >= bfr) return;
	if (y > N || x > N || y <= 0 || x <= 0) return;
	if (visited[y][x]) return;
	visited[y][x] = true;
	dfsResult = max(dfsResult, cnt);
	dfs(y + 1, x, input[y][x], cnt + 1);
	dfs(y - 1, x, input[y][x], cnt + 1);
	dfs(y, x + 1, input[y][x], cnt + 1);
	dfs(y, x - 1, input[y][x], cnt + 1);
	visited[y][x] = false;
}

void find() {
	v.clear();
	int findMaxi = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (findMaxi < input[i][j]) {
				findMaxi = input[i][j];
				v.clear();
				v.push_back(Case(i, j)); //최대 봉오리들을 다 넣어놓음
			}
			else if (findMaxi == input[i][j]) {
				v.push_back(Case(i, j));
			}
		}
	}
}

int cut() {
	int maxi = 0;
	find();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int stand = K;
			while (stand) { //자를수 있을때까지 돌기
				input[i][j]--; //자르기
				stand--;
				int vs = v.size();
				for (int i = 0; i < vs; i++) {
					dfsResult = 0;
					memset(visited, false, sizeof(visited));
					dfs(v[i].y, v[i].x, input[v[i].y][v[i].x] + 1, 1); //자른거에 대해 dfs돌기(큰 봉오리마다)
					maxi = max(maxi, dfsResult);
				}
			}
			input[i][j] += K; //다 자른후에 다시 더하기
		}
	}
	return maxi;
}

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &N, &K);
		memset(input, 0, sizeof(input));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &input[i][j]);
			}
		}
		printf("#%d %d\n", t, cut());

	}
}