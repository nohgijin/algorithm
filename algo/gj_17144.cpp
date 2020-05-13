#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int R, C, T;
int input[60][60];
int copy_input[60][60];

class Pos {
public:
	int y;
	int x;
};

vector<Pos>pure;
vector<Pos>dust;

int dustsum() {
	int sumi = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (input[i][j] == -1) continue;
			sumi += input[i][j];
		}
	}
	return sumi;
}

void airpure2(int y, int x, int bfr) {
	int cur;
	while (y == pure[1].y) {
		x++; //오른쪽으로 이동
		cur = input[y][x]; //현재값 저장
		input[y][x] = bfr; //현재값에 이전값 할당
		bfr = cur; //이전값에 현재값 저장
		if (x == C) break;
	}
	while (x == C) {
		y++;
		cur = input[y][x];
		input[y][x] = bfr;
		bfr = cur;
		if (y == R)	break;
	}
	while (y == R) {
		x--;
		cur = input[y][x];
		input[y][x] = bfr;
		bfr = cur;
		if (x == 1) break;
	}
	while (x == 1) {
		y--;
		if (y == pure[1].y)	break;
		if (input[y][x] == -1) continue;
		cur = input[y][x];
		input[y][x] = bfr;
		bfr = cur;
	}
}


void airpure1(int y, int x, int bfr) {
	int cur;
	while (y == pure[0].y) {
		x++; //오른쪽으로 이동
		cur = input[y][x]; //현재값 저장
		input[y][x] = bfr; //현재값에 이전값 할당
		bfr = cur; //이전값에 현재값 저장
		if (x == C) break;
	}
	while (x == C) {
		y--;
		cur = input[y][x];
		input[y][x] = bfr;
		bfr = cur;
		if (y == 1) break;
	}
	while (y == 1) {
		x--;
		cur = input[y][x];
		input[y][x] = bfr;
		bfr = cur;
		if (x == 1)	break;
	}
	while (x == 1) {
		y++;
		if (y == pure[0].y) break;
		if (input[y][x] == -1) continue;
		cur = input[y][x];
		input[y][x] = bfr;
		bfr = cur;
	}
}

void airdiff(int y, int x) {
	int moredust = copy_input[y][x] / 5; //원래꺼(copy)에 있는 것들만
	int side = 0;

	if (y - 1 >= 1 && input[y - 1][x] != -1) {
		side++;
		input[y - 1][x] += moredust;
	}
	if (y + 1 <= R && input[y + 1][x] != -1) {
		side++;
		input[y + 1][x] += moredust;
	}
	if (x - 1 >= 1 && input[y][x - 1] != -1) {
		side++;
		input[y][x - 1] += moredust;
	}
	if (x + 1 <= C && input[y][x + 1] != -1) {
		side++;
		input[y][x + 1] += moredust;
	}
	input[y][x] -= moredust * side;  //원인먼지 감소
	if (input[y][x] < 0) input[y][x] = 0;
}

int main() {
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] == -1) pure.push_back({ i,j }); //공기청정기
			else if (input[i][j] != 0) dust.push_back({ i,j }); //처음먼지
		}
	}

	memcpy(copy_input, input, sizeof(input)); //copy==input됨

	while (T) {
		int ds = dust.size();
		//먼지 퍼지기
		for (int i = 0; i < ds; i++)  airdiff(dust[i].y, dust[i].x);

		memcpy(copy_input, input, sizeof(input)); //input에 copy내용 다 복사

		airpure1(pure[0].y, pure[0].x, 0); //공기청정기 위
		airpure2(pure[1].y, pure[1].x, 0); //공기청정기 아래

		memcpy(copy_input, input, sizeof(input)); //input에 copy내용 다 복사
		T--;

		dust.clear();
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (input[i][j] != 0 && input[i][j] != -1) dust.push_back({ i,j });
			}
		}
	}
	printf("%d", dustsum());
}