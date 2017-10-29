#include<stdio.h>
int main(){
    int e,m,i,j,x,y;
    scanf("%d %d",&e,&m);
    int length = e-m+1;
    int vals[length];//stores all values from m to e
    for(i=m;i<=e;i++) vals[i-m] = i;//initialising from e to m
    int table[e+1][length];//table storing the iterated values
    for(i=0;i<length;i++) table[0][i] = 1;//partitions of 0 is 1;
    for(i=1;i<e+1;i++){//traverse and fill the table
        x=y=0;
        for(j=0;j<length;j++){
            x = (i-vals[j]>=0 ? table[i-vals[j]][j] :0);
            y = (j>=1 ? table[i][j-1] :0);
            table[i][j] = x+y;
        }
    }
    printf("%d",table[e][length-1]);
    return 0;
}

