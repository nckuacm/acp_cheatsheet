#include <cstdio>

/* This problem use "DFS" to solve! */

// define for static size, using 1-dimension array
int mat[50],war_eagle=0;
bool search[50];

void DFS(int index,int len){
    /*if(mat[index] && search[index]==false){
        search[index]=true;
        // found the war eagle!
        war_eagle++;
        // then search its adjacent 4 direction: (consider the DFS searching direction)
        int row=index/len, col=index%len;
        if((col+1)<len && mat[index+1]){
            DFS(row*len+col+1,len);
        }
        if((row+1)<len && (col-1)>0 && mat[(row+1)*len+col-1]){
            DFS((row+1)*len+col-1,len);
        }
        if((row+1)<len && mat[(row+1)*len+col]){
            DFS((row+1)*len+col,len);
        }
        if((row+1)<len && col+1<len && mat[(row+1)*len+col+1]){
            DFS((row+1)*len+col+1,len);
        }
    }*/
}

int main(){
    char c;
    int len,raw;
    // read the metrix size 
    while(scanf("%d",&len)!=EOF){
        // now len is the metrix size
        for(int i=0;i<len;i++){
            scanf("%d",&raw);
            for(int j=0;j<len;j++){
                // using bitwise operator
                mat[i*len+(len-1-j)]=(raw&1);
                raw/=10;
                // also reset search table
                search[i*len+j]=false;
            }
        }

        // print 
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                // using DFS, to detect how many war eagles
                DFS(i*len+j,len);
                //printf("%d ",mat[i*len+j]);
            }
            //printf("\n");
        }
    }
}