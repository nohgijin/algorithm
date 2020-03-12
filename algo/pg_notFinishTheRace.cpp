#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	int check;
	int j;
	int start = 0;

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	int psize = participant.size();
	int csize = completion.size();
	for (int i = 0; i < psize; i++) {
		j = start;
		check = 0;
		while (j < csize) {
			if (participant[i] == completion[j]) {
				start = j + 1;
				check = 1;
				break;
			}
			j++;
		}
		if (check == 0) {
			answer += participant[i];
		}
	}
	return answer;
}