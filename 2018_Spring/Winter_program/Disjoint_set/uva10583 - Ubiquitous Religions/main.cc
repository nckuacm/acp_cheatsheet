#include <cstdio>
#include <cstdlib>
#include <algorithm>

int *p;

int Find(int x){
    if( x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x,int y){
    int X = Find(x);
    int Y = Find(y);

    p[X] = Y;
}

bool comp(int a,int b){
    return a<b;
}

int main(){
    // read
    int iterative=1; 
    while(1){
        int N,M;
        // scanf N
        int tmp = scanf("%d %d",&N,&M);
        if(N==0 && M==0)
            break;
        // initial table
        p = (int*)malloc((N+1)*sizeof(int));
        for(int i=0;i<=N;i++)
            p[i] = i; // start from 1
        // reading M pair
        int f,s;
        for(int i=0;i<M;i++){
            int tmp = scanf("%d %d",&f, &s);
            // building relation, f union to s
            Union(s,f);
        }

        for(int i=1;i<=N;i++){
            // after connect, also need to update root
            Find(i);
        }
        
        // sort it
        std::sort(p,p+N,comp);

        // check 
        int count=1,diff=p[1];
        for(int i=1;i<=N;i++){
            // printf("%d ",p[i]);
            if(p[i] != diff){
                diff = p[i];
                count++;
            }
        }
        // printf("\n");
        printf("Case %d: %d\n",iterative,count);
        // free
        free(p);
        iterative++;
    }
}