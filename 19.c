/*Find the number of 1's and 0's in the binary representation of a number
@author
Vishal Chokala
*/
#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int temp = n,o=0,z=0;
    while(temp!=0){
        if(temp%2 == 0){
            z++;//Increment the number of zeros
        }
        else if(temp%2 == 1){
            o++;//Increent the number of ones
        }
        temp /= 2;//Right shift
    }
    if(o==z)//If they are equal, we have to print nice.
    printf("\nNice");
    else printf("\nBad    ");
    return 0;

}
