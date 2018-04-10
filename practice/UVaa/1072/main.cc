#include <cstdio>
#include <string>

struct node{
    // record for string len
    int length;
    // string
    std::string str();
};

int main(){
    int n=1;
    // read data
    while(1){
        int seq;
        char line[1024];
        scanf("%d",&seq);
        if(!seq)
            return 0;
        // read seq time 
        for(int i=0;i<seq;i++){
            scanf("%s",line);
            printf("%s\n",line);
        }
    }

    /*TODO*/

    return 0;
}