#include "pch.h"
#include <iostream>
using namespace std;

int dp[91][2];

int main() {
	int n;
	cin >> n;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	} 
	cout << dp[n][1] << "\n";
	return 0;
}