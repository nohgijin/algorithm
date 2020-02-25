#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int T;
int a, b;
vector<int>v;

void minmax() {
	for (int i = 2; i < a; i++) {
		if (a%i == 0 && b%i == 0) {
			a = a / i;
			b = b / i;
			v.push_back(i);
			minmax();
		}
	}
}
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int result = 1;
		scanf("%d %d", &a, &b);
		if (a == 1 || b == 1) result = a * b;
		else if (b%a == 0) result = b;
		else {
			v.clear();
			minmax();
			if (!v.empty()) {
				int vsize = v.size();
				for (int i = 0; i < vsize; i++) {
					result = result * v[i];
				}
			}
			result = result * a*b;
		}
		printf("%d\n", result);
	}
}