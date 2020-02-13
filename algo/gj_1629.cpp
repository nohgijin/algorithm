#include <stdio.h>
#include <iostream>
#include <map>
#pragma warning( disable : 4996 )

using namespace std;

typedef long long ll;
ll result;
map<ll, ll> cache;

ll mod(ll A, ll B, ll C) {
	if (cache[B]) return cache[B];
	if (B == 0) result = 1;
	else if (B == 1) result = A;
	else if (B % 2 == 1) result = mod(A, (B + 1) / 2, C)*mod(A, (B - 1) / 2, C);
	else if (B % 2 == 0) result = mod(A, B / 2, C)*mod(A, B / 2, C);
	cache[B] = result % C;
	return cache[B];
}

int main() {
	ll A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);
	ll jinresult = mod(A, B, C);
	printf("%lld", jinresult);
	return 0;
}