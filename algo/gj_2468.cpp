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
int input[110][110] = { 0, };
int copy_input[110][110] = { 0, };
int maxi = 0; //잠기지 않은 영역 최댓값을 구함

class Case {
public:
	int y;
	int x;
};


int result = 0;
int jinResult = 0;

void show() {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%2d ", copy_input[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void dfs(int y, int x, int value) {
	if (y > N || x > N || y <= 0 || x <= 0) return;
	if (copy_input[y][x] != 0) return; //방문안했고 비침수지역인거
	copy_input[y][x] = value; //체크함
//	show();

	dfs(y + 1, x, value);
	dfs(y - 1, x, value);
	dfs(y, x + 1, value);
	dfs(y, x - 1, value);
}

void rain(int depth) {
	vector<Case> v;
	//	printf("depth :: %d \n", depth);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (copy_input[i][j] > depth) {
				copy_input[i][j] = 0; //비침수지역
				v.push_back({ i,j });
			}
		}
	}
	int vs = v.size();
	result = 0;
	for (int i = 0; i < vs; i++) {
		if (copy_input[v[i].y][v[i].x] == 0) {
			result--;
			dfs(v[i].y, v[i].x, result);
		}
	}
	//	printf("섬개수 : %d\n", result);
	jinResult = max(abs(result), jinResult);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] > maxi) {
				maxi = input[i][j];
			}
		}
	}

	for (int i = 0; i <= maxi; i++) {
		memcpy(copy_input, input, sizeof(input));
		rain(i);
	}
	printf("%d", jinResult);
}