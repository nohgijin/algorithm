#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int L, C;
char input[100];
bool visited[100] = { false, };
vector<char> v;
vector<char> output;

void printo() {
	int os = output.size();
	for (int i = 0; i < os; i++) printf("%c", output[i]);
	printf("\n");
}

void chk() {
	int mo = 0, ja = 0;
	int os = output.size();
	for (int i = 0; i < os; i++) {
		if (output[i] == 'a' || output[i] == 'e' || output[i] == 'i' || output[i] == 'o' || output[i] == 'u') mo++;
		else ja++;
	}
	if (mo >= 1 && ja >= 2) printo();
}

void dfs(int start, int depth) {
	for (int i = start; i < C; i++) {
		if (visited[i]) continue;
		output.push_back(v[i]);
		visited[i] = true;
		if (depth != L) dfs(i + 1, depth + 1);
		else chk();
		visited[i] = false;
		output.pop_back();
	}
}

int main() {
	scanf("%d %d", &L, &C);
	scanf(" %[^\n]", input);
	int len = strlen(input);
	for (int i = 0; i < len; i++) {
		if (input[i] != ' ') v.push_back(input[i]);
	}
	sort(v.begin(), v.end());
	dfs(0, 1);
}