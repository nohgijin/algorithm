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
int no_area = 0;
int area = 0;
char input[110][110];
vector<Pos> RG;
vector<Pos> RGB;
vector<Pos> B;
bool visited[110][110] = { false , };

void bfs_RGB(Pos A) { //빨강파랑초록
	queue<Pos> Q;
	Q.push(A);
	while (!Q.empty()) {
		Pos P = Q.front();
		Q.pop();
		if (P.y <= 0 || P.x <= 0 || P.y > N || P.x > N) continue;
		if (input[P.y][P.x] != input[A.y][A.x]) continue;
		if (visited[P.y][P.x]) continue;
		visited[P.y][P.x] = true;
		Q.push({ P.y + 1, P.x });
		Q.push({ P.y - 1, P.x });
		Q.push({ P.y , P.x + 1 });
		Q.push({ P.y , P.x - 1 });
	}
}

void bfs_B(Pos A) { //파랑
	queue<Pos> Q;
	Q.push(A);
	while (!Q.empty()) {
		Pos P = Q.front();
		Q.pop();
		if (P.y <= 0 || P.x <= 0 || P.y > N || P.x > N) continue;
		if (input[P.y][P.x] == 'R' || input[P.y][P.x] == 'G') continue;
		if (visited[P.y][P.x]) continue;
		visited[P.y][P.x] = true;
		Q.push({ P.y + 1, P.x });
		Q.push({ P.y - 1, P.x });
		Q.push({ P.y , P.x + 1 });
		Q.push({ P.y , P.x - 1 });
	}
}

void bfs_RG(Pos A) { //빨강초록
	queue<Pos> Q;
	Q.push(A);
	while (!Q.empty()) {
		Pos P = Q.front();
		Q.pop();
		if (P.y <= 0 || P.x <= 0 || P.y > N || P.x > N) continue;
		if (input[P.y][P.x] == 'B') continue;
		if (visited[P.y][P.x]) continue;
		visited[P.y][P.x] = true;
		Q.push({ P.y + 1, P.x });
		Q.push({ P.y - 1, P.x });
		Q.push({ P.y , P.x + 1 });
		Q.push({ P.y , P.x - 1 });
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &input[i][1]);
	}

	for (int i = 1; i <= N; i++) { //적록색약
		for (int j = 1; j <= N; j++) {
			if (input[i][j] == 'R' || input[i][j] == 'G') {
				RG.push_back({ i,j }); //적록
			}
			else B.push_back({ i,j }); //파란
		}
	}
	int rgs = RG.size();
	for (int i = 0; i < rgs; i++) { //적록 for문
		if (visited[RG[i].y][RG[i].x]) continue;
		bfs_RG({ RG[i].y,RG[i].x });
		no_area++; //적록보는지역
	}

	memset(visited, false, sizeof(visited));
	int bs = B.size();
	for (int i = 0; i < bs; i++) { //파란 for문
		if (visited[B[i].y][B[i].x]) continue;
		bfs_B({ B[i].y,B[i].x });
		no_area++; //파란보는지역
	}

	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			RGB.push_back({ i,j }); //정상인
		}
	}
	int rgbs = RGB.size();
	for (int i = 0; i < rgbs; i++) { //정상인 for문
		if (visited[RGB[i].y][RGB[i].x]) continue;
		bfs_RGB({ RGB[i].y,RGB[i].x });
		area++;
	}

	printf("%d %d", area, no_area);
}