#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#pragma warning( disable : 4996 )

using namespace std;
int a = 0, N;
int arr_stack[10001] = { 0, };

char tmp[101];

void stack() {
	if (tmp[1] == 'u') {
		// printf("%s\n",tmp);
		string text = strstr(tmp, " ");
		// printf("%s\n",text.c_str());
		int num = atoi(text.c_str());
		// printf("num %d\n",num);
		arr_stack[a] = num;
		a++;
		// printf("a%d %d\n",a,arr_stack[a-1]);
	}
	else if (tmp[0] == 'p') {
		if (a == 0) printf("-1\n");
		else {
			printf("%d\n", arr_stack[a - 1]);
			arr_stack[a - 1] = 0;
			a--;
		}
	}
	else if (tmp[0] == 's') {
		printf("%d\n", a);
	}
	else if (tmp[0] == 'e') {
		if (a == 0) printf("1\n");
		else printf("0\n");
	}
	else if (tmp[0] == 't') {
		if (a == 0) printf("-1\n");
		else printf("%d\n", arr_stack[a - 1]);
	}
}

int main() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		cin.getline(tmp, 100, '\n');
		stack();
	}
	return 0;
}