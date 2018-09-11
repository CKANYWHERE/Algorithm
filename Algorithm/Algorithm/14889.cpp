#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[22][22];
int n,ans=987654321;

void go(int idx, vector<int>&first, vector<int>&second) {

	if (idx == n) {
		int t1=0, t2=0;
		for (int i = 0; i < first.size(); i++) {
			for (int j = i + 1; j < first.size(); j++) {
				t1 += arr[first[i]][first[j]] + arr[first[j]][first[i]];
			}
		}
		for (int i = 0; i < second.size(); i++) {
			for (int j = i + 1; j < second.size(); j++) {
				t2 += arr[second[i]][second[j]] + arr[second[j]][second[i]];
			}
		}
		int temp = abs(t1 - t2);
		ans = min(temp, ans);
		return;
	}

	first.push_back(idx);
	go(idx + 1, first, second);
	first.pop_back();
	
	second.push_back(idx);
	go(idx + 1, first, second);
	second.pop_back();

	return;

}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> first, second;
	go(0, first, second);
	cout << ans << "\n";
	return 0;
}