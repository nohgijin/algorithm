#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int visited[30] = { 0, };
int M;
int x;
char input[30];

void some() {
	if (input[1] == 'd') {
		visited[x] = 1;
	}
	else if (input[1] == 'e') {
		visited[x] = 0;
	}
	else if (input[1] == 'h') {
		if (visited[x]) printf("1\n");
		else printf("0\n");
	}
	else if (input[1] == 'o') {
		if (visited[x]) visited[x] = 0;
		else visited[x] = 1;
	}
	else if (input[1] == 'l') {
		fill_n(visited, 30, 1);
	}
	else {
		fill_n(visited, 30, 0);
	}
}

int main() {
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%s %d", input, &x);
		some();
	}
}