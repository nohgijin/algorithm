#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#pragma warning(disable:4996)

char N[100002];
vector<int> v;
int sumi = 0;
bool zero = false;
bool suc = false;

bool desc(int a, int b) {
	return a > b;
}
int main() {
	scanf("%s", &N);
	int len = strlen(N);
	for (int i = 0; i < len; i++) {
		v.push_back(N[i] - '0');
		sumi += v[i];
		if (v[i] == 0) zero = true;
	}
	if (sumi % 3 == 0 && zero == true) {
		sort(v.begin(), v.end(), desc);
		for (int i = 0; i < len; i++) printf("%d", v[i]);
	}
	else printf("-1");
}