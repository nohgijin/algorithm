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

int N, M;
char input[110][110];
bool visited[110][110] = { false, };
Pos target;

int distance() {
	queue<Pos> q;
	q.push({ 1,1,1 });
	memset(visited, false, sizeof(visited));

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();
		if (cur.y == target.y && cur.x == target.x) return cur.dist;
		if (cur.y <= 0 || cur.x <= 0 || cur.y > N || cur.x > M) continue;
		if (input[cur.y][cur.x] == '0') continue;
		if (visited[cur.y][cur.x]) continue;
		visited[cur.y][cur.x] = true;
		q.push({ cur.y + 1, cur.x, cur.dist + 1 });
		q.push({ cur.y - 1, cur.x, cur.dist + 1 });
		q.push({ cur.y, cur.x + 1, cur.dist + 1 });
		q.push({ cur.y, cur.x - 1, cur.dist + 1 });
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &input[i][1]);

	}
	target = { N,M,0 };
	printf("%d", distance());
}
