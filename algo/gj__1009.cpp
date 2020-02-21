#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#pragma warning( disable : 4996 )

vector<int> v;
int a, b;

void last() {
	int tmp = a % 10;
	int lasttmp = tmp;
	if (tmp == 0) {
		printf("10\n");
		return;
	}
	while (true) {
		v.push_back(tmp);
		tmp = tmp * lasttmp;
		tmp = tmp % 10;
		if (tmp == v.front()) break;
	}
	int size = v.size();
	if (size == 1) {
		printf("%d\n", v.front());
		return;
	}
	else {
		int mod = b % size;
		int result;
		if (mod == 0) result = v[size - 1];
		else result = v[mod - 1];
		printf("%d\n", result);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		last();
		v.clear();
	}
}