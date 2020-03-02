#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#pragma warning(disable:4996)

vector<pair<int, char*>> v;
int N;
int age;

bool cmp(pair<int, char*> a, pair<int, char*>b) {
	if (a.first == b.first) return 0;
	else return a.first < b.first;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char *name = new char[110];
		scanf("%d %s", &age, name);
		v.push_back({ age,name });
	}
	stable_sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) printf("%d %s\n", v[i].first, v[i].second);
}
