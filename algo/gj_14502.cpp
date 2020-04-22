#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

class Pos {
public:
	int y;
	int x;
	int wallcnt = 0;
};

int N, M;
int map[10][10];
int copy_map[10][10];
bool visited[110] = { false, };
bool dfsvisited[10][10] = { false, };
int maxi = 0;
queue<Pos> wall;
vector<Pos> virus;
vector<Pos> empt;
vector<int> output;

void checkVirus() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0 && dfsvisited[i][j] == false) cnt++;
		}
	}
	maxi = maxi > cnt ? maxi : cnt;
}

void dfs(Pos A) {
	if (A.y <= 0 || A.x <= 0 || A.y > N || A.x > M) return;
	if (dfsvisited[A.y][A.x]) return;
	dfsvisited[A.y][A.x] = true;
	if (map[A.y][A.x] == 1) return;
	//if (map[A.y][A.x] == 2) return;
	//map[A.y][A.x] = 2;
	dfs({ A.y + 1, A.x });
	dfs({ A.y - 1, A.x });
	dfs({ A.y, A.x + 1 });
	dfs({ A.y, A.x - 1 });
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) empt.push_back({ i,j });
			if (map[i][j] == 2) virus.push_back({ i,j });
		}
	}

	int se = empt.size();

	for (int i = 0; i < se; i++) {
		for (int j = i + 1; j < se; j++) {
			for (int k = j + 1; k < se; k++) {
				map[empt[i].y][empt[i].x] = 1;
				map[empt[j].y][empt[j].x] = 1;
				map[empt[k].y][empt[k].x] = 1;
				int vs = virus.size();
				memset(dfsvisited, false, sizeof(dfsvisited));
				for (int p = 0; p < vs; p++) {
					dfs(virus[p]);
				}
				checkVirus();
				map[empt[i].y][empt[i].x] = 0;
				map[empt[j].y][empt[j].x] = 0;
				map[empt[k].y][empt[k].x] = 0;
			}
		}
	}
	printf("%d", maxi);
}