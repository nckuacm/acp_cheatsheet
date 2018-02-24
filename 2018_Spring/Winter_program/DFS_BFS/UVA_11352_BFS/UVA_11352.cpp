#include <cstring>
#include <cstdio>

char maps[101][101];
int  dxy[8][2] = {-2,-1,-2,1,2,-1,2,1,-1,-2,-1,2,1,-2,1,2};
int  Dxy[8][2] = {-1,-1,-1,0,-1,1,1,-1,1,0,1,1,0,-1,0,1};
int  Q[10001], S[10001];

int bfs(int x0, int y0, int n, int m)
{
    if (x0 < 0 || y0 < 0) return 0;
    int move = 0, save = 1;
    Q[S[0] = 0] = x0*100+y0;
    while (move < save) {
        int now = Q[move ++];
        for (int k = 0; k < 8; ++ k) {
            int x = now/100+Dxy[k][0];
            int y = now%100+Dxy[k][1];
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (maps[x][y] == 'B') return S[move-1]+1;
                if (maps[x][y] == '.') {
                    maps[x][y] = 'X';
                    Q[save] = 100*x+y;
                    S[save] = S[move-1]+1;
                    save ++;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int t, n, m;
    while (~scanf("%d",&t))
        while (t --) {
            scanf("%d%d",&n,&m);
            for (int i = 0; i < n; ++ i)
                scanf("%s",maps[i]);
            
            int s_x = -1, s_y = -1;
            for (int i = 0; i < n; ++ i)
                for (int j = 0; j < m; ++ j) {
                    if (maps[i][j] == 'A') {
                        s_x = i; s_y = j;
                    }
                    if (maps[i][j] != 'Z') continue;
                    for (int k = 0; k < 8; ++ k) {
                        if (i+dxy[k][0] < 0 || i+dxy[k][0] >= n) continue;
                        if (j+dxy[k][1] < 0 || j+dxy[k][1] >= m) continue;
                        if (maps[i+dxy[k][0]][j+dxy[k][1]] == '.')
                            maps[i+dxy[k][0]][j+dxy[k][1]] = 'X';
                    }
                }
            
            int step = bfs(s_x, s_y, n, m);
            if (step)
                printf("Minimal possible length of a trip is %d\n",step);
            else printf("King Peter, you can't go now!\n");
        }
    return 0;
}

