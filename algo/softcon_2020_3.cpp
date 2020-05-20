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

int T;
int h1, m1, s1;
int h2, m2, s2;

int startSec;
int endSec;

int result = 0;

bool bs = false;
bool be = false;

void bell() {
	int cnt = 0;
	for (int i = 0; i <= 23; i++) {
		cnt = 0;
		int j = 0;
		int p = 0;

		while (true) {
			if (i == 0) {
				if (cnt == 12) break;
			}
			else if (i < 13) {
				if (cnt == i) break;
			}
			else {
				if (cnt == i - 12) break;
			}
			cnt++;

			int bellSec = i * 60 * 60 + j * 60 + p;
			if (bellSec >= startSec && bellSec <= endSec) result++;

			printf("%dh %dm %ds\n", i, j, p);


			p += T;

			if (p >= 60) {
				p -= 60;
				j++;
			}
		}
	}
}

int main() {
	scanf("%d", &T);
	scanf("%d %d %d", &h1, &m1, &s1);
	scanf("%d %d %d", &h2, &m2, &s2);

	//전체종소리 구함

	startSec = h1 * 60 * 60 + m1 * 60 + s1;
	endSec = h2 * 60 * 60 + m2 * 60 + s2;

	bell();
	printf("%d", result);
}