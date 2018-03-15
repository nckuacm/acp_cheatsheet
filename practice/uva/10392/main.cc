#include <cstdio>

int main(){
    long long int n;
    // make prime (with limited prime number)
    int prime[1000000];
    int num_prime=2;
    prime[0]=2;
    prime[1]=3;

    for(int i=5,gap=2; i<10000000;i+=gap,gap=6-gap){
        bool isPrime=1;
        for(int j=1;prime[j]*prime[j]<=i;j++){
            if(i%prime[j]==0){
                isPrime=0;
                break;
            }
        }
        if(isPrime)
            prime[num_prime++]=i;
    }

    // read
    while(scanf("%lld",&n)){
        if(n==-1)
            break;
        // factor
        for(int i=0;i<num_prime;i++){
            while(n%prime[i]==0){
                printf("    %d\n",prime[i]);
                n/=prime[i];
            }
            if(n==1) break;
        }

        if(n!=1) printf("    %lld\n",n);
        printf("\n");
    }

    return 0;
}