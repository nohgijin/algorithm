#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;


int N;
int num[110];
vector<char> oper;
vector<char> resultOper;
bool visited[110] = { false, };
int maxi = INT_MIN;
int mini = INT_MAX;
int result;

void cal() {
	result = num[0];
	int os = resultOper.size();
	for (int i = 0; i < os; i++) {
		if (resultOper[i] == '+') result += num[i + 1];
		else if (resultOper[i] == '-') result -= num[i + 1];
		else if (resultOper[i] == '*') result *= num[i + 1];
		else result /= num[i + 1];
	}
}

void dfs(int start, int depth) {
	bool localVisited[1000] = { false, };
	resultOper.push_back(oper[start]);
	visited[start] = true;
	if (depth == N - 1) {
		cal();
		maxi = max(maxi, result);
		mini = min(mini, result);

	}
	else {
		for (int i = 0; i < N - 1; i++) {
			if (visited[i]) continue;
			if (localVisited[resultOper[i]]) continue;
			localVisited[resultOper[i]] = true;
			dfs(i, depth + 1);
		}
	}
	resultOper.pop_back();
	visited[start] = false;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 4; i++) {
		int tmp;
		scanf("%d", &tmp);
		while (tmp) {
			if (i == 0) oper.push_back('+');
			else if (i == 1) oper.push_back('-');
			else if (i == 2) oper.push_back('*');
			else oper.push_back('/');
			tmp--;
		}
	}

	for (int i = 0; i < N - 1; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i, 1);
	}

	printf("%d\n%d", maxi, mini);
}