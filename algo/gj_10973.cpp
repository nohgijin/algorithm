#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int N;
int cnt = 0;
bool bfind = false;
bool realfind = false;
int chat;
bool visited[10100] = { false, };
vector<int>input;
vector<int> s;

void print() {
	int len = s.size();
	for (int i = 0; i < len; i++) printf("%d ", s[i]);
}

void sun(int depth) {
	for (int i = N; i >= 1; i--) {
		if (realfind) return;
		if (bfind) {
			if (visited[i] == true) continue;
			visited[i] = true;
			s.push_back(i);
			if (depth < N) sun(depth + 1);
			else {
				print();
				realfind = true;
			}
			visited[i] = false;
			s.pop_back();
		}
		else {
			if (input[depth] != i) continue;
			if (visited[i] == true) continue;
			visited[i] = true;
			s.push_back(i);
			if (depth < N) sun(depth + 1);
			else bfind = true;
			visited[i] = false;
			s.pop_back();
		}
	}
}

int main() {
	scanf("%d", &N);
	input.push_back(0);
	for (int i = 1; i <= N; i++) {
		int tmp;
		scanf("%d", &tmp);
		input.push_back(tmp);
	}
	sun(1);
	if (!realfind) printf("-1");
}