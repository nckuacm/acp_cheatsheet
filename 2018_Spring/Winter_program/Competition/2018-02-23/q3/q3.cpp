#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

map<string, int> m;
int parent[5500], size[5500];

int Find(int num){
    while(parent[num] != num)
        num = parent[num];
    return num;
}

void Union(int p1, int p2){
    parent[p1] = p2;
    size[p2] += size[p1];
    return;
}

int main(){
    int c, r;
    while(scanf("%d %d", &c, &r) != EOF){
        if (!c && !r)
            break;
        m.clear();
        memset(parent, 0, sizeof(parent));
        memset(size, 0, sizeof(size));
        string str;
        for(int i=0;i < c;i++){
            cin >> str;
            m[str] = i; 
            size[i] = 1;
            parent[i] = i;
        }

        for(int i=0;i < r;i++){
            cin >> str;
            int p1 = Find(m[str]);
            cin >> str;
            int p2 = Find(m[str]);
            if(p1 != p2)
                Union(p1, p2);
        }
        
        int ans = 1;
        for(int i=0;i < c;i++)
            if(parent[i] == i)
                ans = max(ans, size[i]);
        printf("%d\n", ans);
    }
    return 0;
}
