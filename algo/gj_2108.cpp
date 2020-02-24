#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

int N;
int sum = 0;
vector<int>v;
vector<int>mv;
int visited[8100] = { 0, };

int average() {
	int avg;
	int size = v.size();
	for (int i = 0; i < size; i++) {
		sum += v[i];
	}
	float tmp = float(sum) / float(size);
	avg = round(tmp);
	return avg;
}

int midium() {
	int size = v.size();
	sort(v.begin(), v.end());
	int num = size / 2;
	return v[num];
}

int most() {
	int size = v.size();
	int max = 0;
	int result;
	sort(v.begin(), v.end());
	for (int i = 0; i < size; i++) v[i] += 3999;
	for (int i = 0; i < size; i++) visited[v[i]]++;
	for (int i = 0; i < 8100; i++) {
		if (max < visited[i]) {
			mv.clear();
			max = visited[i];
			mv.push_back(i - 3999);
		}
		else if (max == visited[i]) {
			mv.push_back(i - 3999);
		}
	}
	sort(mv.begin(), mv.end());
	int msize = mv.size();
	if (msize == 1) result = mv[0];
	else result = mv[1];
	return result;
}

int far() {
	int size = v.size();
	sort(v.begin(), v.end());
	int dis = v.back() - v.front();
	return dis;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	int avg = average();
	int mid = midium();
	int tmax = most();
	int dis = far();
	printf("%d\n%d\n%d\n%d\n", avg, mid, tmax, dis);

}