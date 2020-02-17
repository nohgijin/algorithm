#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
#pragma warning( disable : 4996 )

int N;
char input[100100];
int result;

queue<int> q;

void NQ() {
	int input_len = strlen(input);

	if (input[1] == 'u') {
		/*string number = "";
		for (int i = 5; i < input_len; i++) {
			number += input[i];
		}*/
		q.push(atoi(input + 5));
	}

	else if (input[0] == 'p') {
		if (!q.empty()) {
			result = q.front();
			q.pop();
		}
		else result = -1;
	}

	else if (input[0] == 's') {
		result = q.size();
	}

	else if (input[0] == 'e') {
		if (q.empty()) result = 1;
		else result = 0;
	}

	else if (input[0] == 'f') {
		if (q.empty()) result = -1;
		else result = q.front();
	}

	else if (input[0] == 'b') {
		if (q.empty()) result = -1;
		else result = q.back();
	}
}

int main(void) {
	scanf("%d", &N);

	cin.ignore();

	for (int i = 0; i < N; i++) {
		scanf(" %[^\n]", input);
		NQ();
		if (input[1] == 'u') continue;
		printf("%d\n", result);
	}
	return 0;
}