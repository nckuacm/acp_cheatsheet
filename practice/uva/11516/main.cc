#include <cmath>
#include <cstdio>
#include <sstream>
#include <algorithm>

int h[100000];

int greedy_find(int loc,int cnt,int ap){
    // loc -> ap loc, cnt -> counter of ap
    int n=1;
    int r=h[0]+loc;
    for(int i=0;i<cnt;i++){
        if(abs(r-h[i])<=loc){}
        else{
            n++;
            if(n > ap) return 0;
            r=h[i]+loc;
        }
    }
    return 1;
}

int main(){
    // readin testcase
    int testcase,ap,house,left,right;
    char line[1024];
    // get testcase
    scanf("%d",&testcase);
    // execute for testcase times
    while(testcase--){
        // get the number of APs , and houses 
        scanf("%d",&ap);
        scanf("%d",&house);
        // and then read the line for "house" time
        int cnt=0,iterative=house;
        while(iterative--){
            // readline
            scanf("%d",&h[cnt]);
            h[cnt]*=2;
            cnt++;
            //printf("House number: %d\n",h[cnt-1]);
        }
        // after having all house, using greedy algorithm to find the best location for ap
        std::sort(h,h+house);

        left=0,right=(h[house-1]-h[0])/2;
        int ap_loc;
        while(left<=right){
            ap_loc=(left+right)/2;
            if(greedy_find(ap_loc,house,ap)){
                right=ap_loc-1;
            }
            else{
                left=ap_loc+1;
            }
        }
        printf("%.1lf\n", (right+1)/2.0);
        
        /*for(int i=0;i<house;i++){
            printf("%d ",h[i]);
        }
        printf("\n");*/
    }

    return 0;
}