#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
int N;
int K;
ll result = 0;
char strinput[20];
int input[20];
int copy_input[20];
bool visited[20] = { false, }; //지워야 할 수
vector<int> dfsinput;

void cal() {
	int cnt = N - K;

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		if (input[i] == 0) return;
		else break;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		result = result + input[i] * pow(10, cnt - 1);
		cnt--;
	}
}

void dfs(int start, int depth) {
	if (visited[start]) return;
	visited[start] = true;

	if (depth != K) {
		for (int i = start + 1; i < N; i++) {
			if (visited[i]) continue;
			dfs(i, depth + 1);
		}
	}

	else {
		cal();
	}

	visited[start] = false;
}

int main(void) {
	scanf("%d %d", &N, &K);
	scanf("%s", strinput);
	for (int i = 0; i < N; i++) {
		input[i] = strinput[i] - '0';
	}

	memcpy(copy_input, input, sizeof(input));

	if (K == 0) {
		printf("%s", strinput);
	}

	else {
		for (int i = 0; i < N; i++) {
			memset(visited, false, sizeof(visited));
			dfs(i, 1);
		}

		printf("%lld", result);
	}

	return 0;
}