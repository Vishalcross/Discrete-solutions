/* The objective of this porgram is to create a divisor lattice for a given input
@authors Vishal Chokala
Code optimized by tanmay Kulkarni
*/
#include<stdio.h>
#include<string.h>
#define MAX 1000

int main(){
	int num;
	printf("Enter the number\n");
	scanf("%d",&num);
	if(num<0){
		printf("invalid input\n");
		return 0;
	}
	int factors[MAX];
	int size=0;

	for(int i=1;i<=num;i++){
		if(num%i==0){
			factors[size++]=i;
		}
	}
	
	int divides[size][size];
	memset(divides,0,sizeof(divides));
	
	for(int i=0;i<size;i++){
		for(int j=0;j<=i;j++){
			if(i!=j && factors[i]%factors[j]==0){
				divides[i][j]=1; //i is divided by j
			}
		}
	}
	
	//Removing all the intermediate connections
	for(int i=size-1;i>=0;i--){
		for(int j=0;j<size;j++){
			if(divides[i][j]==1){
				for(int k=j;k<=i;k++){
					if(divides[i][k]==1 && divides[k][j]==1){
						divides[i][j]=0;
						break;
					}
				}
			}
		}
	}
	
	int count=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(divides[i][j]==1){
				count++;
			}
		}
	}
	
	printf("The answer is %d\n",count);
	return 0;
}
