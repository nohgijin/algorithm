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
int input[25][25];

class Shark {
public:
	int y;
	int x;
	int body = 2;
	int sec = 0;
	int eat = 0;
};

class Fish {
public:
	int y;
	int x;
	int body = 0;
};

Shark sk;
vector<Fish> fish;

void canEatFish();

void sharkMove(int y, int x, int dist) {
	input[y][x] = 0;
	sk = { y,x,sk.body,sk.sec + dist,sk.eat + 1 };
	if (sk.body <= sk.eat) {
		sk.body++;
		sk.eat = 0;
	}
	canEatFish();
}

int bfs(int y, int x) {
	int startSec = sk.sec;
	bool bfsVisited[25][25] = { false, };
	queue<Shark> Q;
	Q.push(sk);
	while (!Q.empty()) {
		Shark S = Q.front();
		Q.pop();
		if (S.x <= 0 || S.y <= 0 || S.x > N || S.y > N) continue;
		if (input[S.y][S.x] > S.body) continue;
		if (bfsVisited[S.y][S.x]) continue;
		bfsVisited[S.y][S.x] = true;
		if (S.y == y && S.x == x) {
			return S.sec - startSec;
		}
		Q.push({ S.y + 1, S.x, S.body, S.sec + 1, S.eat });
		Q.push({ S.y - 1, S.x, S.body, S.sec + 1, S.eat });
		Q.push({ S.y , S.x + 1, S.body, S.sec + 1, S.eat });
		Q.push({ S.y , S.x - 1, S.body, S.sec + 1, S.eat });
	}
	return -1;
}

void shortDist() {
	int mini = INT_MAX;
	int eatY, eatX;
	int fs = fish.size();
	for (int i = 0; i < fs; i++) {
		int shortDist = bfs(fish[i].y, fish[i].x);
		if (shortDist == -1) continue;
		else if (mini > shortDist) {
			mini = shortDist;
			eatY = fish[i].y;
			eatX = fish[i].x;
		}
	}
	if (mini == INT_MAX) {
		return;
	}
	else {
		sharkMove(eatY, eatX, mini);
	}
}

void canEatFish() {
	fish.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (input[i][j] < sk.body && input[i][j]>0) {
				fish.push_back({ i,j,input[i][j] });
			}
		}
	}
	if (fish.empty()) return;
	else shortDist();
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] == 9) {
				sk = { i,j };
				input[i][j] = 0;
			}
		}
	}
	canEatFish();
	printf("%d", sk.sec);
}