#include <stdio.h>
#include <iostream>
using namespace std;

#pragma warning(disable:4996)

int N;
int arr[5000][5000];
int main() {
	scanf("%d", &N);
	int r = 2;
	int x = 1;
	int y = 1;
	arr[1][1] = 1;
	if (N == 1) printf("1\n");
	while (N > 1) {
		if (x == 1) {
			int tmpy = y;
			y++;
			arr[x][y] = r;
			r++;
			N--;
			for (int i = tmpy; i >= 1; i--) {
				if (N > 1) {
					x++;
					y--;
					arr[x][y] = r;
					r++;
					N--;
				}
			}
		}
		else if (y == 1) {
			int tmpx = x;
			x++;
			arr[x][y] = r;
			r++;
			N--;
			for (int i = tmpx; i >= 1; i--) {
				if (N > 1) {
					x--;
					y++;
					arr[x][y] = r;
					r++;
					N--;
				}
			}
		}
	}
	printf("%d/%d", x, y);
}