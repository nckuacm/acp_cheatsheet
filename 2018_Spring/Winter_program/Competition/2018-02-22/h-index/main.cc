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
            int max;
            for(int i=0;i<N;i++){
                if(N-i >= arr[i] && i < arr[i]){
                    // h-index found, take its maximum 
                    max = arr[i];
                }
            }
            printf("%d\n",max);
            free(arr);
        }
    }
}