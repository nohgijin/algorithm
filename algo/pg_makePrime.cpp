#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int sum = 0;
bool visited[1010] = { false, };
vector<int> output;
bool prime[1000100];
int cnt = 0;
int mmax;
void check() {
	fill_n(prime, 1000100, true);
	prime[1] = false;
	for (int i = 2; i <= 1000100; i++) {
		if (prime[i]) {
			for (int j = i + i; j <= 1000100; j = j + i) prime[j] = false;
		}
	}
}

void isprime(int bfr, int depth, vector<int> nums, int nsize) {
	for (int i = bfr; i < nsize; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		output.push_back(nums[i]);
		if (depth < 3) isprime(i + 1, depth + 1, nums, nsize);
		if (depth == 3) {
			int ssum = output[0] + output[1] + output[2];
			if (prime[ssum]) {
				cnt++;
			}
		}
		visited[i] = false;
		output.pop_back();
	}
}

int solution(vector<int> nums) {
	int answer = -1;
	int nsize = nums.size();
	sort(nums.begin(), nums.end());
	int len = nums.size();
	mmax = nums[len - 1];
	check();

	fill_n(visited, 1010, false);
	isprime(0, 1, nums, nsize);
	answer = cnt;
	return answer;
}