#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int cnt[3] = { 0, };
	int n;
	scanf("%d", &n);
	char s[400000];
	scanf("%s", s);

	for (int i = 0; i < n; i++) {
		s[i] = s[i] - '0';
	}

	for (int i = 0; i < n; i++) {
		cnt[s[i]]++; //cnt에 개수 들어감
	}
	int stand = n / 3;

	for (int i = n - 1; i >= 0; i--) {
		if (cnt[2] >= stand) break;
		if (s[i] != 2 && cnt[s[i]] > stand) {
			cnt[s[i]]--;
			s[i] = 2;
			cnt[2]++;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (cnt[1] >= stand) break;
		if (s[i] != 1 && cnt[s[i]] > stand) {
			cnt[s[i]]--;
			s[i] = 1;
			cnt[1]++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (cnt[0] >= stand) break;
		if (s[i] != 0 && cnt[s[i]] > stand) {
			cnt[s[i]]--;
			s[i] = 0;
			cnt[0]++;
		}
	}

	for (int i = 0; i < n; i++) {
		s[i] = s[i] + '0';
	}

	printf("%s", s);
}