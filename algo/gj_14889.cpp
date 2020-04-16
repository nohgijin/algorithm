#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
#pragma warning(disable:4996)
int N;
int input[110][110];
bool visited[30][30] = { false, };
int mid[110][110] = { 0, };
bool revisited[100] = { false, };
vector<int> a;
vector<int> b;
int mini = INT_MAX;

/*void printA() {
	int as = a.size();
	for (int i = 0; i < as; i++) printf("%d ", a[i]);
	//1,2,4,5
	printf("\n");
}*/
//중복체크는 0부터 시작

void dfs(int start, int depth) {
	for (int i = start; i <= N; i++) {
		a.push_back(i);
		revisited[i] = true;
		if (depth != N / 2) dfs(i + 1, depth + 1);
		else { //A팀 확정경우
//			printA();
			int powA = 0;
			for (int p = 0; p < N / 2; p++) {
				for (int q = p + 1; q < N / 2; q++) {
					powA += mid[a[p]][a[q]];
				}
			}
			for (int p = 1; p <= N; p++) {
				if (revisited[p]) continue;
				b.push_back(p);
			}
			int powB = 0;
			for (int p = 0; p < N / 2; p++) {
				for (int q = p + 1; q < N / 2; q++) {
					powB += mid[b[p]][b[q]];
				}
			}

			mini = min(abs(powA - powB), mini);
			b.clear();
		}
		a.pop_back();
		revisited[i] = false;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) scanf("%d", &input[i][j]);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) {
				mid[i][j] = 0;
				continue;
			}
			mid[i][j] = (input[i][j] + input[j][i]);
			visited[i][j] = true;
			visited[j][i] = true;
		}
	}
	dfs(1, 1);
	printf("%d", mini);
}