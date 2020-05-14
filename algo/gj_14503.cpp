#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int N, M, r, c, d;
int input[55][55];
bool chk = false;
bool sec = false;

void clean(int y, int x, int dir) {
	if (chk == true) return;
	if (y <= 0 || x <= 0 || y > N || x > M) return;
	int clean_wall = 0;
	if (sec == false) input[y][x] = -1; //1번

	sec = false;

	if (input[y][x - 1] != 0) clean_wall++;
	if (input[y - 1][x] != 0) clean_wall++;
	if (input[y + 1][x] != 0) clean_wall++;
	if (input[y][x + 1] != 0) clean_wall++;

	if (clean_wall == 4) { //2-c,2-d
		if (dir == 0) {
			if (input[y + 1][x] == 1) {
				chk = true;
				return;
			}
			else clean(y + 1, x, 0);
		}
		else if (dir == 1) {
			if (input[y][x - 1] == 1) {
				chk = true;
				return;
			}
			else clean(y, x - 1, 1);
		}
		else if (dir == 2) {
			if (input[y - 1][x] == 1) {
				chk = true;
				return;
			}
			else clean(y - 1, x, 2);
		}
		else if (dir == 3) {
			if (input[y][x + 1] == 1) {
				chk = true;
				return;
			}
			else clean(y, x + 1, 3);
		}
	}

	else {
		if (dir == 0) { //위쪽
			if (input[y][x - 1] == 0) {
				clean(y, x - 1, 3); //2-a
			}
			else if (input[y][x - 1] != 0) {
				sec = true;
				clean(y, x, 3); //2-b
			}
		}
		else if (dir == 1) { //오른쪽
			if (input[y - 1][x] == 0) {
				clean(y - 1, x, 0); //2-a
			}
			else if (input[y - 1][x] != 0) {
				sec = true;
				clean(y, x, 0); //2-b
			}
		}
		else if (dir == 2) { //아래쪽
			if (input[y][x + 1] == 0) {
				clean(y, x + 1, 1); //2-a
			}
			else if (input[y][x + 1] != 0) {
				sec = true;
				clean(y, x, 1); //2-b
			}
		}
		else if (dir == 3) { //아래쪽
			if (input[y + 1][x] == 0) {
				clean(y + 1, x, 2); //2-a
			}
			else if (input[y + 1][x] != 0) {
				sec = true;
				clean(y, x, 2); //2-b
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	clean(r + 1, c + 1, d);

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] == -1) result++;
		}
	}
	printf("%d", result);
}