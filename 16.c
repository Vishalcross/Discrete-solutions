#include<stdio.h>
int main(){
    int i,j,n,k,l,anti=0,trans=0;
    scanf("%d %d",&n,&k);
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j] = 0;
            if(i==j) a[i][j] = 1;
        }
    }
    for(i=0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x][y] = 1;
    }

    //transitive?
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==1){
                for(l=0;l<n;l++){
                    if(a[l][i]==1 && a[l][j]==0){
                        a[l][j] = 1;
                    }
                }
            }
        }
    }

    //anti-symmetric
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                if(a[i][j]==1 && a[j][i]==1){
                    anti=1;
                    break;
                }
            }
        }
        if(anti==1) break;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++) printf("%d ",a[i][j]);
        printf("\n");
    }

    if(anti==0 && trans==0) printf("Possible");
    else printf("%d Not Possible",trans);

    return 0;
}
