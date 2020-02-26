#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, t;
long long sum;
vector<int>v;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	scanf("%d", &t);
	for (int j = 0; j < t; j++) {
		scanf("%d", &n);
		sum = 0;
		v.clear();
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		int vsize = v.size();
		sort(v.begin(), v.end());
		for (int p = 0; p < vsize; p++) {
			for (int q = p + 1; q < vsize; q++) {
				if (v[p] == 0 || v[q] == 0) continue;
				sum += gcd(v[p], v[q]);
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}