#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning( disable : 4996 )

vector <int> arr;
vector <int> r_stack;
int N;

void stackPrint() {
	for (int k = 0; k < r_stack.size(); k++) {
		printf("%d ", r_stack[k]);
	}
	printf("\n");
}


void NM(int depth, int M) {
	for (int i =0; i < N; i++) {
		int num = arr[i];
		r_stack.push_back(num);
		if (depth == M) stackPrint();
		else NM(depth + 1, M);
		r_stack.pop_back();
	}
}

int main() {
	int M, tmp;
	scanf("%d %d", &N, &M);
	for (int j = 1; j <= N; j++) {
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	NM(1, M);
}