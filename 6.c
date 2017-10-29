#include<stdio.h>
int main(){
    int i,j,n,k,o;
    scanf("%d %d", &n,&k);
    int a[n],b[k][n],c[k];//c holds m, b holds implications and a holds propositions
    for(i=0;i<n;i++) a[i] = 0;
    for(i=0;i<k;i++){
        scanf("%d", &c[i]);//value of m
        for(j=0;j<c[i]+1;j++){
            scanf("%d", &b[i][j]);//implications holder
        }
    }
    scanf("%d",&o);
    for(i=0;i<o;i++){
        int x;
        scanf("%d",&x);
        a[x]++;//making 1 = true for all given values
    }
    printf("\n");
    for(i=0;i<k;i++){
        int x=0;
        for(j=0;j<c[i];j++){
            if(a[b[i][j]]==0){
                x=1;
            }
        }
        if(x==0) a[b[i][c[i]]]++;
    }
    for(i=0;i<n;i++){
        if(a[i]>0) printf("%d ",i);
    }
    return 0;
}
