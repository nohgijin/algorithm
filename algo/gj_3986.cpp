#include <iostream>
#include <vector>
#include <string.h>

#pragma warning( disable : 4996 )
using namespace std;
vector<char> stack;
int N;
char good_word[100010];
int sum = 0;

void gw() {
	stack.clear();
	int len = strlen(good_word);
	stack.push_back(good_word[0]);
	for (int i = 1; i < len; i++) {
		if (!stack.empty())
		{
			char top = stack.back();
			if (top == good_word[i])
				stack.pop_back();
			else stack.push_back(good_word[i]);
		}
		else stack.push_back(good_word[i]);
	}
	if (stack.empty()) {
		sum++;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", good_word);
		gw();
	}
	printf("%d", sum);
}