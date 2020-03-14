#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int>m;
vector<int> v;
bool visited[100] = { 0, };
int sumi = 0;

void cls(int bfr, int depth, int mt) {
	int sz = v.size();
	for (int i = bfr; i < sz; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		int k = mt * v[i];
		sumi += k;
		if (depth < sz) cls(i + 1, depth + 1, k);
		visited[i] = false;
	}
}

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	for (auto it = clothes.begin(); it != clothes.end(); it++) {
		for (auto it2 = it->begin() + 1; it2 != it->end(); it2++) {
			if (m[*it2]) m[*it2]++;
			else m[*it2] = 1;
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		v.push_back(it->second);
	}
	cls(0, 0, 1);
	answer = sumi;
	return answer;
}