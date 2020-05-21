#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

#pragma warning(disable:4996)
using namespace std;

class Case {
public:
	int a;
	int b;
};

int N, M;
int m[1010];
int answer[1010] = { 0, };
vector<Case> v;
bool result = true;

bool check() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (answer[i] == 0) cnt++;
		if (cnt >= 2) return false;
	}
	return true;
}

void change(int idx) {
	int a = v[idx].a;
	int b = v[idx].b;

	if (m[idx] == 0) { //°ÅÁþ
		for (int i = a; i <= b; i++) {
			answer[i] = -1;
		}
	}
	else if (m[idx] == 1) { //Âð
		for (int i = 1; i < a; i++) {
			answer[i] = -1;
		}
		for (int i = b + 1; i <= N; i++) {
			answer[i] = -1;
		}
	}

}

bool notMosun() {
	int testAnswer[1010] = { 0, };
	int vs = v.size();
	for (int p = 0; p < vs; p++) {
		int a = v[p].a;
		int b = v[p].b;
		if (m[p] == 0) { //°ÅÁþ
			for (int i = a; i <= b; i++) {
				if (testAnswer[i] == 1) return false;
				testAnswer[i] = -1;
			}
		}

		else if (m[p] == 1) { //Âü
			for (int i = 1; i < a; i++) {
				if (testAnswer[i] == -1) return false;
				testAnswer[i] = 1;
			}
			for (int i = b + 1; i <= N; i++) {
				if (testAnswer[i] == -1) return false;
				testAnswer[i] = 1;
			}
		}
	}
	return true;
}

void rec(int idx) {
	if (idx == M) {
		if (notMosun()) {
			memset(answer, 0, sizeof(answer));
			for (int i = 0; i < M; i++) {
				change(i);
			}
			if (!check()) {
				result = false;
				return;
			}
		}
		return;
	}

	for (int i = 0; i <= 1; i++) {
		if (!result) return;
		m[idx] = i;
		rec(idx + 1);
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		v.push_back({ t1,t2 });
	}
	rec(0);

	if (!result) printf("NO\n");
	else printf("YES\n");
	return 0;
}