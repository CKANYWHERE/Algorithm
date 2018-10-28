#include "pch.h"
#include <iostream>
using namespace std;
int dp[1005][1005];
const int MOD = 1000000003;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) dp[i][1] = i;
	for (int i = 1; i <= n; i++) dp[i][0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << (dp[n-3][m-1]+dp[n-1][m]) % MOD << "\n";

	return 0;
} 