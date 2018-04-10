#include <cstdio>

// get permutations
long long int permutations(long long int m,long long int n){
    long long int numerator=1,denominator=1;

    for(long long int i=0;i<n;i++){
        numerator*=(m-i);
        denominator*=(i+1);
    }

    return numerator/denominator;
}

int main(){
    long long int row,col;
    while(scanf("%lld%lld",&row,&col)!=EOF){
        if(!row && !col)
            break;
        // calculate the result
        long long int result=0;
        // row
        result+=(row*permutations(col,2));
        // col
        result+=(col*permutations(row,2));
        // crossline
        if(row>col){
            // longest 
            result+=((row-(col-1))*2*permutations(col,2));
            // and other
            for(long long int i=col-1;i>1;i--){
                result+=(4*permutations(i,2));
            }
        }
        else{
            result+=((col-(row-1))*2*permutations(row,2));
            // and other
            for(long long int i=row-1;i>1;i--){
                result+=(4*permutations(i,2));
            }
        }
        printf("%lld\n",2*result);
    }

    return 0;
}