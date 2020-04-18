#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

class pos {
public:
	int y;
	int x;
};

int N, M;
int input[1010][1010];
queue<pos> q[2];
int day = 0;

void check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] == 0) day = -1;
		}
	}
}

void push(int y, int x, int d) {
	if (x <= 0 || y <= 0) return;
	if (x > M || y > N) return;
	if (input[y][x] == 0) {
		q[d % 2].push({ y,x });
		input[y][x] = 1;
	}
}

void ripe() {
	while (1) {
		while (!q[day % 2].empty()) {
			pos num = q[day % 2].front();
			q[day % 2].pop();
			push(num.y, num.x - 1, day + 1);
			push(num.y, num.x + 1, day + 1);
			push(num.y - 1, num.x, day + 1);
			push(num.y + 1, num.x, day + 1);
		}
		if (q[(day + 1) % 2].empty()) break;
		day++;
	}
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] == 1) q[0].push({ i, j });
		}
	}
	ripe();
	check();
	printf("%d", day);
}