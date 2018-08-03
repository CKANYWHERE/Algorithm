#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*int main() {
	stack<char> lstack;
	stack<char> rstack;
	string input;
	int cnt;
	char cmd;
	
	cin >> input;
	
	int len = input.size();

	for (int i = 0; i < len; i++) {
		lstack.push(input[i]);
	}

	cin >> cnt;
	while(cnt--){
		cin >> cmd;
		if (cmd == 'D') {
			if (!rstack.empty()) {
				lstack.push(rstack.top());
				rstack.pop();
			}
		}
		else if (cmd == 'L') {
			if (!lstack.empty()) {
				rstack.push(lstack.top());
				lstack.pop();
			}
		}
		else if (cmd == 'B') {
			if (!lstack.empty()) {
				lstack.pop();
			}
		}
		else if (cmd == 'P') {
			char data;
			cin >> data;
			lstack.push(data);
		}
		

	}

	while (!lstack.empty()) {
		rstack.push(lstack.top());
		lstack.pop();
	}

	while (!rstack.empty()) {
		cout << rstack.top();
		rstack.pop();
	}

	return 0;
}*/
