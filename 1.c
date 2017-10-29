#include <stdio.h>
#include<math.h>
int main(){
    int n,N;
    scanf("%d", &n);//number of partitions
    int a[n][100],size[n],j,counter1,counter2;
    int i,k,l;
    for(i=0;i<n;i++){
        scanf("%d", &size[i]);//size of each group
        for(j=0;j<size[i];j++){
            scanf("%d", &a[i][j]);//inputting group
        }
    }
    //the main generator coupled with subset generator
    for(j=0;j<n;j++){//loop for all groups
        if(size[j]>1){//size of group is the control
            int sequence[size[j]];//stores the group
            for(i=0;i<size[j];i++) sequence[i] = a[j][i];//intialising
            int number = (int) pow(2,size[j]),m;//classic variables
            int binary[number];
            int p[size[j]];//stores the rest of elements
            for(i=0;i<size[j];i++) p[i] = 0;
            i=0;
            for(k=0;k<number;k++){//for all subsets
                for(i=0;i<size[j];i++) p[i] = 0;
                int b = 1;
                binary[k] = 0;
                int num = k, count = 0;
                while (num > 0){//bit string
                    if (num % 2 == 1)
                        count++;
                    binary[k] += (num % 2) * b;
                    num /= 2;
                    b = b * 10;
                }

                for(N=1;N<=size[j]/2;N++){//N counts till the number of subsets needed
                    if (count == N){//upar dekh
                        for(counter2=0;counter2<n;counter2++){//print the subsets of the selected group
                            if(counter2==j){//only the selected group passes
                                for (l = 0; l < size[j]; l++){//print the subsets
                                    if (binary[k] % 10 == 1){
                                        printf("%d ",sequence[l]);
                                        p[l] = 1;
                                    }
                                    binary[k] /= 10;
                                }
                                printf("\n");
                                for(m=0;m<size[j];m++){//store the leftovers
                                    if(p[m] == 0){
                                        printf("%d ",sequence[m]);
                                    }
                                }
                                printf("\n");
                            }
                            else{//print the rest of the groups
                                for(counter1=0;counter1<size[counter2];counter1++){
                                    printf("%d ", a[counter2][counter1]);
                                }
                                printf("\n");
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
