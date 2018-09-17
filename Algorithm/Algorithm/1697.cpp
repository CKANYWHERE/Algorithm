#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100000
using namespace std;

bool check[MAX];
int dist[MAX];

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	check[n] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now+1 < MAX && check[now] == false)  {
			check[now + 1] = true;
			dist[now+1] = dist[now] + 1;
			q.push(now + 1);
		}
		if (now - 1 > 0 && check[now - 1] == false) {
			check[now - 1] = true;
			dist[now - 1] = dist[now] + 1;
			q.push(now - 1);
		}
		if (now * 2 < MAX && check[now * 2] == false) {
			check[now * 2] = true;
			dist[now * 2] = dist[now] + 1;
			q.push(now * 2);
		}
	}

	cout << dist[k] << "\n";

	return 0;
}