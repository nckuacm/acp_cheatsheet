#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main()
{
    int test;
    while(scanf("%d", &test) == 1) {
        char input[150];
        stack<char> stk;
        getchar();
        while(test--) {
           
            while(!stk.empty()) {
                stk.pop();
            }

            memset(input, 0, sizeof(input));
            fgets(input, 150, stdin);

            char tmp;
            
            for(int i = 0; i < strlen(input); ++i) {
                if(input[i] == '(' || input[i] == '[') {
                    stk.push(input[i]);
                } else if(input[i] == ')' || input[i] == ']') {
                    if(stk.empty()) {
                        printf("No\n");
                        break;
                    } else {
                        tmp = stk.top();
                        stk.pop();
                    }

                    if(input[i] == ']') {
                        if(tmp != '[') {
                            printf("No\n");
                            break;
                        }
                    } else if(input[i] == ')') {
                        if(tmp != '(') {
                            printf("No\n");
                            break;
                        }
                    }
                }

                if(i == strlen(input)-1) {
                    if(stk.empty())
                        printf("Yes\n");
                    else
                        printf("No\n");
                }
            }
        }
    }
    return 0;
}
