#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

char input[100002];
int len;
int cnt = 0;

void pallin() {
	int cnt = 0;
	int i = len / 2;
	for (int j = 0; j < i; j++) {
		if (input[j] == input[len - j - 1]) {
			cnt++;
		}
	}
	if (i == cnt) printf("yes\n");
	else printf("no\n");
}

int main() {
	while (true) {
		scanf("%s", input);
		len = strlen(input);
		if (len == 1 && input[0] == '0') break;
		else pallin();
	}
}