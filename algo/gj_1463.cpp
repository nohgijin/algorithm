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
int X;

class Case {
public:
	int result;
	int num = 0;
};

queue<Case> v;

int bfs() {
	while (!v.empty()) {
		Case C = v.front();
		v.pop();
		if (C.result == 1) return C.num;
		if (C.result % 3 == 0) {
			v.push({ C.result / 3,C.num + 1 });
		}
		if (C.result % 2 == 0) {
			v.push({ C.result / 2,C.num + 1 });
		}
		v.push({ C.result - 1,C.num + 1 });
	}
}

int main() {
	scanf("%d", &X);
	v.push({ X,0 });
	printf("%d", bfs());
}