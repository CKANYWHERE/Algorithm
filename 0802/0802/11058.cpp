#include "stdafx.h"
#include <iostream>
using namespace std;

int dp[101];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j <= i - 3; j++) {
			long long cur = dp[i - j - 2] * (j + 1);
			if (cur > dp[i])
				dp[i] = cur;
		}
	}
	cout << dp[n] << "\n";
	return 0;
}