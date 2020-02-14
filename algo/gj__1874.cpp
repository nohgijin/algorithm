#include <iostream>
#include <vector>
using namespace std;

#pragma warning( disable : 4996 )
int n;
vector<int> stack;
char res[200200];

int main() {
	scanf("%d", &n);
	int num = 1;
	int index = 0;
	for (int i = 1; i <= n; i++) {
		int turn;
		scanf("%d", &turn);
		while (num <= turn) {
			stack.push_back(num);
			num++;
			res[index] = '+';
			index++;
		}
		int top = stack.back();
		if (top == turn) {
			stack.pop_back();
			res[index] = '-';
			index++;
		}
		else {
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < index; i++) {
		printf("%c\n", res[i]);
	}
	return 0;
}