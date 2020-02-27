#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int N;
int output;
int num = 0;
vector<int> v;

void isprime(int input) {
	for (int i = 1; i <= input; i++) {
		if (input%i == 0) output++;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	int vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		output = 0;
		isprime(v[i]);
		if (output == 2) num++;
	}
	printf("%d", num);
	return 0;
}