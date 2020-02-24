#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
#pragma warning(disable:4996)

int n;
int x, y;
int sum;
int vsize;
char type;

vector<int> vx;
vector<int> vy;

void input() {
	for (int j = 0; j < n; j++) {
		cin >> type >> x >> y;

		if (type == '+') {
			vx.push_back(x);
			vy.push_back(y);
		}
		else if (type == '?') {
			vsize = vx.size();
			sum = 0;
			for (int i = 0; i < vsize; i++) {
				if (vx[i] <= x && vy[i] <= y) sum++;
				else if (vx[i] <= y && vy[i] <= x) sum++;
			}
			if (sum == vsize) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}

int main() {
	scanf("%d", &n);
	input();
}