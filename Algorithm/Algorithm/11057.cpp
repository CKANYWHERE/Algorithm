#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001][10];
long long mod = 10007;
int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
	}
	ans %= mod;
	cout << ans << "\n";
	return 0;
}