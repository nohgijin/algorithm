#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <climits>

#pragma warning(disable:4996)
using namespace std;

int input;

int main() {
	scanf("%d", &input);
	if (input % 3 == 1) {
		printf("%d", (input - 1) / 3);
	}
	else if (input % 3 == 2) {
		printf("%d", (input - 2) / 3);
	}
}