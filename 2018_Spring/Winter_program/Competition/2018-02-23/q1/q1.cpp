#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
//mapping: map to group
int parent[200100], sum[200100], size[200100];

int Find(int num){
	while(parent[num] != num)
		num = parent[num];
	return num;
}

void Union(int p1, int p2){
	parent[p1] = p2;
	sum[p2] += sum[p1];
	size[p2] += size[p1];
	return;
}

void Move(int num1, int p1, int p2){
	sum[p1] -= num1;
	sum[p2] += num1;
	size[p1]--;
	size[p2]++;
	parent[num1] = p2;
	return;
}

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		int command, num1, num2;
		//initial
		memset(parent, 0, sizeof(parent));
		memset(sum, 0, sizeof(sum));
		memset(size, 0, sizeof(size));
		for(int i=1;i <= n;i++){
			parent[i] = i+n;
			parent[i+n] = i+n;
			sum[i+n] = i;
			size[i+n] = 1;
		}
		for(int i=0;i < m;i++){
			scanf("%d %d", &command, &num1);
			if(command != 3){
				scanf("%d", &num2);
				//find if 2 numbers in same group
				int p1 = Find(num1);
				int p2 = Find(num2);
				if(p1 != p2){
					if(command == 1)
						Union(p1, p2);
					else if(command == 2){
						Move(num1, p1, p2);
					}
					else;
				}
			}
			else{
				//find
				int p = Find(num1);
				printf("%d %d\n", size[p], sum[p]);
			}
		}
	}
	return 0;
}