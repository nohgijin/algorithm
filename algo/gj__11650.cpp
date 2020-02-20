#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

#pragma warning( disable : 4996 )
using namespace std;

int N;
class Location {
public:
	int x;
	int y;
};

vector<Location>v;

bool compare(const Location a, const Location b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	else {
		return a.x < b.x;
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		printf("%d %d", v[i].x, v[i].y);
		printf("\n");
	}
}

int main() {
	int a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		Location l;
		scanf("%d %d", &l.x, &l.y);
		v.push_back(l);
	}
	sort(v.begin(), v.end(), compare);
	print();
}