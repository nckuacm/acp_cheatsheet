#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int parent[30100], size[30100], ans;

int Find(int num){
	while(parent[num] != num)
		num = parent[num];
	return num;
}

void Union(int p1, int p2){
	parent[p1] = p2;
	size[p2] += size[p1];
	return;
}

int main(){
	int cas, n, m;
	while(scanf("%d", &cas) != EOF){
		while(cas--){
			//initial
			memset(parent, 0, sizeof(parent));
			memset(size, 0, sizeof(size));
			scanf("%d %d", &n, &m);
			for(int i=1;i <= n;i++){
				parent[i] = i;
				size[i] = 1;
			}
			
			int num1, num2;
			for(int i=0;i < m;i++){
				scanf("%d %d", &num1, &num2);
				//find if 2 numbers in same group
				int p1 = Find(num1);
				int p2 = Find(num2);
				if(p1 != p2)
					Union(p1, p2);
			}
			int ans = 0;
			for(int i=1;i <= n;i++)
				if(parent[i] == i)
					ans = max(ans, size[i]);
			printf("%d\n", ans);
		}
	}
	return 0;
}