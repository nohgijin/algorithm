#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

int a1, a2, a3, a4;
char a[100000];

int main() {
	int sum = 0;
	scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
	scanf("%s", a);
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		if (a[i] == '1') sum += a1;
		else if (a[i] == '2') sum += a2;
		else if (a[i] == '3') sum += a3;
		else if (a[i] == '4') sum += a4;
	}
	printf("%d", sum);
}