#include <iostream>
#define min(a,b) (a<b?a:b)
using namespace std;
typedef long long ll;
#pragma warning(disable:4996)

int n, m;
int two = 0;
int five = 0;

int twoCount(int num) {
	int count = 0;
	for (ll i = 2; num / i >= 1; i *= 2) count += num / i;
	return count;
}

int fiveCount(int num) {
	int count = 0;
	for (ll i = 5; num / i >= 1; i *= 5) count += num / i;
	return count;
}

int main() {
	scanf("%d %d", &n, &m);

	five += fiveCount(n);
	if (m != 0)five -= fiveCount(m);
	if (n != m)five -= fiveCount(n - m);

	two += twoCount(n);
	if (m != 0)two -= twoCount(m);
	if (n != m)two -= twoCount((n - m));

	printf("%d\n", min(two, five));
}