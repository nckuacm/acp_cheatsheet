#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int parent[505000];

int Find(int num){
//find root along parent node
    while(parent[num] != num)
        num = parent[num];
    return num;
}

void Union(int p1, int p2){
    parent[p1] = p2;
    return;
}

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int n;
        scanf("%d", &n);
        getchar();
		//initialize
        memset(parent, 0, sizeof(parent));
        for(int i=1;i <= n;i++)
            parent[i] = i;

        int num1, num2;
        char str[10000];
        while(fgets(str, sizeof(str), stdin) && str[0] != '\n'){
            char *ptr = strtok(str, " ");
            while(ptr != NULL){
                int num1 = atoi(ptr);
                ptr = strtok(NULL, " ");
                int num2 = atoi(ptr);
                ptr = strtok(NULL, " ");
                int p1 = Find(num1);
                int p2 = Find(num2);
                if(p1 != p2)
                    Union(p1, p2);
            }
        }
		//count groups
        int ans = 0;
        for(int i=1;i <= n;i++)
            if(parent[i] == i)
                ans++;
        printf("%d\n", ans);
        if(cas != 0)
            printf("\n");
    }
    return 0;
}
