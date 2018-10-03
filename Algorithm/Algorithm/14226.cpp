#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;

int dist[MAX][MAX];
bool check[MAX][MAX];

int main() {
	int n,s,c;
	cin >> n;
	queue<pair<int,int>> q;
	q.push(make_pair(1, 0));
	check[1][0] = true;
	while (!q.empty())
	{
		s = q.front().first;
		c = q.front().second;
		q.pop();
		if (check[s][s] == false) {
			check[s][s] = true;
			dist[s][s] = dist[s][c] + 1;
			q.push(make_pair(s, s));
		}
		if (check[s + c][c] == false && s + c <= n) {
			check[s + c][c] = true;
			dist[s + c][c] = dist[s][c] + 1;
			q.push(make_pair(s + c, c));
		}
		if (check[s - 1][c] == false && s - 1 >= 0) {
			check[s - 1][c] = true;
			dist[s - 1][c] = dist[s][c] + 1;
			q.push(make_pair(s - 1, c));
		}
	}
	int ans = -1;
	for (int i = 0; i <= n; i++) {
		if (check[n][i]) {
			if (ans > dist[n][i] || ans == -1) {
				ans = dist[n][i];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}