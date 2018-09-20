#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> 
using namespace std;

vector<int> graph[10001];
bool check[10001];
int cnt = 0;
int ans = 0;
int n, m;

void dfs(int node) {

	if (check[node])
		return;

	check[node] = true;
	cnt+=1;
	ans = max(cnt,ans);
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!check[next]) {
			check[next] = true;
			dfs(next);
		}	
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	int maxNode=0;
	vector<int>result;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		dfs(i);
		if (maxNode == cnt) {
			result.push_back(i);
		}
		if (maxNode < cnt) {
			maxNode = cnt;
			result.clear();
			result.push_back(i);
		}
		memset(check, false, sizeof(check));
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
	return 0;
}