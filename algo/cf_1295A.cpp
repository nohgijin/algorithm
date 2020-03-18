#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
int N;
vector<int> v;

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		v.clear();
		scanf("%d", &N);
		while (true) {
			if (N >= 4) {
				v.push_back(1);
				N -= 2;
			}
			else if (N == 2) {
				v.push_back(1);
				break;
			}
			else if (N == 3) {
				v.push_back(7);
				break;
			}
		}
		int sz = v.size();
		for (int i = sz - 1; i >= 0; i--) printf("%d", v[i]);
		printf("\n");
	}
}