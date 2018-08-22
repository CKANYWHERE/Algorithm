#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int dist[101];

int main() {
	int n,m;
	cin >> n;
	int s, f;
	cin >> s >> f >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
 		arr[x][y] = arr[y][x] = 1;
	}
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int index = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[index][i] == 0 || dist[i] != 0)continue;
			dist[i] = dist[index] + 1;
			q.push(i);
		}

	}
	cout << (dist[f] == 0 ? -1 : dist[f]) << endl;
	return 0;
}