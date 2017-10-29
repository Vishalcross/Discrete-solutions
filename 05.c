#include<stdio.h>
void find(int n,int a[n][n],int city, int count[n]);
int main(){
    int i,j,n,m;
    scanf("%d %d", &n,&m);
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) a[i][j] = 0;
    }
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d %d", &x,&y);
        a[x][y] = 1;
    }
    //all cities
    for(i=0;i<n;i++){
        int empty=0,count[n];
        for(j=0;j<n;j++) count[j] = 0;
        find(n,a,i,count);
        for(j=0;j<n;j++){
            if(count[j]==1){
                empty = 1;
            }
        }
        if(!empty) printf("-");
        else{
            for(j=0;j<n;j++){
                if(count[j]==1 && j!=i) printf("%d ",j);
            }
        }
        printf("\n");
    }
    return 0;
}
void find(int n, int a[n][n], int city, int count[n]){
    int i;
    for(i=0;i<n;i++){
        if(a[city][i]==1){
            if(count[i]==0){
                count[i] = 1;
                find(n,a,i,count);
            }
        }
    }
}
