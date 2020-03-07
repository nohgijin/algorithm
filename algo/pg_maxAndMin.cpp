#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int res;
vector<int> output;
char tmp[1000000];

string solution(string s) {
	string answer = "";
	int len = s.length();
	for (int i = 0; i < len; i++) {
		strcpy(tmp, "");
		int t = 0;
		if (s[i] == ' ') continue;
		else {
			while (true) {
				tmp[t] = s[i];
				if ((i == len - 1) || (s[i + 1] == ' ')) {
					break;
				}
				i++;
				t++;
			}
			tmp[t + 1] = '\0';
			res = atoi(tmp);
			output.push_back(res);
		}
	}
	sort(output.begin(), output.end());
	string first = to_string(output.front());
	string second = to_string(output.back());
	answer = first + " " + second;
	return answer;
}