#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
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

int N, M;
int mini = INT_MAX;
int input[55][55];
bool dfsvisited[55][55] = { false, };
vector<Pos> chicken;
vector<Pos> home;
vector<Pos> pick_chicken;
int dist = 0;

Pos P;

void distance(int y, int x) {
	int homemini = INT_MAX;
	//치킨집 하나씩 돈다.
	for (int i = 0; i < M; i++) {
		int homedist = abs(pick_chicken[i].y - y) + abs(pick_chicken[i].x - x);
		if (homemini > homedist) {
			homemini = homedist; //고른 치킨집간 최소거리
		}
	}
	dist += homemini;
}


void dfs(int index) {
	if (pick_chicken.size() == M) { //고른 치킨 사이즈가 최대 치킨집과 같으면
		dist = 0;
		int hs = home.size();
		//집 하나씩 돈다.
		for (int h = 0; h < hs; h++) {
			distance(home[h].y, home[h].x);
		}
		mini = mini > dist ? dist : mini;
		return;
	}
	if (index >= chicken.size()) return;
	if (dfsvisited[chicken[index].y][chicken[index].x]) return;
	dfsvisited[chicken[index].y][chicken[index].x] = true;
	pick_chicken.push_back({ chicken[index].y,chicken[index].x }); //선정한 치킨 들어감
	int cs = chicken.size();
	for (int i = index + 1; i < cs; i++)	dfs(i);
	dfsvisited[chicken[index].y][chicken[index].x] = false;
	pick_chicken.pop_back();
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input[i][j]);
			if (input[i][j] == 2) {
				chicken.push_back({ i,j }); //치킨 전체 들어감
			}
			else if (input[i][j] == 1) {
				home.push_back({ i,j }); //집 전체 들어감
			}
		}
	}

	int cs = chicken.size();
	for (int i = 0; i < cs; i++) {
		memset(dfsvisited, false, sizeof(dfsvisited));
		dfs(i); //치킨 있는거 dfs 돌림
	}
	printf("%d\n", mini);
}