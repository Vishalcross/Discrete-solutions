#include<stdio.h>
#include<string.h>
int main(){
    int n,k,i,j,zero=0,count=0;
    scanf("%d %d",&n,&k);
    int a[n][n],eliminated[n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) a[i][j] = 0;
    }
    memset(eliminated,0,sizeof(eliminated));
    for(i=0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x][y] = 1;
    }
    //coloumn and row elimination?
    while(1){
        if(count==n) break;
        for(i=0;i<n;i++){
            zero = 0;
            if(eliminated[i]==0){
                for(j=0;j<n;j++){
                    if(a[j][i]>0){
                        zero = 1;
                        break;
                    }
                }
                if(zero==0){
                count++;
                eliminated[i] = 1;
                printf("%d ",i);
                for(j=0;j<n;j++){
                    a[i][j] = -1;
                    a[j][i] = -1;
                }
                break;
            }
            }
        }
    }
    return 0;
}
