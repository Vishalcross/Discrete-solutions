#include<stdio.h>
int main(){
    int a,b,ans,i;
    scanf("%d %d", &a,&b);
    a = a%10;
    if(a==0 || a== 1 || a==5 || a== 6){
        ans = a;
    }
    else if(a==2 || a==3 || a == 7|| a==8){
        ans = 1;
        for(i=0;i<b%4;i++){
            ans = ans*a;
        }
        if(b%4==0) ans = a*a*a*a;
        ans = ans%10;
    }
    else{
        ans = 1;
        for(i=0;i<b%2;i++){
            ans = ans*a;
        }
        if(b%2==0) ans = a*a;
        ans = ans%10;
    }
    if(b==0){
        ans = 1;
    }
    printf("%d", ans);
    return 0;
}
