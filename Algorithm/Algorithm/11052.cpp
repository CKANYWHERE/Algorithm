#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int p[100001];
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	dp[1] = p[1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], p[j] + dp[i - j]);
		}
	}

	cout << dp[n] << "\n";
	return 0;
}