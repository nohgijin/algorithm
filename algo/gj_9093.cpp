#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int T;
char input[2000];

void rev() {
	int start = 0;
	int len = strlen(input);
	for (int i = 0; i <= len; i++) {
		if (input[i] == ' ' || i == len) {
			for (int j = i - 1; j >= start; j--) printf("%c", input[j]);
			if (start == 0)	printf(" ");
			start = i;
		}
	}
	printf("\n");
}
int main() {
	scanf("%d", &T);
	cin.ignore();
	for (int i = 0; i < T; i++) {
		cin.getline(input, 2000);
		rev();
	}
}