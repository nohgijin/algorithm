#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int N;
bool visited[10100] = { false, };
vector<int> s;

void print() {
	int len = s.size();
	for (int i = 0; i < len; i++) printf("%d ", s[i]);
	printf("\n");
}

void sun2(int depth)
{
	if (depth > N) print();
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		s.push_back(i);
		sun2(depth + 1);
		visited[i] = false;
		s.pop_back();
	}
}
int main() {
	scanf("%d", &N);
	sun2(1);
}