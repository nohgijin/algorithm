#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

int N;
vector<int> input;
vector<int> fq;
int visited[8100] = { 0, };

int avg() {
	double sumi = 0;
	for (int i = 0; i < N; i++) {
		sumi += input[i];
	}
	return round(sumi / (double)N);
}

int mid() {
	return input[N / 2];
}

int freq() {
	int maxi = INT_MIN;
	for (int i = 0; i < N; i++) {
		visited[input[i] + 4000]++;
	}
	for (int i = 0; i < 8100; i++) {
		if (visited[i]) {
			if (maxi < visited[i]) {
				if (!fq.empty()) fq.clear();
				fq.push_back(i - 4000);
				maxi = visited[i];
			}
			else if (maxi == visited[i]) {
				fq.push_back(i - 4000);
			}
		}
	}

	if (fq.size() == 1) return fq.front();
	else return fq[1];
}

int ran() {
	int maxi = INT_MIN;
	int mini = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (maxi < input[i]) maxi = input[i];
		if (mini > input[i]) mini = input[i];
	}
	return maxi - mini;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());

	printf("%d\n", avg());
	printf("%d\n", mid());
	printf("%d\n", freq());
	printf("%d\n", ran());
}