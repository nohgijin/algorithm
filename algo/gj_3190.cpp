#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, K, L;
int input[110][110] = { 0, };
char dir[11100] = { 0, };
int now_dir = 4;
int total_time = 0;

class Pos {
public:
	int y;
	int x;
};

queue<Pos> snake;
//위1 아래2 왼3 오른4

void show() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%2d", input[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//위1 아래2 왼3 오른4

bool move() {
	Pos head = snake.back();
	Pos tail = snake.front();
	Pos nextHead;
	if (now_dir == 1) {
		nextHead = { head.y - 1,head.x };
	}
	else if (now_dir == 2) {
		nextHead = { head.y + 1,head.x };
	}
	else if (now_dir == 3) {
		nextHead = { head.y,head.x - 1 };
	}
	else {
		nextHead = { head.y,head.x + 1 };
	}
	if (nextHead.y > N || nextHead.x > N || nextHead.y <= 0 || nextHead.x <= 0) return false;
	if (input[nextHead.y][nextHead.x] == -1) return false;

	if (input[nextHead.y][nextHead.x] == 1) {
		input[nextHead.y][nextHead.x] = 0;
		head = nextHead;
		input[head.y][head.x] = -1;
		snake.push(head);
	}
	else if (input[nextHead.y][nextHead.x] == 0) {
		head = nextHead;
		input[head.y][head.x] = -1;
		snake.push(head);

		input[tail.y][tail.x] = 0;
		snake.pop();
	}
	total_time++;

	return true;
}

int main() {
	input[1][1] = -1;
	snake.push({ 1, 1 });
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		input[t1][t2] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int t1;
		char t2;
		scanf("%d %c", &t1, &t2);
		dir[t1] = t2;
	}
	//위1 아래2 왼3 오른4
	//왼쪽 L 오른쪽 D
	//show();
	while (true) {
		//show();
		if (move()) {
			if (dir[total_time]) {
				if (now_dir == 1) {
					if (dir[total_time] == 'L') now_dir = 3;
					else if (dir[total_time] == 'D') now_dir = 4;
				}
				else if (now_dir == 2) {
					if (dir[total_time] == 'L') now_dir = 4;
					else if (dir[total_time] == 'D') now_dir = 3;
				}
				else if (now_dir == 3) {
					if (dir[total_time] == 'L') now_dir = 2;
					else if (dir[total_time] == 'D') now_dir = 1;
				}
				else {
					if (dir[total_time] == 'L') now_dir = 1;
					else if (dir[total_time] == 'D') now_dir = 2;
				}
			}
		}
		else break;
		//show();
	}
	printf("%d", total_time + 1);
}