#include stdio.h
#include iostream
#include vector
#include algorithm
#pragma warning( disable  4996 )

using namespace std;

#define MAX_N 50+1
#define MIN_N 2

int arr[MAX_N][MAX_N] = { 0, };
int result[MAX_N] = { 0, };
int N;

void dung() {

	for (int i = 0; i  N; i++) {
		for (int j = 0; j  N; j++) {
			if ((arr[i][0]  arr[j][0]) && (arr[i][1]  arr[j][1])) {
				result[i] += 1;
			}
		}
	}

	for (int k = 0; k  N; k++) {
		printf(%d , result[k]+1);
	}
}

int main() {
	scanf(%d, &N);
	for (int i = 0; i  N; i++) {
		int x, y;
		scanf(%d %d, &x, &y);
		arr[i][0] = x;
		arr[i][1] = y;
	}
	dung();
	return 0;
}