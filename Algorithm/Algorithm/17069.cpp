#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[33][33][3];
int board[33][33];
int n;
long long ans = 0;

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	dp[0][1][0] = 1;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i < 0 || j < 0 || i >= n || j >= n)
				continue;
			
			if (board[i][j] != 0)
				continue;
		
			if (board[i][j + 1] != 1) {
				dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
				//cout << "dp[i][j][0]" << dp[i][j][0] << "\n";
			}
			if (board[i + 1][j] != 1) {
				dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];
				//cout << "dp[i][j][1]" << dp[i][j][1] << "\n";
			}
			if (board[i + 1][j] != 1 && board[i][j + 1] != 1) {
				dp[i + 1][j + 1][2] += dp[i][j][2] + dp[i][j][1] + dp[i][j][0];
				//cout << "dp[i][j][2]" << dp[i][j][2] << "\n";
			}
		}
	}
	ans = dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
	cout << ans << "\n";
	return 0;
}