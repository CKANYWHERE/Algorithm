#include "stdafx.h"
#include <queue>
#include <stack>
#include <iostream>
const int MAX = 100010;
using namespace std;

bool check[MAX];
int dist[MAX];
int from[MAX];

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	check[n] = true;
	q.push(n);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();


		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				dist[now - 1] = dist[now] + 1;
				check[now - 1] = true;
				from[now - 1] = now;
			}
		}

		if (now * 2 < MAX) {
			if (check[now * 2] == false) {
				q.push(now * 2);
				dist[now * 2] = dist[now] + 1;
				check[now * 2] = true;
				from[now * 2] = now;
			}
		}

		if (now + 1 < 0) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				dist[now + 1] = dist[now] + 1;
				check[now + 1] = true;
				from[now + 1] = now;
			}
		}
	}
	cout << dist[k] << "\n";
	stack<int> s;
	for (int i = k; i != n; i = from[i]) {
		s.push(i);
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << "\n";
}