#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning( disable : 4996 )

vector <int> arr;
vector <int> r_stack;
int N, M;

void stackPrint() {
	for (int k = 0; k < r_stack.size(); k++) {
		printf("%d ", r_stack[k]);
	}
	printf("\n");
}

void NM(int start, int depth) {
	for (int j = start; j < N; j++) {
		r_stack.push_back(arr[j]);
		if (depth == M) stackPrint();
		else NM(j, depth + 1);
		r_stack.pop_back();
	}
}

int main() {
	int tmp;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	NM(0, 1);
	return 0;
}