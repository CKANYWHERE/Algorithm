#include"stdafx.h"
#include<queue>
#include<tuple>
#include<iostream>
using namespace std;
int dist[1001][1001];

int main() {
	int n;
	cin >> n;
	memset(dist, -1, sizeof(dist));
	queue<pair<int,int>> q;
	q.push(make_pair(0,1));
	dist[1][0] = 0;
	while (!q.empty()) {
		int s, c;
		tie(s, c) = q.front();
		q.pop();

		if (dist[s][s] == -1) {
			dist[s][s] = dist[s][c] + 1;
			q.push(make_pair(s,s));
		}

		if (dist[s + c][c] == -1 && s <= n) {
			dist[s + c][c] = dist[s][c] + 1;
			q.push(make_pair(s + c, c));
		}

		if (dist[s - 1][c] == -1 && s - 1 >= 0) {
			dist[s - 1][c] = dist[s][c] + 1;
			q.push(make_pair(s - 1, c));
		}
	}

	int ans = -1;
	for (int i = 0; i <= n; i++) {
		if (dist[n][i] != -1) {
			if (ans == -1 || ans > dist[n][i]) {
				ans = dist[n][i];
			}
		}
	}
	cout << ans << '\n';

	return 0;
}