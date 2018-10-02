#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;
vector<int> v[MAX];
bool check[MAX];
int depth[MAX];
int parent[MAX];


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	depth[1] = 0;
	check[1] = true;
	queue<int> q;
	q.push(1);
	parent[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : v[x]) {
			if (!check[y]) {
				depth[y] = depth[x] + 1;
				check[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}