#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;
#pragma warning(disable:4996)

int N;
int input[10];
vector<int> sinput;
int sum = 0;
int tmax = 0;
bool visited[10] = { false, };

void dec() {
	int ssize = sinput.size();
	sum = 0;
	for (int i = 0; i <= ssize - 2; i++) sum += abs(sinput[i] - sinput[i + 1]);
	tmax = tmax > sum ? tmax : sum;
}

void dif(int depth) {
	for (int i = 1; i <= N; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		sinput.push_back(input[i]);
		if (depth < N) dif(depth + 1);
		dec();
		visited[i] = false;
		sinput.pop_back();
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int tmp;
		scanf("%d", &tmp);
		input[i] = tmp;
	}
	dif(1);
	printf("%d", tmax);
}