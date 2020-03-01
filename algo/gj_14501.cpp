#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int N;
int t, p;
int sum = 0;
int day;
pair<int, int> a[20];
vector<int> v;
int maxint = 0;
bool visited[20] = { false, };
int daum = 1;

void maxi() {
	sum = 0;
	int vsize = v.size();
	for (int i = 0; i < vsize; i++) sum += v[i];
	maxint = (maxint > sum) ? maxint : sum;
}

void count(int day) {
	for (int i = day; i <= N; i++) {
		int daum = i + a[i].first;
		if (visited[i]) continue;
		if (daum > N + 1) continue; //다음날이 넘을때 제외
		visited[i] = true;
		v.push_back(a[i].second);
		maxi();
		count(daum); //7보다 작으면 다 감
		visited[i] = false;
		v.pop_back();
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &t, &p);
		a[i] = { t,p };
	}

	count(1);

	printf("%d", maxint);
}