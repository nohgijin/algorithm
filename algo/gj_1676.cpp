#include <iostream>
using namespace std;
typedef long long ll;
#pragma warning(disable:4996)

int N;
int five = 0;
int two = 0;
int cnt;

int main() {
	scanf("%d", &N);
	while (N >= 5) {
		five += N / 5;
		N = N / 5;
	}
	printf("%d", five);
}
