#include<stdio.h>
void next(int f, int n, int push[n],int visited[n]);
int main(){
    int n,i,j;
    scanf("%d",&n);
    int push[n],visited[n],count=0;

    for(i=0;i<n;i++){
        scanf("%d",&push[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) visited[j] = 0;
        next(i,n,push,visited);
        if(visited[i]==2){
            count++;
        }
        printf("\n");
    }
    printf("%d", count);
    return 0;
}
void next(int f, int n, int push[n],int visited[n]){
    if(visited[f]<=1){
        printf("%d %d ",visited[f],f);
        visited[f]++;
        f = (f+push[f])%n;
        if(visited[f]==2){
            return;
        }
        next(f,n,push,visited);
    }
}
