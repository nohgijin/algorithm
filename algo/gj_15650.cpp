#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning( disable : 4996 )

using namespace std;

vector<int> stack;
int used[11] = { 0, };

void stackPrint(int M) {
	int a = 1;
	for (int i = 1; i < stack.size(); i++) {
		if (stack[i - 1] > stack[i]) continue;
		else a++;
	}
	if (a == M) {
		for (int i = 0; i < stack.size(); i++) {
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}

void NM(int depth, int N, int M) {
	if (N == M) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", j);
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (used[i] == 0) {
			stack.push_back(i);
			used[i] = 1;
			if (depth != M)
				NM(depth + 1, N, M);
			else stackPrint(M);
			stack.pop_back();
			used[i] = 0;
		}
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	NM(1, N, M);
	return 0;
}

