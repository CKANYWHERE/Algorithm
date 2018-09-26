
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s[20][20];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	int ans = -1;
	for (int i = 0; i < (1 << n); i++) {
		vector<int> first, second;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				first.push_back(j);
			}
			else {
				second.push_back(j);
			}
		}
		if (first.size() != n / 2) continue;
		int t1 = 0;
		int t2 = 0;
		for (int l1 = 0; l1 < n / 2; l1++) {
			for (int l2 = 0; l2 < n / 2; l2++) {
				if (l1 == l2) continue;
				t1 += s[first[l1]][first[l2]];
				t2 += s[second[l1]][second[l2]];
			}
		}
		int diff = t1 - t2;
		if (diff < 0) diff = -diff;
		if (ans == -1 || ans > diff) {
			ans = diff;
		}
	}
	cout << ans << '\n';
}