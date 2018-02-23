#include <cstdio>
#include <cstdlib>
#include <algorithm>

bool compare(int a,int b){
    return a<b;
}

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF){
        if(N==0)
            return 0;
        else{
            int *arr = (int *)malloc(N*sizeof(int));
            for(int i=0;i<N;i++){
                int r = scanf("%d",&arr[i]);
            }
            // sort
            std::sort(arr,arr+N,compare);
            // cal
            int i;
            for(i=0;i<N;i++){
                if(arr[i] >= N-i){
                    // h-index found
                    printf("%d\n", N-i);
                    break;
                }
            }
            if (i == N) { // If all citations are zero
                // h-index is 0
                printf("%d\n", 0);
            }
            free(arr);
        }
    }
}