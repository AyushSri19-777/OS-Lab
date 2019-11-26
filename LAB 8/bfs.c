#include<stdio.h>
#include <stdbool.h>
#define MAX 100

int matrix[MAX][MAX];

int q[MAX];
int vertices, edges, vertex;
int u,v,w;
int i,j;
int s,d;


void inputGraph(){
	printf("Number of Vertices and Edges: \n");
	scanf("%d%d", &vertices, &edges);

	for(i=1;i<=vertices;i++){
		for(j=1;j<=vertices;j++){
			matrix[i][j] = 0;
		}
	}

	printf("Enter connected vertices \n");

	for(i=1;i<=edges;i++){
		scanf("%d%d", &u, &v);
		matrix[u][v] = matrix[v][u] = 1;
	}
}

void printGraph(){
	printf("\nGraph: \n");

	for(i=1;i<=vertices;i++){
		for(j=1;j<=vertices;j++)
			printf("%d", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}

int visited[MAX];
int r = -1, f=0;
void bfs(int ver){
	for(i = 1; i <= vertices; i++)
		if(matrix[ver][i] && !visited[i])
			q[++r] = i;
	if(f <= r) {
		visited[q[f]] = 1;
		bfs(q[f++]);
	}
}

int main(){
	inputGraph();
	printGraph();
	int origin;
	printf("Enter origin");
	scanf("%d", &origin);

	bfs(origin);

	for(i=1;i<=vertices;i++){
		if(visited[i]){
			printf("%d, ", i);
		}
		else{
			printf("\nBFS Not Possible!All Nodes Not Reachable");
			break;
		}
	}
}
