#include <cstdio>

/* Using "backtracking" to solve first */

char maze[1000][1000];

// only for debug
void dump(int row,int col);

int main(){
    char line[1024];
    int testcase,row,col,j_pos_x,j_pos_y,f_pos_x,f_pos_y;
    // get testcase 
    scanf("%d",&testcase);

    while(testcase--){
        // get row,col
        scanf("%d",&row);
        scanf("%d",&col);
        // readline and then insert into maze
        for(int i=0;i<row;i++){
            scanf("%s",line);
            for(int j=0;j<col;j++){
                maze[i][j]=line[j];
                // record the Joe's & fire's location
                if(line[j]=='J'){
                    j_pos_x=i;
                    j_pos_y=j;
                }
                if(line[j]=='F'){
                    f_pos_x=i;
                    f_pos_y=j;
                }
            }
        }
        
        // finish IO problem, then using backtracking to find whether if Joe's can escape from maze or not
        // escape(j_pos_x,j_pos_y);

        dump(row,col);
    }
}

void dump(int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
}