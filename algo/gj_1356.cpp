#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
char N[12];
int M[12];
bool suc = false;

int main() {
	int first = 1;
	int second = 1;
	scanf("%s", &N);
	int len = strlen(N);
	for (int i = 0; i < len; i++) {
		M[i] = N[i] - '0';
	}
	for (int i = 0; i < len; i++) {
		if (len == 1) break;
		first *= M[i];
		for (int j = i + 1; j < len; j++) {
			second *= M[j];
		}
		if (first == second) {
			suc = true;
			break;
		}
		else second = 1;
	}
	if (suc == true) printf("YES");
	else printf("NO");
}