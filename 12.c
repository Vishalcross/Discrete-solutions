#include<stdio.h>
int main(){
	int i,j,k,n;
	scanf("%d",&n);
	int factors[100],size=0,count=0;
	for(i=1;i<=n;i++){
		if(n%i==0) factors[size++] = i;
	}
	int a[size][size];
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			a[i][j] = 0;
		}
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			int x=factors[i],y=factors[j];
			if(y%x==0 && y!=x) a[i][j] = 1;
		}
	}
	for(i=size-1;i>=0;i--){
		for(j=0;j<size;j++){
			if(a[i][j]==1){
				for(k=0;k<size;k++){
					if(a[k][i]==1 && a[k][j]==1){
						a[k][j] = 0;
					}
				}
			}
		}
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(a[i][j]==1) count++;
		}
	}
	printf("%d",count);
	return 0;
}
