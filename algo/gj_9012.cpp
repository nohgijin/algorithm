#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>

#pragma warning( disable : 4996 )
using namespace std;

int T;
char PS[51];
int a = 0;

void VPS() {
	vector<int> stack;
	if (PS[0] == ')') {
		printf("NO\n");
		return;
	}
	int len = strlen(PS);
	for (int i = 0; i < len; i++) {
		if (PS[i] == '(')
			stack.push_back(PS[i]);
		else {
			if (stack.empty()) {
				printf("NO\n");
				return;
			}
			else {
				stack.pop_back();
			}
		}
	}
	if (stack.size() == 0)
		printf("YES\n");
	else
		printf("NO\n");
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", PS);
		VPS();
	}
	return 0;
}