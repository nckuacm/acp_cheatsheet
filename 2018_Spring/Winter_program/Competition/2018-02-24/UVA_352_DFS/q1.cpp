#include<cstdio>
#include<iostream>
using namespace std;

char ans[26][26];

void DFS(int &n,int i,int j){

    ans[i][j] = '0';

    if (i-1 >= 0 && j-1 >= 0)
        if (ans[i-1][j-1] == '1') DFS(n,i-1,j-1);
    if (j-1 >= 0)
        if (ans[i][j-1] =='1') DFS(n,i,j-1);
    if (j-1 >= 0 && i+1 < n)
        if (ans[i+1][j-1] == '1') DFS(n,i+1,j-1);
    if (i+1 < n)
        if (ans[i+1][j] =='1') DFS(n,i+1,j);
    if (i+1 < n && j+1 < n)
        if (ans[i+1][j+1] == '1') DFS(n,i+1,j+1);
    if (j+1 < n)
        if (ans[i][j+1] =='1') DFS(n,i,j+1);
    if (i-1 >= 0 && j+1 < n)
        if (ans[i-1][j+1] == '1') DFS(n,i-1,j+1);
    if (i-1 >= 0)
        if (ans[i-1][j] =='1') DFS(n,i-1,j);
}

int main(){
    int i,j,n;
    int k=0;
    int count = 0;

    while (scanf("%d\n",&n) != EOF)
    {
        for (i=0;i<n;i++)
                fgets(ans[i],1024,stdin);

        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
            {
                if (ans[i][j] == '1')
                {
                    DFS(n,i,j);
                    count++;
                }
            }
        k++;
        cout<<"Image number "<<k<<" contains "<<count<<" war eagles."<<endl; 
        count = 0;
    }

}
