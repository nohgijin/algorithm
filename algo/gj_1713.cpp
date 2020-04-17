#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int N;
int rec;
vector<int> v;
vector<pair<int, int>> output;
bool chk = false;
bool allsame = true;
int mini;

int main() {
	scanf("%d", &N);
	scanf("%d", &rec);
	for (int i = 0; i < rec; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp); //추천된 학생들 명단 들어감
	}
	for (int i = 0; i < rec; i++) {
		allsame = true;
		if (output.size() < N) {
			int os = output.size();
			chk = false;
			for (int j = 0; j < os; j++) {
				if (output[j].first == v[i]) {
					output[j].second++;
					chk = true;
				}
				if (chk == false) {
					output.push_back(make_pair(v[i], 1));
				}
			}
		}
		else { //N이상으로 갈 경우
			chk = false;
			mini = output[0].second;
			for (int j = 0; j < N; j++) {
				if (output[j].first == v[i]) { // 안에 있으면
					output[j].second++; //더해주고
					chk = true; //안에 있는거 체크
				}
				if (mini != output[j].second)//안에 있는거 모두 같은지 체크
				{
					if (mini > output[j].second) mini = output[j].second;
				}
			}

			if (chk == false) { //안에 같은게 없다.
				mini = output[0].second;
				int idx = 0;
				for (int p = 0; p < N; p++) {
					if (mini > output[i].second) {
						idx = p;
						mini = output[i].second;
					}
				}
				for (int p = idx; p < N - 1; p++) {
					output[p] = output[p + 1];
				}
				output[N - 1].first = v[i];
				output[N - 1].second = 1;
			}

		}
	}
	sort(output.begin(), output.end());
	for (int i = 0; i < output.size(); i++) printf("%d ", output[i].first);
}