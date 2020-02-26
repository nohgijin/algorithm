#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int t;
int n;
int q;
int vsize;
int depth;
int stdl;
int tmp;
int mstd;

bool visited[110] = { 0, };

vector<int>v;

int gresult = 1;
int gjinresult = 0;

void cal() {
	int min = stdl > tmp ? tmp : stdl;
	for (int j = min; j >= 2; j--) { //나눠지는수 넣어줌
		if (stdl%j == 0 && tmp%j == 0) {
			stdl = stdl / j;
			tmp = tmp / j;
			gresult *= j;
			cal();
		}
	}
}

void gcd(int depth) {
	int a = 1;
	stdl = v[depth];
	mstd = stdl; //std고정시키기위해
	for (q = depth + 1; q < vsize; q++) {
		stdl = mstd;
		tmp = v[q];
		if (stdl == 0 || tmp == 0) continue;
		gresult = 1;
		cal();
		gjinresult += gresult;

	}
	if (depth + 1 < vsize) gcd(depth + 1);
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		vsize = v.size();
		gjinresult = 0;
		gcd(0);
		printf("%d\n", gjinresult);
	}
	return 0;
}