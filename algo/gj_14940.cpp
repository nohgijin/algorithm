#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
#pragma warning(disable:4996)

class Pos {
public:
	int y;
	int x;
	int dist = 0;
};

int n, m;
int map[1010][1010];
int output[1010][1010];
bool visited[1010][1010] = { false, };
Pos target;
vector<Pos> land;
int mini = INT_MAX;

//A°¡ Å¸°Ù
void distance(Pos A) {
	queue<Pos> Q;
	Q.push(A);
	memset(visited, false, sizeof(visited));
	while (!Q.empty()) {
		Pos p = Q.front();
		Q.pop();
		if (p.y <= 0 || p.x <= 0 || p.y > n || p.x > m) continue;
		if (map[p.y][p.x] == 0) continue;
		if (visited[p.y][p.x]) continue;
		visited[p.y][p.x] = true;
		output[p.y][p.x] = p.dist;
		Q.push({ p.y,p.x + 1,p.dist + 1 });
		Q.push({ p.y,p.x - 1,p.dist + 1 });
		Q.push({ p.y + 1,p.x,p.dist + 1 });
		Q.push({ p.y - 1,p.x,p.dist + 1 });
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) target = { i,j };
			if (map[i][j] == 1) land.push_back({ i, j });
			if (map[i][j] == 0) output[i][j] = 0;
		}
	}

	int ls = land.size();

	distance(target);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j] == false && map[i][j] == 1) output[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", output[i][j]);
		}
		printf("\n");
	}
}