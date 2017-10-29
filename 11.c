#include<stdio.h>
#include<math.h>
void subset_generator(int n, int number,int sequence[n], int s[number][n]);
int two_pair(int n, int a[n]);
int main(){
    //need to call subset generator once and store all the 2^n subsets
    //then examine each for pairs under the divisibilty relation
    int n,i,j;
    scanf("%d",&n);
    int sequence[n];//the given set
    for(i=0;i<n;i++) scanf("%d",&sequence[i]);
    int number = (int) pow(2,n);//number of elements in power set
    int s[number][n];//holds the subsets
    for(i=0;i<number;i++){//fills the subsets with bullshit so as to avoid random values
        for(j=0;j<n;j++) s[i][j]=-1;
    }
    subset_generator(n,number,sequence,s);//the mighty generator which fills s

    for(i=0;i<number;i++){//create two pairs and test them out
        int size=0;
        for(j=0;j<n;j++){//size of each subset
            if(s[i][j]!=-1){
                size++;
            }
            else break;
        }
        if(size<2) continue;
        int a[size];//subset holder to send inside two_pair
        for(j=0;j<size;j++) a[j] = s[i][j];//now holding...
        int pairs = two_pair(size,a);//no. of pairs which divide
        if(pairs%2==0 && size%2==0){//even
            for(j=0;j<size;j++) printf("%d ",a[j]);
            printf("\n");
        }
        else if(pairs%2==1 && size%2==1){//odd
            for(j=0;j<size;j++) printf("%d ",a[j]);
            printf("\n");
        }
    }
    return 0;
}
void subset_generator(int n, int number, int sequence[n], int s[number][n]){//flawless
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
                        s[i][l++] = sequence[k];
                    binary[i] /= 10;
                }
            }
        }
    }
}
int two_pair(int n, int a[n]){//looks not so good
    int number = (int) pow(2,n),counter=0;
    int i,j,binary[number];
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
        if(count==2){//subsets of size two
            int l=0,x[2];
            for(j=0;j<n;j++){
                if(binary[i]%10 == 1)
                    x[l++] = a[j];
                binary[i] /= 10;
            }
            if(x[1]%x[0] == 0){
                counter++;
            }
        }
    }
    return counter;
}
