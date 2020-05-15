#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#pragma warning(disable:4996)
using namespace std;

int N, M, x, y, K;
int input[30][30];
int dice[6][6] = { 0, };
int copy_dice[6][6] = { 0, };
vector<int> v;

bool move(int y, int x, int dir) {
	//돌리고 나서 값넣기
	if (dir == 1) { //오
		//주사위에 쓰거나 지도에 쓰기
		if (x + 1 > M) return false;
		//주사위 값 재배치
		else {
			copy_dice[1][2] = dice[1][2]; //6
			copy_dice[2][1] = dice[4][2]; //5
			copy_dice[2][2] = dice[2][1]; //4
			copy_dice[2][3] = dice[2][2]; //2
			copy_dice[3][2] = dice[3][2]; //1
			copy_dice[4][2] = dice[2][3]; //3
			if (input[y][x + 1] == 0) {
				input[y][x + 1] = copy_dice[4][2];
			}
			else {
				copy_dice[4][2] = input[y][x + 1];
				input[y][x + 1] = 0;
			}
		}
	}
	else if (dir == 2) { //왼
		if (x - 1 <= 0) return false;
		else {
			copy_dice[1][2] = dice[1][2];
			copy_dice[2][1] = dice[2][2];
			copy_dice[2][2] = dice[2][3];
			copy_dice[2][3] = dice[4][2];
			copy_dice[3][2] = dice[3][2];
			copy_dice[4][2] = dice[2][1];
			if (input[y][x - 1] == 0) {
				input[y][x - 1] = copy_dice[4][2];
			}
			else {
				copy_dice[4][2] = input[y][x - 1];
				input[y][x - 1] = 0;
			}
		}
	}
	else if (dir == 3) { //위
		if (y - 1 <= 0) return false;
		else {
			copy_dice[1][2] = dice[2][2];
			copy_dice[2][1] = dice[2][1];
			copy_dice[2][2] = dice[3][2];
			copy_dice[2][3] = dice[2][3];
			copy_dice[3][2] = dice[4][2];
			copy_dice[4][2] = dice[1][2];
			if (input[y - 1][x] == 0) {
				input[y - 1][x] = copy_dice[4][2];
			}
			else {
				copy_dice[4][2] = input[y - 1][x];
				input[y - 1][x] = 0;
			}
		}
	}
	else { //아래
		if (y + 1 > N) return false;
		else {
			copy_dice[1][2] = dice[4][2];
			copy_dice[2][1] = dice[2][1];
			copy_dice[2][2] = dice[1][2];
			copy_dice[2][3] = dice[2][3];
			copy_dice[3][2] = dice[2][2];
			copy_dice[4][2] = dice[3][2];
			if (input[y + 1][x] == 0) {
				input[y + 1][x] = copy_dice[4][2];
			}
			else {
				copy_dice[4][2] = input[y + 1][x];
				input[y + 1][x] = 0;
			}
		}
	}
	return true;
}

int main() {
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	y++; //1부터 시작
	x++; //1부터 시작
	for (int i = 0; i < K; i++) {
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		memset(copy_dice, 0, sizeof(copy_dice));
		if (move(y, x, v[i])) {
			if (v[i] == 1) {
				x++;
			}
			else if (v[i] == 2) {
				x--;
			}
			else if (v[i] == 3) {
				y--;
			}
			else {
				y++;
			}
			memcpy(dice, copy_dice, sizeof(dice));
			printf("%d\n", dice[2][2]);
		}
	}
}
