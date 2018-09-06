#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int e, s, m;
	int E = 1, S = 1, M = 1,cnt=1;

	cin >> e >> s >> m;

	while (true) {
		if (e == E && s == S && m == M) {
			cout << cnt << "\n";
			return 0;
		}
		cnt++;
		E++;
		S++;
		M++;
		if (E == 16) {
			E = 1;
		}
		if (S == 29) {
			S = 1;
		}
		if (M == 20) {
			M = 1;
		}
	}
	
	return 0;
}