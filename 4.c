// C++ program to print all topological sorts of a graph
#include<stdio.h>
#include<string.h>
int count = 0;
struct vertex{
    int indegree;
};
void util(int V, int visited[V], struct vertex g[V], int adj[V][V]){
    int flag = 0,i,j;
    for(i=0;i<V;i++){
        if(g[i].indegree==0 && visited[i]==0){
            for(j=0;j<V;j++){
                if(adj[i][j]==1){
                    g[j].indegree--;
                }
            }
            printf("Count = %d, inside = %d\n",count,i);
            visited[i] = 1;
            util(V,visited,g,adj);
            visited[i] = 0;
            for(j=0;j<V;j++){
                if(adj[i][j]==1){
                    g[j].indegree++;
                }
            }
            flag = 1;
        }
    }

    if(flag==0) count++;
}
void toposort(int V, struct vertex g[V], int adj[V][V]){
    int visited[V];
    memset(visited,0,sizeof(visited));
    util(V,visited, g, adj);
}
// Driver program to test above functions
int main(){
	// Create a graph given in the above diagram
	int V,k,i;
	scanf("%d %d",&V,&k);
    struct vertex g[V];
    int adj[V][V];//initialisation
    memset(adj,0,sizeof(adj));
    for(i=0;i<V;i++){
        g[i].indegree = 0;
    }
	for(i=0;i<k;i++){//initialising the adj matrix
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x][y] = 1;
        g[y].indegree++;
	}
	toposort(V,g,adj);
    printf("%d",count);
	return 0;
}
