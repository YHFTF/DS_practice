//선택정렬
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int SS(int n[],int size){
    int min=n[0],temp,tempj;
    for(int i=0; i<size; i++){
        for(int j=i;j<size;j++){
            if(min>n[j]){
                min = n[j];
                tempj=j;
            }
        }
        temp = n[i];
        n[i]= min;
        n[tempj] = temp;
        min = n[i+1];
    }
}
int main(){
    int size;
    srand(time(NULL));
    printf("input arr size : ");
    scanf("%d",&size);
    int n[size];

    printf("랜덤으로 채워진 10개의 수 : ");
    for(int i =0;i<10;i++){
        n[i]= rand()%100;
        printf("%d ",n[i]);
    }
    printf("\n");
    SS(n,size);
    printf("순서대로 정렬된 10개의 수 : ");
    for(int i=0;i<size;i++){
        printf("%d ",n[i]);
    }
    
}