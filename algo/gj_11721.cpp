#include <iostream>
#include <string.h>
using namespace std;
#pragma warning( disable : 4996 )

char input[110];

int main(void) {
	scanf("%s", input);
	int input_len = strlen(input);
	int a = 0;
	for (int i = 0; i < input_len; i++) {
		printf("%c", input[i]);
		a++;
		if (a == 10) {
			printf("\n");
			a = 0;
		}
	}

	return 0;
}