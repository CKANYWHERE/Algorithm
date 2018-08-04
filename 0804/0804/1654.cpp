#include "stdafx.h"
#include <iostream>
using namespace std;
int n, m;
int arr[10000];

bool check(long long x) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += arr[i] / x;
	}
	return cnt >= m;
}

int main() {
	
	cin >> n >> m;
	long long max = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	long long l = 1;
	long long r = max;
	long long mid = 0;
	long long ans = 0;

	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			if (ans < mid)
				ans = mid;
			l = mid + 1;
		} 
		else {
			r = mid - 1;
		}
	}
	cout << ans << "\n";
}