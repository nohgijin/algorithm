#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int N;
int cnt = 0;
bool visited[10100] = { false, };
vector<int> s;

void print() {
	int len = s.size();
	for (int i = 0; i < len; i++) printf("%d ", s[i]);
	printf("\n");
}

void sun(int depth) {
	for (int i = 1; i <= N; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		s.push_back(i);
		int len = s.size();
		if (depth < N) sun(depth + 1);
		if (N == len) print();
		visited[i] = false;
		s.pop_back();
	}

}

int main() {
	scanf("%d", &N);
	if (N == 1) printf("1\n");
	for (int i = 1; i <= N; i++) {
		s.clear();
		fill_n(visited, 10100, 0);
		visited[i] = true;
		s.push_back(i);
		sun(1);
	}
}