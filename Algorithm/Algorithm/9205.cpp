#include "pch.h"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t, n;
vector<bool> check;
vector<pair<int, int> > v;

int abs(int x) {
	return ((x < 0) ? -x : x);
}

bool dist(int x1, int y1, int x2, int y2) {
	return ((abs(x1 - x2) + abs(y1 - y2)) <= 1000 ? true : false);
}

int main(void) {
	cin >> t;
	while (t--) {
		cin >> n;
		check = vector<bool>(n + 2, false);
		v = vector<pair<int, int> >(n + 2, make_pair(0, 0));
		for (int i = 0; i < n + 2; i++)
			cin >> v[i].first >> v[i].second;

		queue<int> q;
		q.push(0);
		check[0] = true;

		bool find = false;
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 1; i < n + 2; i++) {
				if (!check[i] && dist(v[now].first, v[now].second, v[i].first, v[i].second)) {
					q.push(i);
					check[i] = true;
				}
			}
		}

		if (check[n + 1] == true) {
			cout << "happy" << "\n";
		}
		else
			cout << "sad" << "\n";
	}
	return 0;
}