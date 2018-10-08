#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long calc(int n) {
	long long ans = 0;
	int len = 0;
	for (int i = 0; i <= n; i *= 10) {
		len++;
		int end = i * 10 - 1;
		if (end > n) {
			end = n;
		}
		ans += (long long)(end - i + 1) * len;
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	if (calc(n) < k) {
		cout << -1 << '\n';
		return 0;
	}
	int left = 1;
	int right = n;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long len = calc(mid);
		if (len < k) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	string s = to_string(ans);
	long long l = calc(ans);
	cout << s[s.length() - (l - k) - 1] << '\n';
	
	return 0;
}