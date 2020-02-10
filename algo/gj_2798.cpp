#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning( disable : 4996 )

using namespace std;
int N, M;
vector <int> arr;
vector <int> sum;
vector <int> realsum;

void NM() {
	int tmpsum;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				tmpsum= arr[i] + arr[j] + arr[k];
				sum.push_back(tmpsum);
			}
		}
	}
	sort(sum.begin(), sum.end());
	
	for (int p = 0; p < sum.size(); p++) {
		if (sum[p]-M <= 0) {
			realsum.push_back(sum[p]);
		}
	}

	printf("%d", realsum.back());
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	NM();
}