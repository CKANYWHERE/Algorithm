#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> 
using namespace std;

vector<int> graph[10001];
vector<int> nodes;
bool check[10001];
int maxValue = 0;
int cnt = 0;

void dfs(int node) {
	if (check[node]) return;
	else check[node] = true;
	cnt++;
	for (int i = 0; i < graph[node].size(); i++) {
		int next_node = graph[node][i];
		if(!check[next_node]) dfs(next_node);
	}
}

int main() {
	int n, m;
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		graph[end].push_back(start);
	}

	vector<int> res;

	for (int i = 1; i <= n; i++) {
		memset(check, false, sizeof(check));
		cnt = 0;
		dfs(i);
		maxValue = max(maxValue, cnt);
		if (cnt == maxValue) {
			res.push_back(i);
		}
		if (cnt > maxValue) {
			res.clear();
			res.push_back(i);
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << "\n";

	return 0;
}