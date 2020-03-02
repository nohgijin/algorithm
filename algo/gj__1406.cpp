#include <iostream>
#include <cstring>
#include <list>
using namespace std;

#pragma warning(disable:4996)
list<char> slist;
char input[600100];
char jinput[5];
char ins[600100];
int M;
int len;
list<char>::iterator iter;

void print() {
	for (iter = slist.begin(); iter != slist.end(); iter++) {
		cout << *iter;
	}
}

void dodo() {
	iter = slist.end();
	for (int i = 0; i < M; i++) {
		scanf(" %5[^\n]", jinput);
		if (jinput[0] == 'L') {
			if (slist.begin() == iter) continue;
			iter--;
		}
		else if (jinput[0] == 'D') {
			if (slist.end() == iter) continue;
			iter++;
		}
		else if (jinput[0] == 'B') {
			if (slist.begin() == iter) continue;
			iter = slist.erase(--iter);
		}
		else if (jinput[0] == 'P') {
			slist.insert(iter, jinput[2]);
		}
	}
}

int main() {
	scanf("%s", input);
	int len = strlen(input);
	for (int i = 0; i < len; i++) slist.push_back(input[i]);
	scanf("%d", &M);
	dodo();
	print();
}