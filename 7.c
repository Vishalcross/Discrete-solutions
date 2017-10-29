#include<stdio.h>
int gcd(int a, int b);
int main(){
    int nr, dr;
    scanf("%d %d", &nr, &dr);
    int rank = 1;
    int p=1,q=1,r=1;

    while(1){
            if(p==nr && q==dr) break;
            //printf("test1");
        //move left
        if(p%2==0 && q==1){
            p++;
            rank++;
        }
        //move down
        else if(p==1 && q%2==1){
            q++;
            rank++;
        }
        //diagonally down
        else if(p%2==1 && q==1){
            int x=p,y=q;
            while(x!=q){
                x--;
                y++;
                if(gcd(x,y)==1){
                    rank++;
                }
                if(x==nr && y==dr){
                    break;
                }
            }
            p = x;
            q = y;
        }
        //diagonally up
        else if(p==1 && q%2==0){
            int x=p,y=q;
            while(x!=q){
                x++;
                y--;
                if(gcd(x,y)==1){
                    rank++;
                }
                if(x==nr && y==dr){
                    break;
                }
            }
            p = x;
            q = y;
        }
    }
    printf("%d", rank);
}
int gcd(int a,int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

