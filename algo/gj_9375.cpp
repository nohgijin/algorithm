#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
int n;
vector<string>v;
vector<int> vc;
bool visited[32] = { false, };

void ck() {
	int sum = 1;
	int cnt = 0;
	int vs = v.size();
	vc.clear();
	for (int i = 0; i < vs; i++) {
		if (i == 0) vc.push_back(1);
		else {
			if (v[i - 1] == v[i]) vc[cnt]++;
			else {
				vc.push_back(1);
				cnt++;
			}
		}
	}
	int sz = vc.size();
	for (int i = 0; i < sz; i++) {
		sum *= (vc[i] + 1);
	}
	sum--;
	printf("%d\n", sum);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		v.clear();
		int tmp;
		scanf("%d", &tmp);
		for (int j = 0; j < tmp; j++) {
			char clt[22];
			char typ[22];
			scanf("%s %s", clt, typ);
			v.push_back(typ);
		}
		sort(v.begin(), v.end());
		ck();
	}
}