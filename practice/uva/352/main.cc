#include <cstdio>

/* This problem use "DFS" to solve! */

// define for static size, using 1-dimension array
int mat[625];
bool search[625];

void DFS(int index,int len){
    if(mat[index]&&search[index]==false){
        search[index]=true;
        // then search its adjacent 8 direction: (consider the DFS searching direction)
        int row=index/len, col=index%len;
        if( (row-1)>=0 && (col-1)>=0){
            DFS((row-1)*len+col-1,len);
        }
        if( (row-1)>=0){
            DFS((row-1)*len+col,len);
        }
        if( (row-1)>=0 && col+1<len){
            DFS((row-1)*len+col+1,len);
        }
        if( ((col-1)>=0) ){
            DFS(index-1,len);
        }
        if(((col+1)<len)){
            DFS(index+1,len);
        }
        if( (row+1)<len && (col-1)>=0 ){
            DFS((row+1)*len+col-1,len);
        }
        if( (row+1)<len ){
            DFS((row+1)*len+col,len);
        }
        if((row+1)<len && col+1<len){
            DFS((row+1)*len+col+1,len);
        }
    }
    return;
}

int main(){
    char c,str[25];
    int raw;
    int len,war_eagle=0,iterative=1;
    // read the metrix size 
    while(scanf("%d",&len)!=EOF){
        // now len is the metrix size
        for(int i=0;i<len;i++){
            scanf("%s",str);
            //printf("raw: %s\n",str);
            //printf("%lld\n",raw);
            for(int j=0;j<len;j++){
                // using bitwise operator
                mat[i*len+j]= (str[j]=='0'?0:1);
                //printf("%d ",mat[i*len+j]);
                // also reset search table
                search[i*len+j]=false;
            }
        }

        // print 
        /*for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                printf("%d ",mat[i*len+j]);
            }
            printf("\n");
        }*/
        
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                // using DFS, to detect how many war eagles
                if(search[i*len+j]==false){
                    if(mat[i*len+j]){
                        DFS(i*len+j,len);
                        //printf("Iterative: %d, location: %d,%d\n",iterative,i,j);
                        war_eagle++;
                    }
                    else{
                        search[i*len+j]=true;
                    }
                }
                //printf("%d ",mat[i*len+j]);
            }
            //printf("\n");
        }
        printf("Image number %d contains %d war eagles.\n",iterative,war_eagle);
        war_eagle=0;
        iterative++;
    }
}