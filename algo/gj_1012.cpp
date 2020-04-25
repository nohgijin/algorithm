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
	int cnt = 0;
};

int T, M, N, K;
bool map[60][60] = { false, };
bool visited[60][60] = { false, };

vector<Pos> P;

void dfs(Pos A) {
	if (A.y < 0 || A.x < 0 || A.y >= N || A.x >= M) return;
	if (!map[A.y][A.x]) return;
	if (visited[A.y][A.x]) return;
	visited[A.y][A.x] = true;
	dfs({ A.y + 1, A.x });
	dfs({ A.y - 1, A.x });
	dfs({ A.y , A.x + 1 });
	dfs({ A.y , A.x - 1 });
}


int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &M, &N, &K);
		int cnt = 0;
		memset(map, false, sizeof(map));
		memset(visited, false, sizeof(visited));
		P.clear();
		for (int j = 0; j < K; j++) {
			int first, second;
			scanf("%d %d", &first, &second);
			map[second][first] = true;
			P.push_back({ second,first });
		}
		int sz = P.size();
		for (int i = 0; i < sz; i++) {
			if (visited[P[i].y][P[i].x]) continue;
			dfs(P[i]);
			cnt++;
		}
		printf("%d\n", cnt);
	}
}