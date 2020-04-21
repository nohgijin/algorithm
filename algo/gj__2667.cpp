#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#pragma warning(disable:4996)

class Pos {
public:
	int y;
	int x;
};

int N;
int cnt = 0;
char input[30][30];
bool visited[30][30] = { false, };
vector<int> output;
vector<Pos> v;

void dfs(int y, int x) {
	if (y <= 0 || x <= 0 || y > N || x > N) return;
	if (visited[y][x]) return;
	visited[y][x] = true;
	if (input[y][x] == '0') return;
	cnt++;
	dfs(y, x + 1);
	dfs(y + 1, x);
	dfs(y, x - 1);
	dfs(y - 1, x);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &input[i][1]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (input[i][j] == '1') {
				v.push_back({ i,j });
			}
		}
	}

	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		if (visited[v[i].y][v[i].x]) continue;
		cnt = 0;
		dfs(v[i].y, v[i].x);
		output.push_back(cnt);
	}

	int os = output.size();
	printf("%d\n", os);
	sort(output.begin(), output.end());
	for (int i = 0; i < os; i++) {
		printf("%d\n", output[i]);
	}

}