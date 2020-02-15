#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#pragma warning( disable : 4996 )
char input[1000100];

int main() {
	cin.getline(input, 1000100, '\n');
	int input_len = strlen(input);
	int sum = 0;
	if ((input_len == 1) && (input[0] != ' ')) {
		sum = 1;
		printf("%d", sum);
		return 0;
	}
	for (int i = 1; i < input_len; i++) {
		if (i == 1) sum = 1;
		if ((input[i] == ' ') && (i != input_len - 1)) sum++;
	}
	printf("%d", sum);
}
