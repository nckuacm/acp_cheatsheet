#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
/* Using "BFS" to solve first */

int maze[1001][1001];
int row,col;
// point type
struct point{
    int x;
    int y;
};
// record the fire location
vector< queue<point> > QF;

// 
const int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int escape(point Joe){
    queue<point> QJ;
    QJ.push(Joe);
    point curr,next;
    int minute;

    while(!QJ.empty()){
        for(int i=0;i<QF.size();++i){
            if(!QF[i].empty()){
                curr=QF[i].front();
                minute=maze[curr.x][curr.y];
            }
            while(!QF[i].empty()){
                curr=QF[i].front();
                if(maze[curr.x][curr.y]!=minute) break;
                QF[i].pop();
                for(int x=0;x<4;++x){
                    next.x=curr.x+direction[x][0];
                    next.y=curr.y+direction[x][1];
                    if(next.x<0||next.x>=row||next.y<0||next.y>=col) continue;

                    if(maze[next.x][next.y]==0){
                        maze[next.x][next.y]=maze[curr.x][curr.y]-1;
                        QF[i].push(next);
                    }
                }
            }
            curr=QJ.front();
            minute=maze[curr.x][curr.y];
            while(!QJ.empty()){
                curr=QJ.front();
                if(maze[curr.x][curr.y]!=minute) break;

                QJ.pop();

                for(int x=0;x<4;++x){
                    next.x = curr.x + direction[x][0];
                    next.y = curr.y + direction[x][1];
                    if (next.x < 0 || next.x >= row || next.y < 0 || next.y >= col)
                        return maze[curr.x][curr.y];
                    if (maze[next.x][next.y] == 0) {
                        maze[next.x][next.y] = maze[curr.x][curr.y] + 1;
                        QJ.push(next);
                    }
                }
            }
        }
    }
    return -1;
}


int main(){
    char line[1024];
    int testcase;
    // get testcase 
    scanf("%d",&testcase);

    while(testcase--){
        // get row,col
        scanf("%d",&row);
        scanf("%d",&col);
        point Joe;
        QF.clear();
        // readline and then insert into maze
        for(int i=0;i<row;i++){
            scanf("%s",line);
            for(int j=0;j<col;j++){
                // record the Joe's & fire's location
                if(line[j]=='J'){
                    Joe={i,j};
                    maze[i][j]=1;
                }
                else if(line[j]=='.'){
                    maze[i][j]=0;
                }
                else if(line[j]=='#'){
                    maze[i][j]=-1;
                }
                else if(line[j]=='F'){
                    queue<point> tmp;
                    tmp.push({i,j});
                    QF.push_back(tmp);
                    maze[i][j]=-2;
                }
            }
        }
        
        // finish IO problem, then using backtracking to find whether if Joe's can escape from maze or not
        int minute=escape(Joe);

        // printf("The last pos: %d, %d\n",last_x,last_y);
        if(minute==-1) puts("IMPOSSIBLE");
        else printf("%d\n",minute);
    }
    return 0;
}

void dump(int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}