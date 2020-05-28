#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int T, N;
vector<int> v;
vector<string> sv;
string combStr = "";

void print() {
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int cal(string str) {
	int num = 0;
	int op = 0;
	int result = 0;
	int comLen = combStr.length();
	for (int i = 0; i < comLen; i++) {
		if (combStr[i] == '+') {
			if (op == 1) {
				result += num;
			}
			else if (op == 2) {
				result -= num;
			}
			else {
				result = num;
			}
			num = 0;
			op = 1;
		}
		else if (combStr[i] == '-') {
			if (op == 1) {
				result += num;
			}
			else if (op == 2) {
				result -= num;
			}
			else {
				result = num;
			}
			num = 0;
			op = 2;
		}
		else if (combStr[i] == ' ') {
			continue;
		}
		else {
			num = num * 10 + combStr[i] - '0';
		}
	}
	if (op == 1) {
		result += num;
	}
	else if (op == 2) {
		result -= num;
	}
	else {
		result = num;
	}
	return result;
}

void comb() {
	combStr = "";
	int vs = v.size();
	for (int i = 1; i < vs; i++) {
		if (v[i] == 1) {
			combStr += to_string(i) + "+";
		}
		else if (v[i] == 2) {
			combStr += to_string(i) + "-";
		}
		else if (v[i] == 3) {
			combStr += to_string(i) + " ";
		}
	}
	combStr += to_string(N);
	//	printf("ggggg%s\n", combStr.c_str());
	if (!cal(combStr)) {
		sv.push_back(combStr);
	}
}

void dfs(int start, int depth) {
	v.push_back(start);
	if (depth != N - 1) {
		for (int i = 1; i <= 3; i++) {
			dfs(i, depth + 1);
		}
	}
	else comb();
	v.pop_back();
}

int main() {
	scanf("%d", &T);
	while (T) {
		sv.clear();
		v.clear();
		v.push_back(-1);
		scanf("%d", &N);
		T--;
		for (int i = 1; i <= 3; i++) {
			dfs(i, 1);
		}
		sort(sv.begin(), sv.end());
		int svs = sv.size();
		for (int i = 0; i < svs; i++) {
			printf("%s\n", sv[i].c_str());
		}
		printf("\n");
	}
}