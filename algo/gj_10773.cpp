#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning( disable : 4996 )

using namespace std;
int K;
vector <int> stack;

int main() {
	scanf("%d", &K);
	int sum = 0;
	for (int i = 0; i < K; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) stack.pop_back();
		else stack.push_back(tmp);
	}
	for (int i = 0; i < stack.size(); i++) {
		sum += stack[i];
	}
	printf("%d", sum);
}