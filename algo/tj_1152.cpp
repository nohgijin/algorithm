#include <iostream>
#include <string.h>
using namespace std;

int main(void) {

	char str[1000010];

	int cnt = 0;
	int tmp = 0;

	cin.getline(str, 1000010, '\n');

	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			if (tmp > 0)cnt++;
			tmp = 0;
		}
		else tmp++;
	}

	if (tmp > 0)cnt++;

	printf("%d", cnt);

	return 0;
}