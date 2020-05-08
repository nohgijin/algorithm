#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int S;
bool visited[1005][1005] = { false, };

class Case {
public:
	int cnt = 1; //화면 표시 이모티콘 개수
	int time = 0; //누적시간
	int clip = 0; //복사한 이모티콘
};

int bfs() {
	queue<Case> q;
	q.push({ 1,0,0 });
	while (!q.empty()) {
		Case C = q.front();
		if (C.cnt == S) return C.time;
		q.pop();
		if (C.cnt < 0 || C.cnt >1000) continue;
		if (visited[C.cnt][C.clip]) continue;
		visited[C.cnt][C.clip] = true;
		q.push({ C.cnt,C.time + 1,C.cnt }); //클립보드에 복사
		q.push({ C.cnt - 1,C.time + 1,C.clip }); //화면에 있는거 삭제
		if (C.clip == 0) continue;
		q.push({ C.cnt + C.clip,C.time + 1,C.clip }); //클립보드를 붙여넣기
	}
}

int main() {
	scanf("%d", &S);
	printf("%d", bfs());
}