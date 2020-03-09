#include <string>
#include <cstring>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int slen = s.length();
	char tmp;
	char ck;
	tmp = s[0];
	if (tmp >= 97 && tmp <= 122) {
		tmp -= 32;
	}
	answer += tmp;
	for (int i = 1; i < slen; i++) {
		tmp = s[i];
		ck = s[i - 1];
		if (ck == 32) {
			if (tmp >= 97 && tmp <= 122) {
				tmp -= 32;
			}
			answer += tmp;
		}
		else {
			if (tmp >= 65 && tmp <= 90) {
				tmp += 32;
			}
			answer += tmp;
		}
	}
	return answer;
}