#include <iostream>
#include <algorithm>
#include <queue>

#pragma warning( disable : 4996 )
using namespace std;

int N, K;
queue<int> q;

void oneq() {
	while (N > 0) {
		for (int i = 1; i < K; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}

		int result = q.front();
		q.pop();
		if (N == 1) {
			printf("%d", result);
			return;
		}
		printf("%d, ", result);

		N--;
	}
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	printf("<");
	oneq();
	printf(">");
}