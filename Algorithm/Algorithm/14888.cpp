#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int minV = 987654321, maxV = -987654321;

void go(vector<int> &v,int res ,int idx, int plus, int minus, int multi, int divide) {
	int n = v.size();
	if (n == idx) {
		minV = min(minV, res);
		maxV = max(maxV, res);		
		return;
	}
	if (plus > 0) {
		go(v, res + v[idx], idx + 1, plus - 1, minus, multi, divide);
	}

	if (minus > 0) {
		go(v, res - v[idx], idx + 1, plus, minus - 1, multi, divide);
	}

	if (multi > 0) {
		go(v, res * v[idx], idx + 1, plus, minus, multi - 1, divide);
	}

	if (divide > 0) {
		go(v, res / v[idx], idx + 1, plus, minus, multi, divide - 1);
	}
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;
	
	go(a, a[0], 1, plus, minus, mul, div);

	cout << maxV << "\n";
	cout << minV << "\n";

	return 0;
}