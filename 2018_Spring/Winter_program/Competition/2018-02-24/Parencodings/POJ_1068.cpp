#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

stack<char> stk;
stack<int> order;

int main() {

	int test, size;
	while(scanf("%d", &test) == 1) {
		while(test--) {
			scanf("%d", &size);
			int tmp = 0, input;
			
			while(!stk.empty()) stk.pop();
			while(!order.empty()) order.pop();
			
			for(int i = 0, pos = 0; i < size; ++i, pos++) {
				scanf("%d", &input);
				if(input == tmp) {
					printf("%d", (pos - order.top()+1) / 2);
					order.pop();
				} else {
					while(input != tmp) {
						order.push(pos);
						tmp++;
						pos++;
					}
					printf("%d", (pos - order.top()+1) / 2);
					order.pop();
				}
				if(i != size-1) printf(" ");
				else puts("");
			}
		}
	}

	return 0;
}
