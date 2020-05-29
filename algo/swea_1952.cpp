#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>

#pragma warning(disable:4996)

using namespace std;

int day, oMonth, tMonth, year;
vector<int> plan;
vector<int> dfsPlan;
bool visited[15] = { false, };
int result;
int answer = INT_MAX;
int month;

void show() {
	bool chk = false;
	printf("\n");
	int ps = dfsPlan.size();
	for (int i = 0; i < ps; i++) {
		printf("%d ", dfsPlan[i]);
	}
	printf("\n");
}

int cal() {
	int mth = 0;
	int calResult = 0;
	int ps = dfsPlan.size();

	for (int i = 0; i < ps; i++) {
		if (dfsPlan[i] == 1) {
			calResult += plan[mth] * day;
			mth++;
		}
		else if (dfsPlan[i] == 2) {
			calResult += oMonth;
			mth++;
		}
		else if (dfsPlan[i] == 3) {
			calResult += tMonth;
			mth += 3;
		}
		else if (dfsPlan[i] == 4) {
			calResult += year;
			mth += 12;
		}
	}

	return calResult;
}

void dfs(int start, int depth) {
	dfsPlan.push_back(start);
	if (depth < month) {
		for (int i = 1; i <= 4; i++) {
			if (i == 1 || i == 2) {
				dfs(i, depth + 1);
			}
			else if (i == 3) {
				dfs(i, depth + 3);
			}
			else if (i == 4) {
				dfs(i, depth + 12);
			}
		}
	}
	else {
		//		show();
		answer = min(answer, cal());
	}
	dfsPlan.pop_back();
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		answer = INT_MAX;
		scanf("%d %d %d %d", &day, &oMonth, &tMonth, &year);
		plan.clear();
		bool chk = false;
		for (int i = 0; i < 12; i++) {
			int t;
			scanf("%d", &t);
			if (t == 0 && !chk) continue;
			else {
				chk = true;
				plan.push_back(t);
			}
		}

		int ps = plan.size();
		for (int i = ps - 1; i >= 0; i--) {
			if (plan[i] == 0) plan.pop_back();
			else break;
		}

		month = plan.size();

		for (int i = 1; i <= 4; i++) {
			if (i == 1 || i == 2) {
				dfs(i, 1);
			}
			else if (i == 3) {
				dfs(i, 3);
			}
			else if (i == 4) {
				dfs(i, 12);
			}
		}
		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}