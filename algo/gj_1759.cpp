#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int L, C;
int ja = 0;
int mo = 0;
int cnt = 0;
vector<char> input;
vector<char> output;
bool visited[40];

void print() {
	mo = 0;
	ja = 0;
	int osize = output.size();
	for (int i = 0; i < osize; i++) {
		char tt = output[i];
		if (tt == 'a' || tt == 'e' || tt == 'i' || tt == 'o' || tt == 'u') mo++;
		else ja++;
	}
	if (mo >= 1 && ja >= 2) {
		for (int i = 0; i < osize; i++) {
			printf("%c", output[i]);
		}
		printf("\n");
	}
}

void amho(int bfr, int depth) {
	for (int i = bfr + 1; i <= C; i++) {
		if (visited[input[i] - 97]) continue;
		visited[input[i] - 97] = true;
		output.push_back(input[i]);
		if (output.size() == L) print();
		if (depth < L) amho(i, depth + 1);
		visited[input[i] - 97] = false;
		output.pop_back();
	}
}

int main() {
	scanf("%d %d", &L, &C);
	input.push_back(0);
	for (int i = 0; i < C; i++) {
		char tmp;
		scanf(" %c", &tmp);
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	amho(0, 1);
}