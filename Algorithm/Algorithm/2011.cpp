#include "pch.h"
#include<iostream>
#include<string.h>
using namespace std;

#define mod 1000000
int dp[5000 + 1];

int main()
{
	char n[5000 + 2];
	cin >> n + 1;
	int slen = strlen(n + 1);
	dp[0] = 1;

	for (int i = 1; i <= slen; i++)
	{
		int x = n[i] - '0';
		if (x >= 1 && x <= 9)
			dp[i] = (dp[i] + dp[i - 1]) % mod;
		if (i == 1) continue;
		if (n[i - 1] == '0') continue;
		int y = (n[i - 1] - '0') * 10 + (n[i] - '0');
		if (y >= 10 && y <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % mod;
	}
	printf("%d\n", dp[slen]);
	return 0;
}