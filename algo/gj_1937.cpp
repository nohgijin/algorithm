#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;


int n;
int input[510][510];
int cache[510][510] = { 0, };
int cnt = 0;


int dpdfs(int bfr, int y, int x) {
	if (y <= 0 || x <= 0 || y > n || x > n) return 0;
	if (bfr >= input[y][x]) return 0;

	if (cache[y][x]) return cache[y][x];

	int d = dpdfs(input[y][x], y + 1, x);
	int u = dpdfs(input[y][x], y - 1, x);
	int r = dpdfs(input[y][x], y, x + 1);
	int l = dpdfs(input[y][x], y, x - 1);

	int best = max(d, u);
	best = max(best, r);
	best = max(best, l);


	return cache[y][x] = best + 1;

}




int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &input[i][j]);
			//P.push_back({ i,j,input[i][j] });
		}
	}
	//sort(P.begin(), P.end(), comp);

	int day = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			day = max(day, dpdfs(0, i, j));
		}
	}

	printf("%d", day);
}