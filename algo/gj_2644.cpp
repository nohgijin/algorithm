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
	int num;
	int cnt = 0;
};

int n, m;
int person1, person2;
bool map[110][110] = { false, };
bool visited[110][110] = { false, };

int bfs() {
	queue<Pos> Q;
	Q.push({ person1 });
	while (!Q.empty()) {
		Pos P = Q.front();
		if (P.num == person2) return P.cnt;
		Q.pop();
		for (int i = 1; i <= n; i++) {
			if (!map[P.num][i]) continue;
			if (visited[P.num][i]) continue;
			visited[P.num][i] = true;
			visited[i][P.num] = true;
			Q.push({ i ,P.cnt + 1 });
		}

	}
	return -1;
}

int main() {
	scanf("%d", &n);
	scanf("%d %d", &person1, &person2);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		map[t1][t2] = true;
		map[t2][t1] = true;
	}
	printf("%d", bfs());
}