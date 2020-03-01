#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int N;
int len;
char input[100100];
vector<char> v;
char jinput[600100];
vector<char> tmp;
int pt;

void dodo() {
	for (int i = 0; i <= N; i++) {
		jinput[0] = '\0';
		cin.getline(jinput, 600100);
		if (jinput[0] == 'L') {
			if (pt != 0) pt--;
		}
		else if (jinput[0] == 'D') {
			if (pt != len) pt++;
		}
		else if (jinput[0] == 'B') {
			if (pt == 0) continue;
			if (pt != 0) v[pt] = '0';
			pt--;
		}
		else if (jinput[0] == 'P') {
			int len = strlen(jinput);
			int jlen = strlen(jinput) - 2;
			int ctmp = 0;
			int vsize = v.size(); //아직 안추가된 사이즈
			for (int j = 0; j < jlen; j++) v.push_back(0); //스택에 추가
			int jvsize = v.size(); //추가된 사이즈(문자열 추가 길이)
			for (int j = pt + 1; j <= vsize; j++) {
				if (v[j] == '0' || v[j] == '\0') continue;
				tmp.push_back(v[j]);
				v[j] = '0';
			}
			for (int j = pt + 1; j <= pt + jlen; j++) { //문자열길이만큼
				v[j] = jinput[j - pt + 1]; //jlen 두번째 꺼 부터
			}
			ctmp = tmp.size();
			for (int j = pt + 1 + jlen; j < jvsize; j++) {
				if (ctmp > 0) v[j] = tmp[j - pt - 1 - jlen];
				ctmp--;
			}
			for (int j = 0; j < jlen; j++) pt++;
			tmp.clear();
		}
	}
}

int main() {
	scanf("%s", input);
	len = strlen(input);
	pt = len;
	v.push_back(0);
	for (int i = 0; i < len; i++) v.push_back(input[i]);
	scanf("%d", &N);
	dodo();
	int vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		if (v[i] != '0' && v[i] != '\0') printf("%c", v[i]);
	}
}