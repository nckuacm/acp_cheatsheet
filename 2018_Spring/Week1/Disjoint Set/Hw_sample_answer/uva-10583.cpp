#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int parent[50500];

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
    int n, m, cas = 1;
    while(scanf("%d %d", &n, &m) != EOF){
        if (!n && !m)
            break;
		//initialize
        memset(parent, 0, sizeof(parent));
        for(int i=0;i < n;i++)
            parent[i] = i;

        int num1, num2;
        for(int i=0;i < m;i++){
            scanf("%d %d", &num1, &num2);
			//find root
            int p1 = Find(num1);
            int p2 = Find(num2);
			//if num1 and num2 not in same group => union
            if(p1 != p2)
                Union(p1, p2);
        }
        
		//count group
        int ans = 0;
        for(int i=0;i < n;i++)
            if(parent[i] == i)
                ans++;
        printf("Case %d: %d\n", cas, ans);
        cas++;
    }
    return 0;
}
