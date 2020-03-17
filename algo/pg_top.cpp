#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	vector<int> tanswer;
	int sz = heights.size();
	for (int i = sz - 1; i >= 0; i--) {
		int j = i - 1;
		if (j == -1) { //마지막 예외처리
			tanswer.push_back(0);
			break;
		}
		int chk = 1; //없는 경우 체크
		while (j >= 0) {
			if (heights[i] < heights[j]) {
				tanswer.push_back(j + 1);
				chk = 0;
				break;
			}
			else j--;
		}
		if (chk == 1) tanswer.push_back(0);
	}
	for (int i = sz - 1; i >= 0; i--) {
		answer.push_back(tanswer[i]);
	}
	return answer;
}