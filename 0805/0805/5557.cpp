#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

long long dp[101][21];

int main() {
	int n;
	cin >> n;
	n -= 1;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int goal;
	cin >> goal;
	dp[0][arr[0]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - arr[i] >= 0)
				dp[i][j]+=dp[i - 1][j - arr[i]];
			if (j + arr[i] <= 20)
				dp[i][j]+=dp[i - 1][j + arr[i]];
		}
	}
	cout << dp[n-1][goal] << "\n";
	return 0;
}