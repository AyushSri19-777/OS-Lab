#include<stdio.h>
#include <stdbool.h>
#define N 100

int Graph[N][N];

int q[N];
int vertices, edges;
char vertex;
int u,v,w;
int i,j;
int s,d;

void inputGraph(){
	printf("Number of Vertices and Edges: \n");
	scanf("%d%d", &vertices, &edges);

	for(i=1;i<=vertices;i++){
		for(j=1;j<=vertices;j++){
			Graph[i][j] = 0;
		}
	}

	printf("Enter connected vertices \n");

	for(i=1;i<=edges;i++){
		scanf("%d%d", &u, &v);
		Graph[u][v] = Graph[v][u] = 1;
	}
}

void printGraph(){
	printf("\nGraph: \n");

	for(i=1;i<=vertices;i++){
		for(j=1;j<=vertices;j++)
			printf("%d", Graph[i][j]);
		printf("\n");
	}
	printf("\n");
}

int visited[N];
int r = -1, f=0;

void dfs(int ver){
	int j;
    printf("\n%d",ver);
    visited[ver]=1;

    for(j=1;j<=vertices;j++)
       if(!visited[j] && Graph[ver][j]==1)
            dfs(j);
}

int main(){
	inputGraph();
	printGraph();
	int origin;
	printf("Enter origin");
	scanf("%d", &origin);
	dfs(origin);
	}
