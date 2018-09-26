#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	int ans = 987654321;
	int n, m;
	cin >> n >> m;
	vector<int> v(n+1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int sum = v[0];
	int l = 0;
	int r = 0;

	while (l <= r && r < n) {
		if (sum < m)
		{
			r++;
			sum += v[r];
		}
		else if (sum == m)
		{
			if (ans > r - l + 1)
				ans = r - l + 1;
			r++;
			sum += v[r];
		}
		else if (sum > m)
		{
			if (ans > r - l + 1)
				ans = r - l + 1;
			sum -= v[l];
			l++;
		}
	}

	if (ans > n)
		cout << "0" << '\n';
	else
		cout << ans << '\n';


	return 0;
}