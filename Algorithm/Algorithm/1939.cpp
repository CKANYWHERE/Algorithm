#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;
vector<pair<int, int>>graph[100001];
queue<int> q;
bool check[100001];
int start=0;
int dest=0;

bool bfs(int n) {
	memset(check,false,sizeof(check));
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == dest) return true;
		for (int i = 0; graph[now].size(); i++) {
			int next = graph[now][i].first;
			int w = graph[now][i].second;

			if (check[next] == 0 && n <= w) {
				check[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int w;
	for (int i = 0; i < m; i++) {
		cin >> n >> m >> w;
		graph[n].push_back(make_pair(m, w));
		graph[m].push_back(make_pair(n, w));
	}
	
	cin >> start >> dest;
	int l = 0;
	int r = 100001;
	int ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (bfs(mid)) {
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