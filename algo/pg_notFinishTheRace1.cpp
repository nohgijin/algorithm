string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	// 선수이름, 선수 수
	map<string, int> m;

	for (auto it = completion.begin(); it != completion.end(); it++) {
		if (!m[*it]) m[*it] = 1;
		else m[*it]++;
	}

	for (auto it = participant.begin(); it != participant.end(); it++) {
		if (!m[*it]) {
			answer = *it;
			break;
		}
		m[*it]--;
	}

	return answer;
}
