#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int parent[1000000];

int Find(int num){
	while(parent[num] != num)
		num = parent[num];
	return num;
}

void Union(int p1, int p2){
	parent[p1] = p2;
	return;
}
int main(){
	int cas;
	scanf("%d", &cas);
	while(cas--){
		int n;
		scanf("%d", &n);
		getchar();
		for(int i=0;i <= n;i++)
			parent[i] = i;
		char str[50], *ptr, type;
		int num1, num2, p1, p2, yes=0, no=0;
		while(fgets(str, sizeof(str), stdin)){
			if(!strcmp(str, "\n"))
				break;
			ptr = strtok(str, " ");
			type = ptr[0];
			ptr = strtok(NULL, " ");
			num1 = atoi(ptr);
			ptr = strtok(NULL, " ");
			num2 = atoi(ptr);
			p1 = Find(num1);
			p2 = Find(num2);
			if(type == 'c'){
				if(p1 != p2)
					Union(p1, p2);
			}
			else{
				if(p1 == p2)
					yes++;
				else
					no++;
			}
		}
		printf("%d,%d\n", yes, no);
		if(cas != 0)
			printf("\n");
	}
	return 0;
}