#include "pch.h"
#include <iostream>
#include <queue>
#include <stack>
#define MAX 100000
using namespace std;

int dist[MAX];
int from[MAX];
bool check[MAX];

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	check[n] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
	
		if (now + 1 < MAX && check[now + 1] == false) {
			q.push(now + 1);
			dist[now + 1] = dist[now] + 1;
			check[now + 1] = true;
			from[now + 1] = now;
		}	
		if (now - 1 > 0 && check[now - 1] == false) {
			q.push(now - 1);
			dist[now - 1] = dist[now] + 1;
			check[now - 1] = true;
			from[now - 1] = now;
		}
		if (now * 2 < MAX && check[now * 2] == false) {
			q.push(now * 2);
			dist[now * 2] = dist[now] + 1;
			check[now * 2] = true;
			from[now * 2] = now;
		}
	}


	cout << dist[k] << "\n";
	stack<int> ans;
	for (int i = k; i != n; i = from[i]) {
		ans.push(i);
	}
	ans.push(n);
	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}

	return 0;
}