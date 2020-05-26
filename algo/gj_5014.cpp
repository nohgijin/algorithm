#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int F, S, G, U, D;
bool canGo = false;
int result;

class Case {
public:
	int layer;
	int num = 0;
};

void bfs() {
	bool bfsVisited[1000010] = { false, };
	queue<Case> Q;
	Q.push({ S, 0 });
	while (!Q.empty()) {
		Case C = Q.front();
		Q.pop();
		if (C.layer == G) {
			canGo = true;
			result = C.num;
			break;
		}
		if (C.layer <= 0 || C.layer > F) continue;
		if (bfsVisited[C.layer]) continue;
		bfsVisited[C.layer] = true;
		Q.push({ C.layer + U, C.num + 1 });
		Q.push({ C.layer - D, C.num + 1 });
	}
}

int main() {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	bfs();
	if (canGo) printf("%d", result);
	else printf("use the stairs");
}