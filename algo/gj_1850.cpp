#include <iostream>
#include <cstdlib>
#include <cmath>
typedef long long ll;
using namespace std;
#pragma warning(disable:4996)

ll A, B;
ll jinA = 0;
ll jinB = 0;
ll result;

ll gcd(ll A, ll B) {
	if (B == 0) return A;
	else return gcd(B, A%B);
}

int main() {
	scanf("%lld %lld", &A, &B);
	result = gcd(A, B);
	for (int i = 0; i < result; i++) printf("1");
	return 0;
}