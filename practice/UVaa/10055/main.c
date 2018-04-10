#include <stdio.h>

long long int our,opp;

int main(){
    while(scanf("%lld%lld",&our,&opp)!=EOF){
        long long int gap= opp>our ? (opp-our):(our-opp);
        printf("%lld\n",gap);
    }

    return 0;
}