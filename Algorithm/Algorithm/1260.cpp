#include "pch.h"
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[1001];
const int MAX = 1001;
int n, m, v;
vector<int> adj[1001];

void bfs() {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	int idx = 0;
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		cout << idx << " ";
		for (int i = 0; i < adj[idx].size(); i++) {
			int graph = adj[idx][i];
			if (!visited[graph]) {
				q.push(graph);
				visited[graph] = true;
			}
		}
	}
}

void dfs(int idx) {
	cout << idx << " ";
	visited[idx] = true;
	for (int i = 0; i < adj[idx].size(); i++) {
		int graph = adj[idx][i];
		if (!visited[graph]) {
			visited[graph] = true;
			dfs(graph);
		}
	}
}

int main() {

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(v);
	memset(visited, false, sizeof(visited));
	cout << "\n";
	bfs();

	return 0;
}