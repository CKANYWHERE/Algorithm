#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001];
int main() {

	int n;
	cin >> n;
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if (dp[i % 3] == 0) {
			dp[i] = dp[i / 3] + 1;
		}

		if (dp[i % 2] == 0) {
			dp[i] = dp[i / 2] + 1;
		}

	}
	cout << dp[n] << "\n";

	return 0;
}