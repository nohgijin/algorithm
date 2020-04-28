#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

class Pos {
public:
	int x;
	int y;
};

int T;
vector<Pos> v;
vector<int> vv;

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		vv.clear();
		v.clear();
		for (int i = 0; i < 4; i++) {
			int p1, p2;
			scanf("%d %d", &p1, &p2);
			v.push_back({ p1,p2 });
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j) continue;
				int tmp = (v[i].x - v[j].x)*(v[i].x - v[j].x) + (v[i].y - v[j].y)*(v[i].y - v[j].y);
				vv.push_back(tmp);
			}
		}
		sort(vv.begin(), vv.end());
		int line = 0;
		for (int i = 0; i < 11; i++) {
			if (vv[i] == vv[i + 1]) line++;
		}
		if (line == 10) printf("1\n");
		else printf("0\n");
	}
}