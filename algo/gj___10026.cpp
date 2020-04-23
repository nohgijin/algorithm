#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

#pragma warning(disable:4996)
using namespace std;

class Pos {
public:
	int y;
	int x;
};

int N;
int normal = 0;
int special = 0;
int cnt = 0;
char input[110][110];
vector<Pos> v;
bool visited[110][110] = { false , };

void dfs(char rgb, Pos cur) {
	if (cur.y <= 0 || cur.x <= 0 || cur.y > N || cur.x > N) return;
	if (rgb != input[cur.y][cur.x]) return;
	if (visited[cur.y][cur.x]) return;
	visited[cur.y][cur.x] = true;
	dfs(rgb, { cur.y - 1,cur.x });
	dfs(rgb, { cur.y + 1,cur.x });
	dfs(rgb, { cur.y,cur.x - 1 });
	dfs(rgb, { cur.y,cur.x + 1 });
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &input[i][1]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			v.push_back({ i,j });
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) continue;
			dfs(input[i][j], { i,j });
			cnt++;
		}
	}


	normal = cnt;

	memset(visited, false, sizeof(visited));

	cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (input[i][j] == 'G') input[i][j] = 'R';
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) continue;
			dfs(input[i][j], { i,j });
			cnt++;
		}
	}

	special = cnt;

	printf("%d %d", normal, special);
}