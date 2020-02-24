#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int N, M;
int a, b;
int root, start;

vector<int> input[10100];
vector<int> output;
vector<int> result;

bool visited[10100] = { 0, };

void print() {
	int size = result.size();
	sort(result.begin(), result.end());
	for (int i = 0; i < size; i++) {
		printf("%d ", result[i]);
	}
}

void hack(int start) {
	int isize = input[start].size();
	for (int i = 0; i < isize; i++) {
		int child = input[start][i];
		if (visited[child]) continue;
		visited[child] = true;
		output.push_back(child);
		hack(child);
	}
}

int main() {
	int max = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &b, &a);
		input[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		output.clear();
		fill_n(visited, 10100, 0);
		root = i;
		output.push_back(root);
		visited[root] = true;
		hack(root);
		int size = output.size();
		if (max < size) {
			result.clear();
			max = size;
			result.push_back(root);
		}
		else if (max == size) result.push_back(root);
	}
	print();
}