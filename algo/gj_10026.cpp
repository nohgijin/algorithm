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
char copy_input[110][110];
vector<Pos> RGB;
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

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &input[i][1]);
	}

	for (int i = 1; i <= N; i++) { //일반인
		for (int j = 1; j <= N; j++) {
			RGB.push_back({ i,j });
		}
	}

	int rgbsz = RGB.size();

	for (int i = 0; i < rgbsz; i++) {
		if (visited[RGB[i].y][RGB[i].x]) continue;
		bfs_RGB(RGB[i]);
		area++;
	}

	RGB.clear();

	for (int i = 1; i <= N; i++) { //적록색약
		for (int j = 1; j <= N; j++) {
			if (input[i][j] == 'G') input[i][j] = 'R';
			RGB.push_back({ i,j });
		}
	}

	memset(visited, false, sizeof(visited));
	rgbsz = RGB.size();

	for (int i = 0; i < rgbsz; i++) {
		if (visited[RGB[i].y][RGB[i].x]) continue;
		bfs_RGB(RGB[i]);
		no_area++;
	}

	printf("%d %d", area, no_area);
}