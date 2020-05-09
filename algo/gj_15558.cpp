#include <stdio.h>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, k;

char ml[100010];
char mr[100010];
bool visited[100010] = { false, };

class Case {
public:
	bool pos; //¿Þt ¿Àf
	int cur; //ÇöÀçÄ­
	int sec = 0;
};

int bfs() {
	queue<Case> q;
	q.push({ true,1,0 });
	while (!q.empty()) {
		Case C;
		C = q.front();
		q.pop();
		if (C.cur <= 0) continue;
		if (C.cur > N) return 1;
		if (C.pos == true && ml[C.cur] == '0') continue;
		if (C.pos == false && mr[C.cur] == '0') continue;
		if (visited[C.cur]) continue;
		q.push({ C.pos,C.cur + 1,C.sec + 1 }); //ÇÑÄ­¾Õ
		q.push({ C.pos,C.cur - 1,C.sec + 1 }); //ÇÑÄ­µÚ
		q.push({ !C.pos,C.cur + k,C.sec + 1 }); //¹Ý´ëÁÙ Á¡ÇÁ
		visited[C.sec + 1] = true;
	}
	return 0;
}

int main() {
	scanf("%d %d", &N, &k);
	scanf("%s", &ml);
	scanf("%s", &mr);
	printf("%d", bfs());
}