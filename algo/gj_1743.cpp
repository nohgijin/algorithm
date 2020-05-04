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
int input[110][110] = { 0, };
vector<Pos> v;
bool visited[110][110] = { false, };
int area = 0;
int maxi = 0;

void dfs(Pos P) {
	if (P.y <= 0 || P.x <= 0 || P.y > N || P.x > M) return;
	if (!input[P.y][P.x]) return;
	if (visited[P.y][P.x]) return;
	visited[P.y][P.x] = true;
	area++;
	dfs({ P.y + 1, P.x });
	dfs({ P.y - 1, P.x });
	dfs({ P.y , P.x + 1 });
	dfs({ P.y , P.x - 1 });
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		input[t1][t2] = 1;
		v.push_back({ t1,t2 });
	}
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		if (visited[v[i].y][v[i].x]) continue;
		area = 0;
		dfs({ v[i].y, v[i].x });
		maxi = maxi < area ? area : maxi;
	}
	printf("%d", maxi);
}