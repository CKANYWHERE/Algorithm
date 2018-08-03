#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];
int dp[101][101];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0)	
				continue;
			if (i + arr[i][j] < n) 
				dp[i + arr[i][j]][j] += dp[i][j];
			if (j + arr[i][j] < n) 
				dp[i][j + arr[i][j]] += dp[i][j];
		}
	}

	cout << dp[n-1][n-1] << "\n";
	return 0;
} 