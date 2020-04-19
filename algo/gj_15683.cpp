#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
#pragma warning(disable:4996)

class pos {
public:
	int y;
	int x;
};

#define RIGHT 1
#define BOTTOM 2
#define LEFT 3
#define UP 4

int N, M;
int mini = INT_MAX;
char office[10][10];
vector<pos> cctv_pos;

void printOffice();

void nonSeeCheck() {
	int sumi = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (office[i][j] == '0') sumi++;
		}
	}
	//if (mini > sumi) printOffice();
	mini = (mini > sumi) ? sumi : mini;
}

void printOffice() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%c", office[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void detect(int y, int x, int direction) {
	//감지 지역 채우기
	if (x <= 0 || y <= 0 || x > M || y > N) return;
	if (office[y][x] == '6') return;

	if (office[y][x] == '0') {
		office[y][x] = '#'; //cctv 안가림
	}

	if (direction == RIGHT) {
		detect(y, x + 1, RIGHT);
	}
	else if (direction == BOTTOM) {
		detect(y + 1, x, BOTTOM);
	}
	else if (direction == LEFT) {
		detect(y, x - 1, LEFT);
	}
	else if (direction == UP) {
		detect(y - 1, x, UP);
	}
}

void dfs(int idx) {
	//cctv 있는 곳 크기 넘어가는 경우
	if (idx >= cctv_pos.size()) {
		//		printOffice();
		nonSeeCheck();
		return;
	}
	//printOffice();

	int y = cctv_pos[idx].y;
	int x = cctv_pos[idx].x;


	char cpy_office[10][10];
	//아닌 경우

	memcpy(cpy_office, office, sizeof(office));

	if (office[y][x] == '1') { //한방향일경우
		detect(y, x, RIGHT);
		dfs(idx + 1); // 오른쪽으로만 다 채웠고, 그러면 아래도 채워야함.
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, BOTTOM);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, LEFT);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, UP);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));
	}
	else if (office[y][x] == '2') { //양방향일경우
		detect(y, x, RIGHT);
		detect(y, x, LEFT);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, BOTTOM);
		detect(y, x, UP);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));
	}
	else if (office[y][x] == '3') { //직각방향일경우
		detect(y, x, UP);
		detect(y, x, RIGHT);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, RIGHT);
		detect(y, x, BOTTOM);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, BOTTOM);
		detect(y, x, LEFT);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, LEFT);
		detect(y, x, UP);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));
	}
	else if (office[y][x] == '4') { //세방향일경우
		detect(y, x, LEFT);
		detect(y, x, UP);
		detect(y, x, RIGHT);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, UP);
		detect(y, x, RIGHT);
		detect(y, x, BOTTOM);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, RIGHT);
		detect(y, x, BOTTOM);
		detect(y, x, LEFT);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));

		detect(y, x, BOTTOM);
		detect(y, x, LEFT);
		detect(y, x, UP);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));
	}
	else if (office[y][x] == '5') { //네방향일경우
		detect(y, x, RIGHT);
		detect(y, x, LEFT);
		detect(y, x, BOTTOM);
		detect(y, x, UP);
		dfs(idx + 1);
		memcpy(office, cpy_office, sizeof(cpy_office));
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %c", &office[i][j]);
			//cctv 있는 곳 좌표 넣기
			if (office[i][j] >= '1' && office[i][j] <= '5') cctv_pos.push_back({ i,j });
		}
	}
	dfs(0);
	printf("%d", mini);
}