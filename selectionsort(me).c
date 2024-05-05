//선택정렬
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n[10];
    srand(time(NULL));
    printf("랜덤으로 채워진 10개의 수 : ");
    for(int i =0;i<10;i++){
        n[i]= rand()%100;
        printf("%d ",n[i]);
    }
    printf("\n");

    printf("순서대로 정렬된 10개의 수 : ");
    int min=n[0],temp,tempj;
    for(int i=0; i<10; i++){
        for(int j=i;j<10;j++){
            if(min>n[j]){
                min = n[j];
                tempj=j;
            }
        }
        temp = n[i];
        n[i]= min;
        n[tempj] = temp;
        printf("%d ",n[i]);
        min = n[i+1];
    }
}