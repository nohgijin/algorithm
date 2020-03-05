#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int N, S;
int tmp;
vector<int> v;
vector<int> output;
int sumi = 0;
int cnt = 0;
bool visited[21] = { false, };

void check() {
	sumi = 0;
	int osize = output.size();
	for (int i = 0; i < osize; i++) sumi += output[i];
	if (sumi == S) cnt++;
}

void bubun(int start, int depth) {
	for (int i = start; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		output.push_back(v[i]);
		check();
		if (depth < N) bubun(i + 1, depth + 1);
		visited[i] = false;
		output.pop_back();
	}
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	bubun(0, 0);
	printf("%d", cnt);
}