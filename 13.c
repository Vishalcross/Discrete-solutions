#include<stdio.h>
int main(){
    int i,j,n,m;
    scanf("%d %d", &n,&m);
    int a[n][n],k=1,isReflexive[n];
    for(i=0;i<n;i++){
        isReflexive[i] = 0;
        for(j=0;j<n;j++){
            a[i][j] = 0;
        }
    }
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d %d", &x,&y);
        a[x][y] = 1;
    }
    for(i=0;i<n;i++){
        if(a[i][i]==1){
            isReflexive[i] = 1;
            continue;
        }
        else{
            for(j=0;j<n;j++){
                if(a[i][j]==1 && a[j][i]==1){
                    isReflexive[i] = 1;
                    break;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(isReflexive[i]==0){
                k=0;
            printf("Not Reflexive");
        }
    }
    if(k) printf("Reflexive");
    return 0;
}
