#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int n;
char input[1000000];
int v0 = 0, v1 = 0, v2 = 0;
int v0f = 0, v1f = 0, v2f = 0;
int stand;

void check() {
	stand = n / 3;
	if (v0 == stand) {
		while (v1 > stand) {
			v1--;
			v2++;
			v1f--;
			v2f++;
		}
		while (v1 < stand) {
			v1++;
			v2--;
			v1f++;
			v2f--;
		}
	}
	else if (v0 > stand) {
		while (v2 < stand) {
			v2++;
			v0--;
			v2f++;
			v0f--;
		}while (v1 < stand) {
			v1++;
			v0--;
			v1f++;
			v0f--;
		}
	}
	else {
		while (v1 > stand) {
			v1--;
			v0++;
			v1f--;
			v0f++;
		}while (v2 > stand) {
			v2--;
			v0++;
			v2f--;
			v0f++;
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s", input);
	int len = strlen(input);
	for (int i = 0; i < len; i++) {
		if (input[i] == '0') v0++;
		else if (input[i] == '1') v1++;
		else if (input[i] == '2') v2++;
	}
	//	printf("%d %d %d\n", v0, v1, v2);
	check();
	//	printf("%d %d %d\n", v0f, v1f, v2f);

	if (v0f > 0) { //v0 더해야할때
		if (v1f < 0) {
			for (int i = 0; i < len; i++) {
				if (input[i] == '1') {
					input[i] = '0';
					v1f++;
					if (v1f == 0) break;
				}
			}
		}
		if (v2f < 0) {
			for (int i = 0; i < len; i++) {
				if (input[i] == '2') {
					input[i] = '0';
					v2f++;
					if (v2f == 0) break;
				}
			}
		}
	}
	else if (v0f < 0) {
		if (v2f > 0) {
			for (int i = len - 1; i >= 0; i--) {
				if (input[i] == '0') {
					input[i] = '2';
					v2f--;
					if (v2f == 0) break;
				}
			}
		}
		if (v1f > 0) {
			for (int i = len - 1; i >= 0; i--) {
				if (input[i] == '0') {
					input[i] = '1';
					v1f--;
					if (v1f == 0) break;
				}
			}
		}
	}
	else { //0은 같을때
		if (v1f > 0) {
			for (int i = 0; i < len; i++) {
				if (input[i] == '2') {
					input[i] = '1';
					v1f--;
					if (v1f == 0) break;
				}
			}
		}if (v2f > 0) {
			for (int i = len - 1; i >= 0; i--) {
				if (input[i] == '1') {
					input[i] = '2';
					v2f--;
					if (v2f == 0) break;
				}
			}
		}
	}
	for (int i = 0; i < len; i++) printf("%c", input[i]);
}