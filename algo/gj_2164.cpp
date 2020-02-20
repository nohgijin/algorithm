#include <iostream>
#include <algorithm>
#include <queue>

#pragma warning( disable : 4996 )
using namespace std;

int N;
queue<int> q;

void card() {
	while (q.size() > 1) {
		int qsize = q.size();
		q.pop();
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	card();
	printf("%d", q.front());
}