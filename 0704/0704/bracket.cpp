// 0704.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stack>
#include <iostream>
#include <string>
using namespace std;
/*int main() {
	int rescnt;
	cin >> rescnt;

	for (int i = 0; i < rescnt; i++) {
		string res;
		string input;
		bool no = false;
		stack<char> stack;
		cin >> input;

		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(') {
				stack.push(input[i]);
			}
			else if(input[i] == ')'){
				if (stack.empty()) {
					res = "NO";
					no = true;
					break;
				}
				else {
					stack.pop();
				}	
			}
		}
		if (stack.empty() && !no){
			res = "YES";
		}
		else if (!stack.empty()) {
			res = "NO" ;
		}

		cout << res << "\n";
	}

	return 0;
}*/

