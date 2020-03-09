#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	bool visited[200100] = { false, };
	vector<int> result;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		if (visited[nums[i]]) continue;
		visited[nums[i]] = true;
		result.push_back(nums[i]);
	}
	answer = result.size();
	if (answer > len / 2) answer = len / 2;
	return answer;
}