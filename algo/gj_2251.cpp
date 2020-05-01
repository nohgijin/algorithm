#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#pragma warning(disable:4996)
using namespace std;

class Case {
public:
	int a;
	int b;
	int c;
};

int maxA, maxB, maxC;
vector<int> v;
map<int, int> visited;
//bool visited[200200200];

void bfs(int initA, int initB, int initC) {
	queue<Case> Q;
	Q.push({ initA, initB, initC });
	while (!Q.empty()) {
		Case Ca;
		Ca = Q.front();
		Q.pop();
		int a = Ca.a;
		int b = Ca.b;
		int c = Ca.c;
		if (a<0 || b<0 || c<0 || a>maxA || b>maxB || c>maxC) continue;
		int sum = a * 1000000 + b * 1000 + c;
		if (visited[sum]) continue;
		visited[sum] = true;
		if (a == 0) v.push_back(c);

		if (a <= maxB - b) { //a->b
			Q.push({ 0, a + b, c });
		}
		if (a > maxB - b) {
			Q.push({ a - (maxB - b),maxB,c });
		}
		if (a <= maxC - c) { //a->c
			Q.push({ 0,b,a + c });
		}
		if (a > maxC - c) {
			Q.push({ a - (maxC - c),b,maxC });
		}
		if (b <= maxA - a) { //b->a
			Q.push({ a + b,0,c });
		}
		if (b > maxA - a) {
			Q.push({ maxA,b - (maxA - a),c });
		}
		if (b <= maxC - c) { //b->c
			Q.push({ a,0,b + c });
		}
		if (b > maxC - c) {
			Q.push({ a,b - (maxC - c),maxC });
		}
		if (c <= maxA - a) { //c->a
			Q.push({ a + c,b,0 });
		}
		if (c > maxA - a) {
			Q.push({ a - (maxC - c),b,maxC });
		}
		if (c <= maxB - b) { //c->b
			Q.push({ a,b + c,0 });
		}
		if (c > maxB - b) {
			Q.push({ a,maxB,c - (maxB - b) });
		}

	}
}

int main() {
	scanf("%d %d %d", &maxA, &maxB, &maxC);
	bfs(0, 0, maxC);
	sort(v.begin(), v.end());
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		printf("%d ", v[i]);
	}
}