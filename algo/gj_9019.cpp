#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;
typedef long long ll;
class Case {
public:
	string untilNowDSLR;
	int result;
};

ll T;
int A, B;
string jinResult;
bool visited[10010] = { false, };

int Rcal(int value) {
	int calResult;
	calResult = value;
	int a = calResult % 10;
	calResult -= a;
	calResult /= 10;
	calResult += a * 1000;
	return calResult;
}

int Lcal(int value) {
	int calResult;
	calResult = value;
	int a = calResult / 1000;
	calResult -= a * 1000;
	calResult *= 10;
	calResult += a;
	return calResult;
}


int Scal(int value) {
	int calResult;
	if (value == 0) calResult = 9999;
	else calResult = value - 1;
	return calResult;
}

int Dcal(int value) {
	int calResult;
	calResult = value * 2;
	if (calResult >= 10000) calResult %= 10000;
	return calResult;
}

void bfs() {
	queue<Case>Q;
	visited[A] = true;
	Q.push({ "", A });
	while (!Q.empty()) {
		Case C = Q.front();
		Q.pop();
		if (C.result == B) {
			jinResult = C.untilNowDSLR;
			return;
		}

		int d = Dcal(C.result);
		int s = Scal(C.result);
		int l = Lcal(C.result);
		int r = Rcal(C.result);

		if (!visited[d]) {
			visited[d] = true;
			Q.push({ C.untilNowDSLR + "D", d });
		}
		if (!visited[s]) {
			visited[s] = true;
			Q.push({ C.untilNowDSLR + "S", s });
		}
		if (!visited[l]) {
			visited[l] = true;
			Q.push({ C.untilNowDSLR + "L", l });
		}
		if (!visited[r]) {
			visited[r] = true;
			Q.push({ C.untilNowDSLR + "R", r });
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T) {
		memset(visited, false, sizeof(visited));
		scanf("%d %d", &A, &B);
		bfs();
		cout << jinResult;
		printf("\n");
		T--;
	}
}