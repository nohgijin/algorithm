#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <climits>

#pragma warning(disable:4996)
using namespace std;

double A, B, C, D;
int total = 0;
int mini = INT_MAX;

void dfs(double day) {
	total += day * A + ceil((D - day) / B) * C;
}

int main(void) {
	scanf("%lf %lf %lf %lf", &A, &B, &C, &D);

	for (int i = 0; i <= D; i++) {
		total = 0;
		dfs(i);
		mini = min(mini, total);
	}

	printf("%d", mini);

	return 0;
}