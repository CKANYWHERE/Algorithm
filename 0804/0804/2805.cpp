#include "stdafx.h"
#include <iostream>
using namespace std;

int arr[10000];
int n;
long long m;

bool check(int x) {
	long long cnt = 0;
	for (int i = 0; i < m; i++) {
		if(arr[i]-x>0)
			cnt += arr[i] - x;
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
	long long mid;
	long long ans = 0;
	while (l <= r) {
		mid = (r + l) / 2;
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
	return 0;
}