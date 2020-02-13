#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#pragma warning( disable : 4996 )
char tmp[1002];
vector <int> stack;

void balance() {
	stack.clear();
	int len = strlen(tmp);
	for (int i = 0; i < len; i++) {
		if ((tmp[i] == '(') || (tmp[i] == '['))
			stack.push_back(tmp[i]);
		else if (tmp[i] == ')') {
			if (stack.empty()) {
				printf("no\n");
				return;
			}
			else if (stack.back() == '(')
				stack.pop_back();
			else if (stack.back() == '[') {
				printf("no\n");
				return;
			}
		}
		else if (tmp[i] == ']') {
			if (stack.empty()) {
				printf("no\n");
				return;
			}
			else if (stack.back() == '[')
				stack.pop_back();
			else if (stack.back() == '(') {
				printf("no\n");
				return;
			}
		}
	}
	if (stack.empty()) printf("yes\n");
	else printf("no\n");
}

int main() {
	while (1) {
		cin.getline(tmp, 1000, '\n');
		if (strcmp(tmp, ".") == 0) break;
		balance();
	}
	return 0;
}