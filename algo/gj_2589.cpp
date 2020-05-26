#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int L, W;
char input[55][55];

class Case {
public:
	int y;
	int x;
	int dist = 0;
};

vector<Case> land;
int ls;

int findLongLand(int y, int x) {
	int result;
	bool visited[55][55] = { false, };
	queue<Case> Q;
	Q.push({ y,x });
	while (!Q.empty()) {
		Case C = Q.front();
		Q.pop();
		if (C.y <= 0 || C.x <= 0 || C.y > L || C.x > W) continue;
		if (input[C.y][C.x] == 'W') continue;
		if (visited[C.y][C.x]) continue;
		visited[C.y][C.x] = true;
		result = C.dist;
		Q.push({ C.y + 1,C.x, C.dist + 1 });
		Q.push({ C.y - 1,C.x ,C.dist + 1 });
		Q.push({ C.y,C.x + 1 ,C.dist + 1 });
		Q.push({ C.y,C.x - 1 ,C.dist + 1 });
	}
	return result;
}

int main() {
	scanf("%d %d", &L, &W);
	for (int i = 1; i <= L; i++) {
		scanf("%s", &input[i][1]);
	}

	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= W; j++) {
			if (input[i][j] == 'L') {
				land.push_back({ i,j });
			}
		}
	}
	int jinResult = 0;

	ls = land.size();
	for (int i = 0; i < ls; i++) {
		jinResult = max(findLongLand(land[i].y, land[i].x), jinResult);
	}

	printf("%d", jinResult);

}