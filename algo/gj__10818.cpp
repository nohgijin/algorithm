#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#pragma warning( disable : 4996 )

int N;
int input;
int main() {
	int nmax, nmin;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (i == 0) {
			nmax = input;
			nmin = input;
		}
		else {
			nmax = max(nmax, input);
			nmin = min(nmin, input);
		}
	}
	printf("%d %d", nmin, nmax);
}
