#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[4][8];
vector<pair<int, int>> v;

void turn(int dir, int *arr) {
	int temp = 0;
	switch (dir) {
	case 1:
		temp = arr[7];
		for (int i = 7; i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = temp;
		break;
	case -1:
		temp = arr[0];
		for (int i = 0; i < 7; i++)
			arr[i] = arr[i + 1];
		arr[7] = temp;
		break;
	}
}

int opp(int dir) {
	return dir == 1 ? -1 : 1;
}

int main() {
	int n;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num, dist;
		cin >> num >> dist;
		v.push_back({ num-1,dist });
	}

	for (int i = 0; i < v.size(); i++) {
		int num = v[i].first;
		int dist = v[i].second;
		int c[4] = { 0,0,0,0 };
		c[num] = dist;
		int next = num - 1;
		while (true) {
			if (next < 0) break;
			if (arr[next][2] == arr[next + 1][6]) break;
			c[next] = opp(c[next + 1]);
			--next;
		}
		next = num + 1;
		while (true) {
			if (next > 3) break;
			if (arr[next][6] == arr[next - 1][2]) break;
			c[next] = opp(c[next - 1]);
			++next;
		}

		for (int i = 0; i < 4; i++)
			turn(c[i], arr[i]);

		int ans = 0;
		if (arr[0][0] == 1) ++ans;
		if (arr[1][0] == 1) ans += 2;
		if (arr[2][0] == 1) ans += 4;
		if (arr[3][0] == 1) ans += 8;
		cout << ans << endl;
	}

	return 0;
}