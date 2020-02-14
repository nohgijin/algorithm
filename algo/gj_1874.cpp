#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#pragma warning( disable : 4996 )
vector<int> outputStack;
int n;
int a = 0;

int tmpcheck;
int tmplist[10010];

void printStack() {
	for (int i = 0; i < outputStack.size(); i++) {
		printf("%c\n", outputStack[i]);
	}
}

void pushback() {
	int prev;
	for (int i = 1; i <= n; i++) {
		int tmp;

		scanf("%d", &tmp);

		while (a < tmp) {
			outputStack.push_back('+');
			a++;
		}
		if (a == tmp) {
			prev = tmp;
			outputStack.push_back('-');
		}
		else if (a > tmp) {
			if (prev < tmp) {
				printf("NO\n");
				return;
			}
			prev = tmp;
			outputStack.push_back('-');
		}
	}
	printStack();
}

int main() {
	scanf("%d", &n);
	pushback();
}