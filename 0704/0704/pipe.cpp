// 0704.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
int main() {
	stack<int> stack;
	string input;
	int cnt = 0;

	cin >> input;
	int n = input.size();
	for (int i = 0; i < n; i++) {
		if (input[i] == '(') {
			stack.push(i);
		}
		else if (input[i] == ')') {
			if (stack.top() + 1 == i) {
				stack.pop();
				cnt += stack.size();
			}
			else {
				stack.pop();
				cnt += 1;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}*/

