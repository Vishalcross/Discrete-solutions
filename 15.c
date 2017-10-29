#include<stdio.h>
int main(){
    int n,k,i,j,l;
    scanf("%d %d",&n,&k);
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) a[i][j] = 0;
    }
    for(i=0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x][y] = 1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
    //reflexive check
    int reflexive=0, anti=0, transitive=0;
    for(i=0;i<n;i++){
        if(a[i][i]==0){
            reflexive = 1;
            break;
        }
    }
    if(reflexive==0){
        //anti-symmetric?
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i!=j){
                    if(a[i][j]==1){
                        if(a[j][i]==1){
                            anti = 1;
                            break;
                        }
                    }
                }
            }
            if(anti==1) break;
        }
        if(anti==0){
            //transitive?
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(i!=j){
                        if(a[i][j]==1){
                            for(l=0;l<n;l++){
                                if(a[j][l]==1){
                                    if(a[i][l]==0){
                                        transitive=1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if(transitive==1) break;
                }
                if(transitive==1) break;
            }
        }
    }
    if(!reflexive && !anti && !transitive) printf("Yes");
    else printf("No");
    return 0;
}
