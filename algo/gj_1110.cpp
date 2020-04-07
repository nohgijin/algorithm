#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

char N[3];
char M[3];
int cycle = 0;
queue<int> q;

void cl() {
	while (true) {
		int sumi = q.front() + q.back(); //8
		if (sumi >= 10) sumi -= 10;
		q.pop(); //26->6
		q.push(sumi); //68
		M[0] = q.front() + '0';
		M[1] = q.back() + '0';
		cycle++;
		if (!strcmp(N, M)) break;
	}
}

int main() {
	scanf("%s", &N);
	int len = strlen(N);
	if (len == 1) {
		char tmp = N[0];
		N[0] = '0';
		N[1] = tmp;
	}
	for (int i = 0; i < 2; i++) q.push(N[i] - '0');
	cl();
	printf("%d", cycle);
}