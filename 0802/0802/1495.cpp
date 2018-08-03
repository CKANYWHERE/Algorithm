#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

bool dp[1001][1001];

int main() {
	vector<int> v;

	int n, s, m;
	cin >> n >> s >> m;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j] == false) {
				continue;
			}
			else if (dp[i][s + v[i]] <= m) {
				dp[i][s + v[i]] = true;
			}
			else if(dp[i][s - v[i]] >= 0){
				dp[i][s - v[i]] = true;
			}
		}
	}

	return 0;
}