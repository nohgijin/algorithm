#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, M;
int input[10][10];
int copy_input[10][10];

class Case {
public:
	int y;
	int x;
	int value;
	int dir;
};

vector<Case> cctv;
int cs;
int mini = INT_MAX;

void check() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (copy_input[i][j] == 0) cnt++;
		}
	}
	mini = min(mini, cnt);
}

void f4(int y, int x) {
	for (int i = x - 1; i >= 1; i--) {
		if (copy_input[y][i] == 6) break;
		copy_input[y][i] = -1;
	}
}

void f3(int y, int x) {
	for (int i = y + 1; i <= N; i++) {
		if (copy_input[i][x] == 6) break;
		copy_input[i][x] = -1;
	}
}

void f2(int y, int x) {
	for (int i = x + 1; i <= M; i++) {
		if (copy_input[y][i] == 6) break;
		copy_input[y][i] = -1;
	}
}

void f1(int y, int x) {
	for (int i = y - 1; i >= 1; i--) {
		if (copy_input[i][x] == 6) break;
		copy_input[i][x] = -1;
	}
}

void see() {
	for (int i = 0; i < cs; i++) {
		int y = cctv[i].y;
		int x = cctv[i].x;
		if (cctv[i].value == 1) {
			if (cctv[i].dir == 1) {
				f1(y, x);
			}
			else if (cctv[i].dir == 2) {
				f2(y, x);
			}
			else if (cctv[i].dir == 3) {
				f3(y, x);
			}
			else if (cctv[i].dir == 4) {
				f4(y, x);
			}
		}
		else if (cctv[i].value == 2) {
			if (cctv[i].dir == 1) {
				f2(y, x);
				f4(y, x);
			}
			else if (cctv[i].dir == 2) {
				f1(y, x);
				f3(y, x);
			}
		}
		else if (cctv[i].value == 3) {
			if (cctv[i].dir == 1) {
				f1(y, x);
				f2(y, x);
			}
			else if (cctv[i].dir == 2) {
				f2(y, x);
				f3(y, x);
			}
			else if (cctv[i].dir == 3) {
				f3(y, x);
				f4(y, x);
			}
			else if (cctv[i].dir == 4) {
				f4(y, x);
				f1(y, x);
			}
		}
		else if (cctv[i].value == 4) {
			if (cctv[i].dir == 1) {
				f1(y, x);
				f2(y, x);
				f4(y, x);
			}
			else if (cctv[i].dir == 2) {
				f1(y, x);
				f2(y, x);
				f3(y, x);
			}
			else if (cctv[i].dir == 3) {
				f2(y, x);
				f3(y, x);
				f4(y, x);
			}
			else if (cctv[i].dir == 4) {
				f1(y, x);
				f3(y, x);
				f4(y, x);
			}
		}
		else if (cctv[i].value == 5) {
			f1(y, x);
			f2(y, x);
			f3(y, x);
			f4(y, x);
		}
	}
	check();
	memcpy(copy_input, input, sizeof(input));
}

void dfs(int depth) {
	if (depth >= cs) {
		see();
		return;
	}
	else {
		if (cctv[depth].value == 1) {
			for (int i = 1; i <= 4; i++) {
				cctv[depth].dir = i;
				dfs(depth + 1);
			}
		}
		else if (cctv[depth].value == 2) {
			for (int i = 1; i <= 2; i++) {
				cctv[depth].dir = i;
				dfs(depth + 1);
			}
		}
		else if (cctv[depth].value == 3) {
			for (int i = 1; i <= 4; i++) {
				cctv[depth].dir = i;
				dfs(depth + 1);
			}
		}
		else if (cctv[depth].value == 4) {
			for (int i = 1; i <= 4; i++) {
				cctv[depth].dir = i;
				dfs(depth + 1);
			}
		}
		else if (cctv[depth].value == 5) {
			cctv[depth].dir = 1;
			dfs(depth + 1);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] > 0 && input[i][j] < 6) {
				cctv.push_back({ i,j,input[i][j] });
			}
		}
	}
	memcpy(copy_input, input, sizeof(input));
	cs = cctv.size();
	dfs(0);

	printf("%d", mini);

}