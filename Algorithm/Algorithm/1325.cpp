#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring> 
using namespace std;

vector<int> graph[10001];
vector<int> nodes;
bool check[10001];
int maxValue = 0;
int cnt = 0;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			cnt++;
			int now = q.front();
			check[now] = true;
			q.pop();
			for (int j = 0; j<graph[now].size(); j++) {
				int next = graph[now][j];
				if (!check[next]) {
					check[next] = true;
					q.push(next);
				}
			}
		}
		maxValue = max(cnt, maxValue);
		if (cnt == maxValue) {
			result.push_back(i);
		}

		if (cnt > maxValue) {
			maxValue = cnt;
			result.clear();
			result.push_back(i);
		}
		memset(check, false, sizeof(check));
		
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
	return 0;
}