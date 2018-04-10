#include <cstdio>
#include <vector>
#include <queue>

int death[100],dp[100];
std::vector<int> v[100];

int choice(int count,int event);

int main(){
    bool newline=false;
    int event;

    while(scanf("%d",&event)!=EOF){
        int count=0,n,k;

        // reset
        for(int i=0;i<event;i++){
            death[i]=0;
            dp[i]=0;
            v[i].clear();
        }

        // read the event
        for(int i=0;i<event;i++){
            scanf("%d",&n);
            if(!n)
                death[count++]=i;
            else{
                for(int j=0;j<n;j++){
                    scanf("%d",&k);
                    // push into event v[i]
                    v[i].push_back(k);
                }
            }
        }

        // print
        if(newline)
            putchar('\n');
        else
            newline=true;

        // print result
        printf("%d\n",choice(count,event));
    }

}

int choice(int count,int event){
    
    dp[0]=1;

    for(int i=0;i<event;i++){
        // pop out
        while(!v[i].empty()){
            int edge = v[i].back();
            v[i].pop_back();
            dp[edge]+=dp[i];
        }
    }
    

    // sum all path to death event
    int sum=0;
    for(int i=0;i<count;i++)
        sum+=dp[death[i]];
    
    return sum;
}