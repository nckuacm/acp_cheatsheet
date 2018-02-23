#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
    int N;
    std::vector<int> arr;
    while(scanf("%d",&N)!=EOF){
        if(N==0) return 0;
        else{
            for(int i=0;i<N;i++){
                int c;
                int r = scanf("%d",&c);
                arr.push_back(c);
            }
            sort(arr.begin(),arr.end());
            // solved -> presentation error , need to print the first element
            printf("%d",arr.at(0));
            for(int i=1;i<N;i++){
                printf(" %d",arr.at(i));
            }
            printf("\n");
            arr.clear();
        }
    }
    return 0;
}