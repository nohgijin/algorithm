#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> output;

int n;
int tmpa = 0;
int tmpb = 0;

int hindex(int h) {
	int tmpa = 0;
	for (int i = 0; i < n; i++) {
		if (output[i] >= h) tmpa++;
	}
	if (tmpa >= h) return h;
	return 0;
}

int solution(vector<int> citations) {
	int answer;
	answer = 0;
	n = citations.size();
	sort(citations.begin(), citations.end());
	for (int i = 0; i < n; i++) output.push_back(citations[i]);
	int nmax = citations[n - 1];
	for (int h = 0; h <= nmax; h++) {
		if (hindex(h)) answer = hindex(h);
	}
	return answer;
}