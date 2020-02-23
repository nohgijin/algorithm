#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#pragma warning(disable:4996)

char input[210];
int k;
string result;

void pip() {
	int len = strlen(input);
	int tmplen = len;
	int q = 0;
	int s = 0;
	for (int i = 0; i < tmplen; i++) {
		char tmp = input[i];
		if (tmp == '?') {
			q++;
			len--;
		}
		else if (tmp == '*') {
			s++;
			len--;
		}
	}

	int tmps = s;
	int tmpq = q;

	int min = len;

	min -= q;
	min -= s;

	if (tmps) { //*있으면 최댓값 무한대
		if (k >= min) result = "Possible";
		else result = "Impossible";
	}
	else { //*없으면, 최댓값은 len
		if (k >= min && k <= len) result = "Possible";
		else result = "Impossible";
	}

}

int main() {
	scanf("%s", input);
	scanf("%d", &k);
	pip();
	cout << result;
}
