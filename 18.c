#include<stdio.h>
#include<math.h>
int main(){
    int i,j,n,k;
    scanf("%d", &n);
    int sequence[n];
    for(i=0;i<n;i++){
        scanf("%d", &sequence[i]);
    }
    scanf("%d", &k);
    int number = (int) pow(2,n);
    int binary[number];
    for(i=0;i<number;i++){
        int b = 1;
        binary[i] = 0;
        int num = i, count = 0;
        while (num > 0){
            if (num % 2 == 1)
                count++;
            binary[i] += (num % 2) * b;
            num /= 2;
            b = b * 10;
        }
        if(count==k){
            for(j=0;j<n;j++){
                if(binary[i]%10==1)
                    printf("%d ",sequence[j]);
                binary[i]/=10;
            }
            printf("\n");
        }
    }
    return 0;
}
