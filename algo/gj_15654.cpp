#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning( disable : 4996 )

vector <int> arr;
vector <int> r_stack;
int used[10001] = { 0, };
int N, M;

void stackPrint() {
	for (int k = 0; k < r_stack.size(); k++) {
		printf("%d ", r_stack[k]);
	}
	printf("\n");
}

// r스택에 중복되지 않은 값을 넣음.
void NM(int depth) {
	for (int j = 0; j < N; j++) {
		
		if (used[j] == true) continue;

		r_stack.push_back(arr[j]);
		used[j] = 1;


		if (depth == M) stackPrint();
		else NM(depth + 1);


		r_stack.pop_back();
		used[j] = 0;
		
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	NM(1);
}