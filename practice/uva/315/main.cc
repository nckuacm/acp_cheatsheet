#include <cstdio>
#include <sstream>

bool adjacent[101][101];
bool status[101];

void DFS(int id,int N){
    status[id]=true;
    for(int j=1;j<=N;j++){
        if(adjacent[id][j] && !status[j]){
            status[j]=true;
            DFS(j,N);
        }
    }
}

int main(){
    int N;
    char line[1024];
    bool copy[101][101];
    while(1){
        // get nodes
        scanf("%d\n",&N);
        if(!N)
            break;
        for(int i=1;i<=N;i++){
            status[i]=false;
            for(int j=1;j<=N;j++){
                adjacent[i][j]=false;
                copy[i][j]=false;
            }
        }
        // get the next N line
        int counter=0;
        while(fgets(line,1024,stdin) != NULL && counter < N){
            std::stringstream ss(line);
            int firstnode=0,secnode;
            ss >> firstnode;
            if(firstnode == 0)
                break;
            else{
                while(ss>>secnode){
                    // printf("%d - %d\n",firstnode,relation);
                    adjacent[firstnode][secnode]=true;
                    adjacent[secnode][firstnode]=true;
                    copy[firstnode][secnode]=true;
                    copy[secnode][firstnode]=true;
                }
            }
            counter++;
        }

        /*printf("Adjacent:\n");
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                printf("%d ",(adjacent[i][j]==true)?1:0);
            }
            printf("\n");
        }
        printf("\n");*/

        // and then we can searching critical nodes
        int critical=0;
        for(int r=1;r<=N;r++){
            // r = removed node
            for(int i=1;i<=N;i++){
                adjacent[r][i]=false;
                adjacent[i][r]=false;
                status[i]=false;
            }
            if(r==1)
                DFS(2,N);
            else
                DFS(1,N);

            for(int i=1;i<=N;i++){
                if(i!=r && !status[i]){
                    critical++;
                    break;
                }
            }
            for(int i=1;i<=N;i++){
                adjacent[r][i]=copy[r][i];
                adjacent[i][r]=copy[i][r];
            }
        }
        printf("%d\n",critical);
        
    }
    return 0;
}