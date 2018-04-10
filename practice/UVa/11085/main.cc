#include <cstdio>
#include <vector>

// Record
int col_record[8];
bool row[8]={0}, left[15]={0}, right[15]={0};
// Solution table
int all_sol[100][8];
int nOf_sol=0;

void build_sol_table(int c){
    if(c==8){
        for(int i=0;i<8;i++){
            all_sol[nOf_sol][i]=col_record[i]+1;
        }
        ++nOf_sol;
        return;
    }
    for(int r=0;r<8;r++){
        int lb = c-r+7; // left bound
        int rb = c+r; // right bound
        // Check this position has been occupied or not
        if(!row[r] && !left[lb] && !right[rb]){
            row[r]=1, left[lb]=1, right[rb]=1;
            // then record current place into col record
            col_record[c]=r;
            // Then go to next position
            build_sol_table(c+1);
            // recover status
            row[r]=0, left[lb]=0, right[rb]=0;
        }
    }
}

int main(){
    // Build all the solution into table
    build_sol_table(0);

    int row_position[8],testcase=1;

    // Read the first element of each line 
    while(scanf("%d",&row_position[0])!=EOF){
        // read the rest of them
        for(int i=1;i<8;i++)
            scanf("%d",&row_position[i]);
        
        // Maximize the min value (for comparison)
        int MIN=100000;

        // traversal all the solution
        for(int i=0;i<nOf_sol;i++){
            int steps=0;
            // calculate the move, compare with each solution
            for(int c=0;c<8;c++){
                if(all_sol[i][c] != row_position[c])
                    ++steps;
            }
            // compare with min
            if(steps<MIN) MIN=steps;
        }

        // print result
        printf("Case %d: %d\n",testcase++,MIN);
    }
}