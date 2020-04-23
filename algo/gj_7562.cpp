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

int tc;
int l;
bool visited[400][400] = { false, };
Pos cur;
Pos goal;

int bfs() {
	queue<Pos> Q;
	Q.push({ cur.y,cur.x });
	while (!Q.empty()) {
		Pos P = Q.front();
		Q.pop();
		if (P.y < 0 || P.x < 0 || P.y >= l || P.x >= l) continue;
		if (P.y == goal.y && P.x == goal.x) {
			return P.cnt;
		}
		if (visited[P.y][P.x]) continue;
		visited[P.y][P.x] = true;
		Q.push({ P.y + 1, P.x + 2, P.cnt + 1 });
		Q.push({ P.y + 2, P.x + 1, P.cnt + 1 });
		Q.push({ P.y + 1, P.x - 2 ,P.cnt + 1 });
		Q.push({ P.y + 2, P.x - 1 ,P.cnt + 1 });
		Q.push({ P.y - 1, P.x + 2 ,P.cnt + 1 });
		Q.push({ P.y - 2, P.x + 1 ,P.cnt + 1 });
		Q.push({ P.y - 1, P.x - 2 ,P.cnt + 1 });
		Q.push({ P.y - 2, P.x - 1 ,P.cnt + 1 });
	}
}

int main() {
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		memset(visited, false, sizeof(visited));
		scanf("%d", &l);
		scanf("%d %d", &cur.y, &cur.x);
		scanf("%d %d", &goal.y, &goal.x);
		printf("%d\n", bfs());
	}
}