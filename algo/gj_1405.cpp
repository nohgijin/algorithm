#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int N;
double a, b, c, d;

bool visited[100][100] = { false, };
double answer = 0;
vector<double> v;
void dfs(int y, int x, char dir, double per, int cnt);


void validate(int y, int x, char dir, double per, int cnt) {
	if (!visited[y][x]) {
		visited[y][x] = true;
		dfs(y, x, dir, per, cnt);
		visited[y][x] = false;
	}
}

void dfs(int y, int x, char dir, double per, int cnt) {
	if (per == 0) return;
	if (cnt == 0) {
		answer += per;
		return;
	}
	validate(y, x + 1, 'E', per*a, cnt - 1);
	validate(y, x - 1, 'W', per*b, cnt - 1);
	validate(y - 1, x, 'N', per*d, cnt - 1);
	validate(y + 1, x, 'S', per*c, cnt - 1);
}

//E:µ¿, W:¼­, N:ºÏ, S:³²
//a:µ¿ b:¼­ c:³² d:ºÏ
int main() {
	scanf("%d", &N);
	int t1, t2, t3, t4;
	scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
	a = (double)t1 / 100;
	b = (double)t2 / 100;
	c = (double)t3 / 100;
	d = (double)t4 / 100;


	visited[50][50] = true;

	validate(50, 51, 'E', a, N - 1);
	validate(50, 49, 'W', b, N - 1);
	validate(49, 50, 'N', d, N - 1);
	validate(51, 50, 'S', c, N - 1);
	printf("%.11lf", answer);
}