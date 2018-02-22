#include <cstdio>

int get_max_circlelen(const int num);

int main(int argc, char *argv[]){
    // 
    int in,lb=-1,ub=-1;
    while(scanf("%d",&in)!=EOF){
        if(lb == -1)
            lb=in;
        else
            ub=in;
 
        if(lb != -1 && ub != -1){    
            // compare first
            int real_lb,real_ub;
            if(lb > ub){
                real_lb = ub;
                real_ub = lb;
            }
            else{
                real_lb = lb;
                real_ub = ub;
            }
                
            int max=-1;
            for(int i=real_lb;i<=real_ub;i++){
                //
                int result = get_max_circlelen(i);
                if(result>max)
                    max = result;
            }
            printf("%d %d %d\n",lb,ub,max);
            // reset 
            lb=-1;
            ub=-1;
        }
    }

    return 0;
}

int get_max_circlelen(const int num){
    int count=1,tmp=num;
    while(tmp != 1){
        if(tmp%2)
            tmp=3*tmp+1;
        else
            tmp/=2;
        count++;
    }
    return count;
}