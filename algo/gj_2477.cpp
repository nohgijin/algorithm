#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int K;
char input[100];
int garo = 0;
int saero = 0;
int mini_garo, mini_saero;
vector<int> v;
bool cg = false, cs = false;

int main() {
	scanf("%d", &K);
	for (int i = 0; i < 8; i++) v.push_back(0);
	for (int i = 1; i < 7; i++) {
		int first, second;
		scanf("%d %d", &first, &second);
		if (first == 1 || first == 2) {
			if (i == 1) cg = true;
			if (garo < second) garo = second;
			if (i == 6) v[0] = second;
			else if (i == 1) v[7] = second;
			v[i] = second;
		}
		else if (first == 3 || first == 4) {
			if (i == 1) cs = true;
			if (saero < second) saero = second;
			if (i == 6) v[0] = second;
			else if (i == 1) v[7] = second;
			v[i] = second;
		}
	}

	if (cs) { //세로먼저,홀수일때 세로 짝수일때 가로
		for (int i = 1; i < 7; i = i + 2) {
			if (v[i - 1] != garo && v[i + 1] != garo) mini_saero = v[i];
		}
		for (int i = 2; i < 7; i += 2) {
			if (v[i - 1] != saero && v[i + 1] != saero) mini_garo = v[i];
		}
	}

	if (cg) { //가로먼저,홀수일때 가로 짝수일때 세로
		for (int i = 1; i < 7; i = i + 2) {
			if (v[i - 1] != saero && v[i + 1] != saero) mini_garo = v[i];
		}
		for (int i = 2; i < 7; i += 2) {
			if (v[i - 1] != garo && v[i + 1] != garo) mini_saero = v[i];
		}
	}


	int mini = mini_garo * mini_saero;
	int full = garo * saero;
	printf("%d", K*(full - mini));
}