#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N;
int input[110];
bool visited[110] = { false, };
vector<int> v;

bool dfs(int start, int cur) {
	if (start == cur) return true;
	else if (visited[cur]) return false;
	else {
		visited[cur] = true;
		return dfs(start, input[cur]);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &input[i]);
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i, input[i])) {
			v.push_back(i);
		}
	}

	int vs = v.size();
	printf("%d\n", vs);
	for (int i = 0; i < vs; i++) {
		printf("%d\n", v[i]);
	}
}