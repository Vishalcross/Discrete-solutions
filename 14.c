#include<stdio.h>
#include<math.h>
int combination(int n, int r);
int factorial(int n);
int links(int N, int n, int count);
int main(){
    int n,count=0;
    scanf("%d",&n);
    count = links(n,1,count);
    printf("%d",count);
    return 0;
}
int combination(int n, int r){
    int nFact = factorial(n),rFact = factorial(r), x = factorial(n-r);
    return nFact/(rFact*x);
}
int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}
//number of subsets of a set sized n with size n-1 is nC(n-1) therefore for n-1 sized sets, number of links = n-1C n-2 * n-1
//when this hits 1, number of subsets = 1C0 * n
int links(int N, int n, int count){
    //n begins from 1
    if(n==N+1) return 0;
    count += links(N,n+1,count) + (combination(N,N-n+1)) * (combination(N-n+1,N-n));
    return count;
}
