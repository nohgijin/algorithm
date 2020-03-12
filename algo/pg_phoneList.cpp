#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	int len = a.length();
	int check = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] == b[i] && i == len - 1) check = 1; //접두사
		if (a[i] == b[i]) continue;
		else break;
	}
	if (check) return false; //접두사면
	return true;
}

bool solution(vector<string> phone_book) {
	bool answer = true;
	int psize = phone_book.size();
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < psize; i++) {
		string a = phone_book[i];
		for (int j = i + 1; j < psize; j++) {
			string b = phone_book[j];
			bool tmp = cmp(a, b); //접두사면 false
			if (!tmp) {
				answer = false;
				break;
			}
		}
		if (answer == false) break;
	}
	return answer;
}