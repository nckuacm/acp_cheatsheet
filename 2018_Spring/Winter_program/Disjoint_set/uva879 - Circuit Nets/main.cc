#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int p[100000];

int Find(int x)
{
    return (x == p[x]) ? x : p[x] = Find(p[x]);
}

int Union(int x,int y)
{
    int X = Find(x);
    int Y = Find(y);

    p[X]=Y;
}

int main(){
    int cases, nodes;

    char line[10000];
    char *token;
    int f_node,l_node, cnt;
    
    scanf("%d",&cases);
    while(cases--){
        // get nodes
        scanf("%d",&nodes);
        // skip 
        getchar();
        // reset counter
        cnt = 0;
        for(int i=1;i<=nodes;i++)
            p[i] = i;
        // parsing the line
        while(fgets(line,10000,stdin) && line[0] != '\n'){
            token = strtok(line, " ");
            while(token != NULL){
                f_node = atoi(token);
                // get next one
                token = strtok(NULL, " ");
                l_node = atoi(token);
                // set relation
                Union(f_node,l_node);
                // get next token, whether it is NULL or not
                token = strtok(NULL, " ");
            }
        }
        // Get the counters
        for(int i=1;i<=nodes;i++)
            cnt = (i==p[i]) ? cnt+1 : cnt;
        printf("%d\n",cnt);
        if(cases)
            printf("\n");
    }

    return 0;
}