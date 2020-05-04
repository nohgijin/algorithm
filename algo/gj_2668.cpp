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
map<int, int> m;
bool chk = true;
bool indexVisited[110] = { false, };
bool valueVisited[110] = { false, };
void dfs();
void pre();

void dfs() {
	chk = true;
	for (int i = 1; i <= N; i++) {
		if (!indexVisited[i]) continue;
		if (valueVisited[i]) continue;
		chk = false;
		m[i] = 0;
		m[m[i]] = 0;
	}
	if (chk == true) return;
	pre();
}

void pre() {
	memset(valueVisited, false, sizeof(valueVisited));
	memset(indexVisited, false, sizeof(indexVisited));
	for (int i = 1; i <= N; i++) {
		if (m[i] == 0) continue;
		indexVisited[m[i]] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (indexVisited[m[i]]) continue;
		m[i] = 0;
	}
	memset(indexVisited, false, sizeof(indexVisited));
	for (int i = 1; i <= N; i++) {
		if (m[i] == 0) continue;
		indexVisited[i] = true;
		valueVisited[m[i]] = true;
	}
	dfs();
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int tmp;
		scanf("%d", &tmp);
		m[i] = tmp;
	}
	pre();

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!valueVisited[i]) continue;
		cnt++;
	}
	printf("%d\n", cnt);

	for (int i = 1; i <= N; i++) {
		if (!valueVisited[i]) continue;
		printf("%d\n", i);
	}
}