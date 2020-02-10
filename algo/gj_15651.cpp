#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning( disable : 4996 )

using namespace std;

vector<int> stack;

void stackPrint() {
		for (int i = 0; i < stack.size(); i++) {
			printf("%d ", stack[i]);
		}
		printf("\n");
}

void NM(int depth, int N, int M) {
	for (int i = 1; i <= N; i++) {
		stack.push_back(i);
		if (depth == M) stackPrint();
		else {
			NM(depth + 1, N, M);
		}
		stack.pop_back();
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	NM(1, N, M);
	return 0;
}

