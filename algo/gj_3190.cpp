#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

class Pos {
public:
	int y;
	int x;
};

int N, K;
int L;
int input[110][110] = { 0, };

int posx = 1;
int posy = 1;
int bfrdir = 4;
int total_sec = 0;

queue<Pos> snake;
queue<Pos> copy_snake;

bool check() {
	bool chk = false;
	int ss = snake.size();
	for (int i = 0; i < ss; i++) {
		Pos T = snake.front();
		copy_snake.push(T);
		snake.pop();
		if (T.y == posy && T.x == posx) chk = true;
	}

	int css = copy_snake.size();
	for (int i = 0; i < css; i++) {
		Pos T = copy_snake.front();
		snake.push(T);
		copy_snake.pop();
	}
	return chk;
}

void insert() {
	if (input[posy][posx]) {
		snake.push({ posy,posx });
		input[posy][posx] = 0;
	}
	else {
		snake.pop();
		snake.push({ posy,posx });

	}
}

bool dummy(int sec, int bfr_dir, char dir, int y, int x) {
	if (bfr_dir == 1) { //원래방향 위
		while (sec) {
			posy--;
			total_sec++;
			sec--;
			if (posy <= 0) return false;
			insert();
			if (check()) return false;
		}
		if (dir == 'L') {
			bfr_dir = 3;
		}
		else if (dir == 'D') {
			bfr_dir = 4;
		}

	}
	else if (bfr_dir == 2) { //원래방향 아래
		while (sec) {
			posy++;
			total_sec++;
			sec--;
			if (posy > N) return false;
			insert();
			if (check()) return false;
		}
		if (dir == 'L') {
			bfr_dir = 4;
		}
		else if (dir == 'D') {
			bfr_dir = 3;
		}
	}
	else if (bfr_dir == 3) { //원래방향 왼쪽
		while (sec) {
			posx--;
			total_sec++;
			sec--;
			if (posx <= 0) return false;
			insert();
			if (check()) return false;
		}
		if (dir == 'L') {
			bfr_dir = 2;
		}
		else if (dir == 'D') {
			bfr_dir = 1;
		}
	}

	else { //원래방향 오른쪽
		while (sec) {
			posx++;
			total_sec++;
			sec--;
			if (posx > N) return false;
			insert();
			if (check()) return false;
		}
		if (dir == 'L') {
			bfr_dir = 1;
		}
		else if (dir == 'D') {
			bfr_dir = 2;
		}
	}
	return true;
}

int main() {
	int cmd1[110];
	char cmd2[110];

	scanf("%d", &N);
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		input[y][x] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		scanf("%d %c", &X, &C);
		cmd1[i] = X;
		cmd2[i] = C;
	}

	snake.push({ 1,1 });

	for (int i = 0; i < L; i++) {
		if (!dummy(cmd1[i], bfrdir, cmd2[i], posy, posx)) break;
	}

	printf("%d", total_sec);
}