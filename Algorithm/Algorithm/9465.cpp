#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001][2];
int dp[100001][3];

int main() {

	int T;
	cin >> T;
	while (T--) {

		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i][0];
		}

		for (int i = 1; i <= n; i++) {
			cin >> arr[i][1];
		}

		for (int i = 1; i <= n; i++) {
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2])+arr[i][0];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1])+arr[i][1];
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(max(ans, dp[i][0]), max(dp[i][1], dp[i][2]));
		}

		cout << ans << "\n";
	}

	return 0;
}