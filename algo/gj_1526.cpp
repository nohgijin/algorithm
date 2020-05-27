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

int main() {
	scanf("%d", &N);
	while (N) {
		bool chk = true;
		string tmp = to_string(N);
		int tmplen = tmp.length();
		for (int i = 0; i < tmplen; i++) {
			if (tmp[i] == '4' || tmp[i] == '7') {
				chk = true;
			}
			else {
				chk = false;
				break;
			}
		}
		if (chk) {
			printf("%s", tmp.c_str());
			return 0;
		}
		N--;
	}
}