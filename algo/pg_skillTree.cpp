#include <string>
#include <vector>
#include <cstring>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int ssize = skill_trees.size();

	for (int i = 0; i < ssize; i++) {
		string skill_tree = skill_trees[i];

		int stlen = skill_tree.length();
		int slen = skill.length();
		bool possible = true;
		int cnt = 0;

		for (int j = 0; j < stlen; j++) {
			for (int k = 0; k < slen; k++) { //½ºÅ³
				if (skill_tree[j] == skill[k]) {

					if (k != cnt) {
						possible = false;
						break;
					}
					cnt++;

				}
			}
			if (!possible) break;
		}

		if (possible) answer++;

	}

	return answer;
}