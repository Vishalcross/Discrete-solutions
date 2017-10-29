#include<stdio.h>
#include<math.h>
void subset(int n, int number, int sequence[n], int subsets[number][n]);
int main(){
    int i,j,n,k,l;
    scanf("%d",&n);
    int s[n];//skill set
    for(i=0;i<n;i++) scanf("%d",&s[i]);
    scanf("%d",&k);
    int c[k];//skills of colossus
    for(i=0;i<k;i++) scanf("%d",&c[i]);
    scanf("%d",&l);
    int r[l];//required set
    for(i=0;i<l;i++) scanf("%d",&r[i]);
    int temp = (int) pow(2,n);
    int subsets[temp][n];//the subsets holder
    for(i=0;i<temp;i++){//setting bullshit values once again
        for(j=0;j<n;j++) subsets[i][j] = -1;
    }
    subset(n,temp,s,subsets);//generator for subsets
    for(i=0;i<temp;i++){//checking each subset
        int size=0;
        for(j=0;j<n;j++){
            if(subsets[i][j]!=-1) size++;
        }
        //first screening
        if(size+k < l) continue;
        else{
            int counter[n+1],test=0,test2=0;
            for(j=0;j<n+1;j++) counter[j] = 0;
            for(j=0;j<size;j++){
                counter[subsets[i][j]]++;
            }
            for(j=0;j<k;j++){
                counter[c[j]]++;
            }
            for(j=0;j<l;j++){
                if(counter[r[j]]>0){
                    test++;
                }
                else test2=1;
            }
            for(j=1;j<n+1;j++){
                if(counter[j]>0){
                    test--;
                }
            }
            if(test2==1) continue;
            if(test==0){
                for(j=0;j<size;j++){
                    printf("%d ",subsets[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
void subset(int n, int number, int sequence[n], int subsets[number][n]){//flawless
    int i,j,binary[number],k;
    for(i=0;i<number;i++){
        binary[i]=0;
        int b = 1,count=0,num=i;
        while(num>0){
            if(num%2==1)
                count++;
            binary[i] += (num%2)*b;
            b*=10;
            num/=2;
        }
        for(j=1;j<=n;j++){
            if(count==j){
                int l=0;
                for(k=0;k<n;k++){
                    if(binary[i]%10 == 1)
                        subsets[i][l++] = sequence[k];
                    binary[i] /= 10;
                }
            }
        }
    }
}
