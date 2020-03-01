#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

deque<int> d;
int N;
char a[100100];
char tmp[100100];
int num;
int result;

void hi() {
	if (!strcmp(a, "pop_front")) {
		if (!d.empty()) { 
			result = d.front();
			d.pop_front(); 
		}
		else result = -1;
	}
	else if (!strcmp(a, "pop_back")) {
		if (!d.empty()) {
			result = d.back();
			d.pop_back();
		}
		else result = -1;
	}
	else if (!strcmp(a, "size")) {
		result = d.size();
	}
	else if (!strcmp(a, "empty")) {
		if (d.empty()) result = 1;
		else result = 0;
	}
	else if (!strcmp(a, "front")) {
		if (d.empty()) result = -1;
		else result = d.front();
	}
	else if (!strcmp(a, "back")) {
		if (d.empty()) result = -1;
		else result = d.back();
	}
	else if (a[5]=='b') {
		int len = strlen(a);
		for (int i = 10; i <= len; i++) tmp[i - 10] = a[i];
		num = atoi(tmp);
		d.push_back(num);
		return;
	}
	else if (a[5]=='f') {
		int len = strlen(a);
		for (int i =11; i <= len; i++) tmp[i - 11] = a[i];
		num = atoi(tmp);
		d.push_front(num);
		return;
	}
	printf("%d\n", result);
}

int main() {
	scanf("%d", &N);
	cin.ignore();
	for (int i = 0; i < N; i++) {
		cin.getline(a, 100100,'\n');
		hi();
	}
}