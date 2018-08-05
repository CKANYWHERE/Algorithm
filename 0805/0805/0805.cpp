// 0805.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

bool dp[101][1001];
int v[101];
int main()
{
	int n, s, m;
	
	cin >> n >> s >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	dp[0][s] = true;
	for (int i = 0; i <= n-1; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j] == false) continue;
			if (j - v[i+1] >= 0) {
				dp[i+1][j - v[i+1]] = true;
			}
			if (j + v[i+1] <= m) {
				dp[i+1][j + v[i+1]] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; i++) {
		if (dp[n][i]) ans = i;
	}

	cout << ans <<"\n";

    return 0;
}

