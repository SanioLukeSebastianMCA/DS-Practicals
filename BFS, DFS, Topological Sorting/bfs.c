#include<stdio.h>
int a[20][20], q[20], visited[20], n, f = 0, r = -1;
void bfs(int);

void main(){

 	int v;
 	printf("\nBreadth First Search.\n\n");
 	printf("\nEnter the number of vertices for the matrix : ");
 	scanf("%d", &n);

 	printf("\nEnter each graph elements in matrix format : \n");
 	for(int i=1; i<=n; i++){
        q[i] = 0;
 		visited[i] = 0;
		for(int j=1;j<=n;j++){
			scanf("%d", &a[i][j]);
		}
	}

	printf("\nEnter the starting vertex : ");
	scanf("%d", &v);
	bfs(v);

	printf("\nThe reachable nodes are given as : \n");
	for(int i=1; i <= n; i++){
		if(visited[i])
            printf("%d\t", i);
		else{
			printf("\nBFS is not possible !! Not all nodes are reachable.");
			break;
		}
	}
}

void bfs(int v){
	for(int i = 1; i <= n; i++){
		if(a[v][i] && !visited[i])
			q[++r] = i;
		if(f <= r){
			visited[q[f]] = 1;
			bfs(q[f++]);
		}
	}
}
