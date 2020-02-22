#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int n;
int tmp;
vector<int> v;
vector<int> vtmp;

void num() {
	if (v.empty()) v.push_back(tmp);
	else {
		int size = v.size();
		int top = v.back();
		if (tmp < top) {
			vtmp.push_back(size);
			v.clear();
		}
		v.push_back(tmp);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		num();
	}
	int size = v.size();
	if (vtmp.empty()) {
		printf("%d", size);
		return 0;
	}
	int vsize = vtmp.size();
	int max = vtmp[0];
	for (int i = 0; i < vsize; i++) {
		if (max <= vtmp[i]) max = vtmp[i];
	}
	if (size >= max) max = size;
	printf("%d", max);
	return 0;
}
