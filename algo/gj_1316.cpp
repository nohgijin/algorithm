#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N;
char input[110];
int visited[50] = { 0, };
bool chk = false;
int cnt = 0;
vector<char> v;


int main() {
	int cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		v.clear();
		chk = false;
		memset(visited, false, sizeof(visited));
		scanf("%s", input);
		int len = strlen(input);
		for (int j = 0; j < len; j++) {
			if (j == 0) {
				v.push_back(input[j]);
				continue;
			};
			if (input[j] == input[j - 1]) continue;
			v.push_back(input[j]);
		}
		int vs = v.size();
		for (int j = 0; j < vs; j++) {
			if (visited[v[j] - 'a'] >= 1) {
				chk = true;
				break;
			}
			visited[v[j] - 'a']++;
		}
		if (chk == false) cnt++;
	}
	printf("%d", cnt);
}