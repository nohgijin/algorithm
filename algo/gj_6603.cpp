#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#pragma warning( disable : 4996 )

vector<int> stack;
vector<int> v;

int k, tmp;

void print() {
	int size = stack.size();
	for (int i = 0; i < size; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

void result(int idx, int depth) {
	if (depth > 6) {
		print();
		return;
	}

	for (int i = idx; i < k; i++) {
		stack.push_back(v[i]);
		result(i + 1, depth + 1);
		stack.pop_back();
	}
}

int main() {
	while (true) {
		scanf("%d", &k);
		if (k == 0) break;
		v.clear();
		stack.clear();
		for (int i = 1; i <= k; i++) {
			int tmp;
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		result(0, 1);
		printf("\n");
	}
}