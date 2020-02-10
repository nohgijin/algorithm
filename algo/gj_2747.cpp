#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning( disable : 4996 )
using namespace std;

vector<long long> stack;

void pibo(int n){
	long long sum = 0;
	for (int i = 0; i <= n; i++) {
		if (i <2) {
			stack.push_back(i);
		}
		else {
			sum=stack[0]+stack[1];
			stack[0] = stack[1];
			stack[1] = sum;
		}
	}
	printf("%lld", stack[1]);
}

int main() {
	int n;
	scanf("%d", &n);
	pibo(n);
	return 0;
}