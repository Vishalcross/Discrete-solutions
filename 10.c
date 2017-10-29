#include<stdio.h>
int main(){
    int i,n,zero=0,one=0,mone=0,yes=0,neg=0,pos=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){//cannotn say : n==1
        int temp;
        scanf("%d",&temp);
        if(temp==0) zero++;
        if(temp==1) one++;
        if(temp==-1) mone++;
        if(temp<-1) neg++;
        if(temp>1) pos++;
    }
    if(n>1){
        if((zero==1||one==1) && n==2){
            yes=1;
        }
        else if(zero==1 && one==1 && n==3){
            yes=1;
        }
        else if(mone>0 && one>0 && neg==0 && pos==0){
            yes = 1;
        }
    }
    else if(n==1){
        yes = 2;
    }

    if(yes==0){
        printf("No");
    }
    else if(yes==1){
        printf("Yes");
    }
    else if(yes==2) printf("Cannot say");
    return 0;
}
