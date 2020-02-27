#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int e, s, m;
int cnt = 1;
int ee = 1, ss = 1, mm = 1;

int main() {
	scanf("%d %d %d", &e, &s, &m);
	while (true) {
		if ((ee == e) && (ss == s) && (mm == m)) break;
		if (ee == 15) ee = 1;
		else ee++;
		if (ss == 28) ss = 1;
		else ss++;
		if (mm == 19) mm = 1;
		else mm++;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}