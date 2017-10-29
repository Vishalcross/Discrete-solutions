#include<stdio.h>
int main(){
    int i,j,n,moves=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        moves*=temp;
    }
    moves-=1;
    if(moves%2 == 1){
        printf("Uatu");
    }
    else printf("Galactus");
    return 0;
}
