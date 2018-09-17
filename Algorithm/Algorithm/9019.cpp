#include "pch.h"
#include <iostream>
#include <queue>
#include <stack>
#define MAX 10000
using namespace std;

int dist[MAX];
int from[MAX];
char a[MAX];
bool check[MAX];

int main() {
	int T;

	//int n1;
	//cin >> n1;
	//cout << (n1%1000)*10+(n1/1000) <<"\n";
	//cout << (n1 % 10)*1000 + (n1/10) << "\n";
	cin >> T;
	while (T--) {

		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(a, 0, sizeof(a));
		memset(from, 0, sizeof(from));
		int n, m;
		cin >> n >> m;
		queue<int> q;
		dist[n] = 0;
		check[n] = true;
	
		q.push(n);
		while (!q.empty())
		{
			int next;
			int now = q.front();
			q.pop();
			next = (now * 2) % 10000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				a[next] = 'D';
			}//D
			int tmp;
			next = now - 1;
			if (next == -1) next = 9999;
			if (check[next] == false){
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				a[next] = 'S';
			}//S
			next = (now % 1000) * 10 + (now / 1000);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				a[next] = 'L';
			}//L
			next = (now % 10) * 1000 + (now / 10);
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				a[next] = 'R';
			}//R
		}
		stack<char> ans;
		for (int i = m; i != n; i = from[i]) {
			ans.push(a[i]);
		}
		while (!ans.empty())
		{
			cout << ans.top();
			ans.pop();
		}
		cout << "\n";
	}
	return 0;
}