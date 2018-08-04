#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

long long calc(int n) {
	long long ans = 0;
	for (int start = 1, len = 1; start <= n; start *= 10, len++) {
		int end = start * 10 - 1;
		if (end > n)
			end = n;
		ans += (long long)(end - start + 1)*len;
	}
	return ans;
}


int main()
{
	int n;
	long long k;
	cin >> n >> k;
	if (calc(n) < k) {
		cout << -1 << "\n";
		return 0;
	}
	int l = 1;
	int r = n;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		long long len = calc(mid);
		if (len < k) {
			l = mid + 1;
		}
		else {
			ans = mid;
			r = mid - 1;
		}
	}
	string s = to_string(ans);
	long long l = calc(ans);
	cout << s[s.length() - (l - k) - 1] << '\n';
    return 0;
}

