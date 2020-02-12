#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>

#pragma warning( disable : 4996 )
using namespace std;

int T;
char PS[51];

void VPS() {
	int cnt = 0;
	if (PS[0] == ')') {
		printf("NO\n");
		return;
	}

	int len = strlen(PS);
	for (int i = 0; i < len; i++) {
		if (PS[i] == '(') cnt++;
		else {
			if (cnt == 0) {
				printf("NO\n");
				return;
			}
			else cnt--;
		}
	}
	if (cnt == 0) printf("YES\n");
	else printf("NO\n");
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", PS);
		VPS();
	}
	return 0;
}