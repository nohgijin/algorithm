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

int w, h;
int input[60][60];
int map[60][60];
bool visited[60][60];
vector<Pos> v;
int cnt = 0;

void bfs(Pos A) {
	Pos p;
	queue<Pos> Q;
	Q.push(A);
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		if (p.y <= 0 || p.x <= 0 || p.y > h || p.x > w) continue;
		if (visited[p.y][p.x]) continue;
		visited[p.y][p.x] = true;
		if (input[p.y][p.x] == 0) continue;
		Q.push({ p.y + 1,p.x });
		Q.push({ p.y - 1,p.x });
		Q.push({ p.y,p.x + 1 });
		Q.push({ p.y,p.x - 1 });
		Q.push({ p.y + 1,p.x + 1 });
		Q.push({ p.y + 1,p.x - 1 });
		Q.push({ p.y - 1,p.x + 1 });
		Q.push({ p.y - 1,p.x - 1 });
	}
}

int main() {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		memset(visited, false, sizeof(visited));
		v.clear();
		cnt = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &input[i][j]);
				if (input[i][j] == 1) v.push_back({ i,j });
			}
		}

		int vs = v.size();
		for (int a = 0; a < vs; a++) {
			if (visited[v[a].y][v[a].x]) continue;
			bfs({ v[a].y, v[a].x });
			cnt++;
		}

		printf("%d\n", cnt);
	}
}