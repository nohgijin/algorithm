#include <iostream>
#include <map>
using namespace std;
#pragma warning(disable:4996)

map<long long, long long> m;
long long max_value = 0;
long long max_key = 0;

int main() {
	long long N;
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		if (m[tmp]) m[tmp]++;
		else m[tmp] = 1;
		if (max_value == m[tmp]) {
			max_key = max_key < tmp ? max_key : tmp;
		}
		else if (max_value < m[tmp]) {
			max_value = m[tmp];
			max_key = tmp;
		}
	}
	printf("%lld", max_key);
}