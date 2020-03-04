#include <iostream>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

int N, M;
int x, y;
int T;
int cnt = 1;
bool visited[40010] = { false, };

int kaing() {
	if (y >= x) {
		int i = x;
		int j = x;
		cnt = x;
		while (true) {
			if (j == y) break;
			if (visited[j] == true) {
				cnt = -1;
				break;
			}
			visited[j] = true;
			j = j + M;
			while (j > N) j = j - N;
			cnt = cnt + M;
		}
	}
	else {
		int i = y;
		int j = y;
		cnt = y;
		while (true) {
			if (i == x) break;
			if (visited[i] == true) {
				cnt = -1;
				break;
			}
			visited[i] = true;
			i = i + N;
			while (i > M) i = i - M;
			cnt = cnt + N;
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		cnt = 1;
		fill_n(visited, 40010, false);
		scanf("%d %d %d %d", &M, &N, &x, &y);
		printf("%d\n", kaing());
	}
}