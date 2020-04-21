#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

class Pos {
public:
	int y;
	int x;
	int dist = 0;
};

int N;
char input[30][30];
bool visited[30][30] = { false, };
queue<Pos> Q;
vector<int> output;
vector<Pos> target;

void distance(Pos A) {
	Q.push(A);
	//memset(visited, false, sizeof(visited));
	int cnt = 0;
	while (!Q.empty()) {
		Pos P = Q.front();
		Q.pop();
		if (P.y <= 0 || P.x <= 0 || P.y > N || P.x > N) continue;
		if (input[P.y][P.x] == '0') continue;
		if (visited[P.y][P.x]) continue;
		visited[P.y][P.x] = true;
		cnt++;
		Q.push({ P.y + 1, P.x });
		Q.push({ P.y - 1, P.x });
		Q.push({ P.y, P.x + 1 });
		Q.push({ P.y, P.x - 1 });
	}
	output.push_back(cnt);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &input[i][1]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (input[i][j] == '1') {
				if (visited[i][j]) continue;
				distance({ i,j });
			}
		}
	}

	int os = output.size();
	printf("%d\n", os);
	sort(output.begin(), output.end());
	for (int i = 0; i < os; i++) {
		printf("%d\n", output[i]);
	}

}