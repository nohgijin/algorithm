#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

class Pos {
public:
	int x;
	int time = 0;
};
Pos older;
Pos younger;
int N, K;
queue<Pos> q;
vector<int> v;
bool visited[100100] = { false, };

void bfs() {
	q.push({ older.x,0 });
	while (!q.empty()) {
		Pos p = q.front();
		q.pop();
		if (p.x < 0 || p.x > 100000) continue;
		if (visited[p.x]) continue;
		visited[p.x] = true;
		if (p.x == younger.x) {
			v.push_back(p.time);
			break;
		}
		q.push({ p.x + 1,p.time + 1 });
		q.push({ p.x - 1,p.time + 1 });
		q.push({ 2 * p.x,p.time + 1 });
	}
}

int main() {
	scanf("%d %d", &N, &K);
	older.x = N;
	younger.x = K;
	bfs();
	sort(v.begin(), v.end());
	printf("%d", v.front());
}