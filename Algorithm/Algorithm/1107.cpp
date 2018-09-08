#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool broken[10];

int possible(int c) {
	if (c == 0) {
		return broken[0] ? 0 : 1;
	}
	int len = 0;
	while (c > 0) {
		if(broken[c % 10]) return 0;
		len++;
		c /= 10;
	}
	return len;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		broken[a] = true;
	}
	int ans = n - 100;
	ans = abs(ans);


	for (int i = 0; i <= 1000000; i ++ ) {
		int c = i;
		int len = possible(c);

		if (len > 0) {
			int press = c - n;
			if (press < 0) {
				press = -press;
			}
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}