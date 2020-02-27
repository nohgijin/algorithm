#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int N, K;
vector<int> v;
bool visited[1040] = { false, };

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (!visited[j]) {
				v.push_back(j);
				visited[j] = true;
			}
		}
	}
	int vsize = v.size();
	printf("%d", v[K - 1]);
}