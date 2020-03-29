#include <stdio.h>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int p;
char input[50];
int visited[8] = { 0, };

void print() {
	for (int i = 0; i < 8; i++) printf("%d ", visited[i]);
	printf("\n");
}

void howmany() {
	fill_n(visited, 8, 0);
	for (int i = 2; i < 40; i++) {
		if (input[i - 2] == 'H') {
			if (input[i - 1] == 'H') {
				if (input[i] == 'H') { //HHH
					visited[7]++;
				}
				else { //HHT
					visited[6]++;
				}
			}
			else {
				if (input[i] == 'H') { //HTH
					visited[5]++;
				}
				else { //HTT
					visited[4]++;
				}

			}
		}
		else {
			if (input[i - 1] == 'H') {
				if (input[i] == 'H') {
					visited[3]++;
				}
				else {
					visited[2]++;
				}
			}
			else {
				if (input[i] == 'H') {
					visited[1]++;
				}
				else {
					visited[0]++;
				}
			}
		}
	}
	print();
}

int main() {
	scanf("%d", &p);
	for (int i = 0; i < p; i++) {
		scanf("%s", input);
		howmany();
		input[0] = '\0';
	}
}