#include <cstdio>
#include <queue>

/* Using BFS to search the solution */

int row,col;

#define IN_MAZE(x,y) (x>=1&&x<=row&&y>=1&&y<=col)

// define the node
struct node{
    int x;
    int y;
};

// record the maze information from input
char maze[1002][1002];
int burn[1002][1002];
int visit[1002][1002];
// record "fire" and "Joe" move
std::queue<node> fire;
std::queue<node> joe;

// for direction
int dir[4][2]={ {1,0},{-1,0},{0,-1},{0,1} };
// total time spent
int total_time=0;
bool escape_flag;

// reset
void reset();
// spread the fire
void fire_spread();
// Joe escape
void escape();

int main(){
    char line[1024];
    int testcase;
    // get testcase 
    scanf("%d",&testcase);

    while(testcase--){
        // get row,col
        scanf("%d",&row);
        scanf("%d",&col);
        // readline
        for(int i=1;i<=row;i++)
            scanf("%s",maze[i]+1);
        
        // reset
        reset();
        // record the route fire
        fire_spread();
        // Joe walk
        escape();

        // printf("The last pos: %d, %d\n",last_x,last_y);
        if(escape_flag)
            printf("%d\n",total_time);
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}

void reset(){
    escape_flag=false;
    // clear fire, joe
    while(!fire.empty()) fire.pop();
    while(!joe.empty()) joe.pop();
    // searching for fire starting points and Joe
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++){
            // fire
            if(maze[i][j]=='F'){
                fire.push((node){i,j});
                burn[i][j]=0;
            }
            else{
                // non-fire
                burn[i][j]=-1;
            }
            // joe
            if(maze[i][j]=='J'){
                joe.push((node){i,j});
                visit[i][j]=0;
            }
            else{
                visit[i][j]=-1;
            }
        }
}

void fire_spread(){
    // next,current
    node next,curr;

    while(!fire.empty()){
        curr=fire.front();
        fire.pop();

        for(int d=0;d<4;d++){
            next.x=curr.x+dir[d][0];
            next.y=curr.y+dir[d][1];

            if(IN_MAZE(next.x,next.y) && maze[next.x][next.y] != '#'){
                if(burn[next.x][next.y]==-1){
                    burn[next.x][next.y]=burn[curr.x][curr.y]+1;
                    fire.push(next);
                }
            }
        }
    }
}

void escape(){
    // next, current
    node next,curr;

    while(!joe.empty()){
        curr=joe.front();
        joe.pop();

        for(int d=0;d<4;d++){
            next.x=curr.x+dir[d][0];
            next.y=curr.y+dir[d][1];

            // if Joe escape from the maze, then return
            if(!IN_MAZE(next.x,next.y)){
                escape_flag=true;
                total_time=visit[curr.x][curr.y]+1;
                return;
            }

            if(maze[next.x][next.y]!='#' && (burn[next.x][next.y]==-1 || visit[curr.x][curr.y]+1 < burn[next.x][next.y])){
                // if next place ever touch before , go to here
                if(visit[next.x][next.y]==-1){
                    visit[next.x][next.y]=visit[curr.x][curr.y]+1;
                    joe.push(next);
                }
            }
        }
    }
}