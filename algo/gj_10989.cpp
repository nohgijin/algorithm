#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
//중복이 엄청나게 많고, 수가 적음-->visited사용

int N;
int x;
int visited[10010] = { 0, };

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		visited[x]++;
	}
	for (int i = 0; i < 10010; i++) {
		while (visited[i] != 0) {
			printf("%d\n", i);
			visited[i]--;
		}
	}
}