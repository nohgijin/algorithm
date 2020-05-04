#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
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

int N, M, K;
int input[510][510] = { 0, };
vector<Pos> v;
bool visited[510][510] = { false, };
int area = 0;
int cul_area = 0;
int maxi = 0;
queue<Pos> Q;

void bfs(Pos P) {
	Q.push({ P.y,P.x });
	while (!Q.empty()) {
		Pos A = Q.front();
		Q.pop();
		if (A.y <= 0 || A.x <= 0 || A.y > N || A.x > M) continue;
		if (!input[A.y][A.x]) continue;
		if (visited[A.y][A.x]) continue;
		visited[A.y][A.x] = true;
		area++;
		Q.push({ A.y + 1,A.x });
		Q.push({ A.y - 1,A.x });
		Q.push({ A.y,A.x + 1 });
		Q.push({ A.y,A.x - 1 });
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] == 1) v.push_back({ i,j });
		}
	}

	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		area = 0;
		if (visited[v[i].y][v[i].x]) continue;
		if (!input[v[i].y][v[i].x]) continue;
		bfs({ v[i].y, v[i].x });
		cul_area++;
		maxi = maxi < area ? area : maxi;
	}

	printf("%d\n", cul_area);
	printf("%d\n", maxi);
}