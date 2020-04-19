#include <iostream>
#include <map>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int N;
bool visited[11] = { false, };
map<int, int> m;

void dfs(int bfr, int depth) {
	m[bfr] = 1;
	//printf("%d\n", bfr);
	if (depth == 9) return;
	for (int i = 0; i <= 9; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(bfr * 10 + i, depth + 1);
		visited[i] = false;
	}
}

int main() {
	scanf("%d", &N);
	for (int p = 1; p <= 9; p++) {
		visited[p] = true;
		dfs(p, 1);
		visited[p] = false;
	}
	for (auto s = m.begin(); s != m.end(); s++) {
		int A = s->first;
		int B = N - A;
		if (m[B]) {
			printf("%d + %d", A, B);
			return 0;
		}
	}
	printf("-1");
}