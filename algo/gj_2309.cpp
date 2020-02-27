#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

vector<int> v;
int sum = 0;
int vsize;
int a, b;

void nan(int depth) {
	for (int i = depth + 1; i < 9; i++) {
		if (sum - v[i] - v[depth] == 100) {
			a = v[i];
			b = v[depth];
			return;
		}
	}
	if (depth + 1 <= 8) return nan(depth + 1);
}

int main() {
	for (int i = 0; i < 9; i++) {
		int k;
		scanf("%d", &k);
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 9; i++) sum += v[i];

	nan(0);

	for (int i = 0; i < 9; i++) {
		if (v[i] != a && v[i] != b) printf("%d\n", v[i]);
	}
}