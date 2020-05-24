#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int R, C, M;
int input[110][110];
int r, c, s, d, z;

class Shark {
public:
	int y;
	int x;
	int speed;
	int dir;
	int body;
	bool alive = true;
};

int result = 0;

vector<Shark> sk;

void f1(int idx, int spd);
void f2(int idx, int spd);
void f3(int idx, int spd);
void f4(int idx, int spd);

void f4(int idx, int spd) {
	while (spd) {
		if (sk[idx].x <= 1) {
			f3(idx, spd);
			return;
		}
		else {
			sk[idx].x--;
			spd--;
		}
	}
	sk[idx].dir = 4;
}

void f3(int idx, int spd) {
	while (spd) {
		if (sk[idx].x >= C) {
			f4(idx, spd);
			return;
		}
		else {
			sk[idx].x++;
			spd--;
		}
	}
	sk[idx].dir = 3;
}

void f2(int idx, int spd) {
	while (spd) {
		if (sk[idx].y >= R) {
			f1(idx, spd);
			return;
		}
		else {
			sk[idx].y++;
			spd--;
		}
	}
	sk[idx].dir = 2;
}

void f1(int idx, int spd) {
	while (spd) {
		if (sk[idx].y <= 1) {
			f2(idx, spd);
			return;
		}
		else {
			sk[idx].y--;
			spd--;
		}
	}
	sk[idx].dir = 1;
}

void sharkEat() {
	int shark_input[110][110] = { 0, };
	int ss = sk.size();
	for (int i = 0; i < ss; i++) {
		if (!sk[i].alive) continue;
		if (shark_input[sk[i].y][sk[i].x]) {
			int bfr = shark_input[sk[i].y][sk[i].x];
			int bfrBody = sk[bfr - 1].body;
			int curBody = sk[i].body;
			if (bfrBody > curBody) {
				sk[i].alive = false;
			}
			else {
				sk[bfr - 1].alive = false;
				shark_input[sk[i].y][sk[i].x] = i + 1;
			}
		}
		else shark_input[sk[i].y][sk[i].x] = i + 1;
	}
}

void sharkMove() {
	int ss = sk.size();
	for (int i = 0; i < ss; i++) {
		if (!sk[i].alive) continue;
		if (sk[i].dir == 1) {
			f1(i, sk[i].speed);
		}
		else if (sk[i].dir == 2) {
			f2(i, sk[i].speed);

		}
		else if (sk[i].dir == 3) {
			f3(i, sk[i].speed);

		}
		else {
			f4(i, sk[i].speed);
		}
	}

	sharkEat();
}

void kingMove() {
	int ss = sk.size();

	//사람이 움직이는거
	for (int i = 1; i <= C; i++) {
		vector<int> canEat;
		//상어 도는거
		for (int j = 0; j < ss; j++) {
			//먹을수 있는 상어 y좌표 넣기
			if (sk[j].x == i && sk[j].alive == true) canEat.push_back(sk[j].y);
		}

		sort(canEat.begin(), canEat.end());

		if (!canEat.empty()) {
			int cs = canEat.size();
			//모은 상어 전체 돌기
			for (int j = 0; j < ss; j++) {
				if (sk[j].x == i && sk[j].y == canEat[0] && sk[j].alive == true) {
					result += sk[j].body;
					sk[j].alive = false;
				}
			}
		}

		sharkMove();

	}
}

int main() {
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		sk.push_back({ r,c,s,d,z });
	}
	kingMove();

	printf("%d", result);
}