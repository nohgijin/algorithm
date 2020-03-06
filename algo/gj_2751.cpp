#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int N;
vector<int> v;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) printf("%d\n", v[i]);
}