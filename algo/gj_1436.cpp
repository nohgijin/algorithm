#include <iostream>
#include <algorithm>
#include <string>
#pragma warning( disable : 4996 )
using namespace std;

int N;

int main() {
	int a = 0;

	scanf("%d", &N);

	while (true) {
		string tmp = to_string(a);
		if (tmp.find("666") != string::npos) {
			N--;
			if (N == 0) break;
		}
		a++;
	}

	printf("%d", a);
}