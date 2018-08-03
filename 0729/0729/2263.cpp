#include "stdafx.h"
#include <iostream>
using namespace std;

int inorder[100001];
int postorder[100001];
int position[100001];

void solve(int pr_s,int pr_e,int in_s, int in_e) {
	if (pr_s > pr_e || in_s > in_e) return;
	int root = postorder[pr_e];
	cout << root;

	int p = position[root];

	int left = p - in_s;
	solve(in_s, p - 1, pr_s, pr_s + left - 1);
	solve(p + 1, in_e, pr_s + left, pr_e - 1);

}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	for (int i = 0; i<n; i++) {
		position[inorder[i]] = i;
	}
	solve(0,n-1,0,n-1);
	return 0;
}