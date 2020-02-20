#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

#pragma warning( disable : 4996 )
using namespace std;

int N;
vector<pair<int, int>>v;
int x, y;

bool compare(const pair<int, int>a, const pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		printf("%d %d", v[i].first, v[i].second);
		printf("\n");
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), compare);
	print();
}