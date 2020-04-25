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

int M, N, K;
int map[110][110] = { 0, };
int copy_map[110][110];
bool visited[110][110] = { false, };
vector<int> output;
int cnt = 0;
int area = 0;

void dfs(Pos A) {
	if (A.y <= 0 || A.x <= 0 || A.y > M || A.x > N) return;
	if (map[A.y][A.x]) return;
	if (visited[A.y][A.x]) return;
	visited[A.y][A.x] = true;
	cnt++;
	map[A.y][A.x] = 2;

	dfs({ A.y + 1,A.x });
	dfs({ A.y - 1,A.x });
	dfs({ A.y,A.x + 1 });
	dfs({ A.y,A.x - 1 });
}

int main() {
	scanf("%d %d %d", &M, &N, &K);
	int t1, t2, t3, t4;
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		for (int p = t2 + 1; p <= t4; p++) {
			for (int q = t1 + 1; q <= t3; q++) {
				map[p][q] = 1;
			}
		}
	}

	memcpy(copy_map, map, sizeof(map));

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			memcpy(map, copy_map, sizeof(map));
			cnt = 0;
			if (visited[i][j]) continue;
			if (map[i][j]) continue;
			dfs({ i, j });
			area++;
			output.push_back(cnt);
		}
	}


	sort(output.begin(), output.end());
	int os = output.size();

	printf("%d\n", area);
	for (int i = 0; i < os; i++) {
		printf("%d ", output[i]);
	}
}