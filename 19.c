#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int temp = n,o=0,z=0;
    while(temp!=0){
        if(temp%2 == 0){
            z++;
        }
        else if(temp%2 == 1){
            o++;
        }
        temp /= 2;
    }
    if(o==z)
    printf("\nNice");
    else printf("\nBad    ");
    return 0;

}
