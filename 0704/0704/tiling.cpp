#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dp[1010];

int main() {
	int n;
	dp[0] = 1;
	dp[1] = 1;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + (dp[i - 2] * 2) %10007;
	}

	cout << dp[n]%10007 << "\n";

	return 0;
}