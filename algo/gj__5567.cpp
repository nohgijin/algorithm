#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

class Item {
public:
	int number;
	int depth;
};

int n, m;
bool input[510][510] = { false, };
bool visited[510] = { false, };
vector<int> v;

int bfs() {
	int cnt = 0;
	queue<Item> q;
	q.push({ 1,0 });
	visited[1] = true;
	while (!q.empty()) {
		Item I = q.front();
		q.pop();
		if (I.depth == 2) break;
		for (int i = 1; i <= n; i++) {
			if (!input[I.number][i]) continue;
			if (visited[i]) continue;
			visited[i] = true;
			q.push({ i,I.depth + 1 });
			cnt++;
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		input[t1][t2] = true;
		input[t2][t1] = true;
	}

	printf("%d", bfs());

}