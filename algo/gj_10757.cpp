#include <stdio.h>
#include <string.h>
#include <vector>

#pragma warning( disable : 4996 )
using namespace std;
vector<int> stack;

void printStack() {
	while (!stack.empty()) {
		int ps = stack.back();
		printf("%d", ps);
		stack.pop_back();
	}
}

int getNum(char *str, int index) {
	int len = strlen(str);
	if (len - index < 0) return 0;
	return str[len - index] - 48;
}

int main() {
	char A[10010];
	char B[10010];
	int overflow = 0;

	scanf("%s %s", A, B);

	int lenA = strlen(A);
	int lenB = strlen(B);

	int lenC = (lenA > lenB) ? lenA : lenB;

	for (int i = 1; i <= lenC; i++) {
		int tmp = getNum(A, i) + getNum(B, i);
		tmp += overflow;
		overflow = 0;
		if (tmp >= 10) {
			stack.push_back(tmp - 10);
			overflow = 1;
		}
		else
			stack.push_back(tmp);
	}

	if (overflow) stack.push_back(1);

	printStack();

	return 0;
}