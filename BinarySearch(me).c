#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
int BS(int arr[],int find,int size){
    int middle,left=0,right=size-1,result;
    while(1){
        middle = (left+right)/2;
        if(arr[middle] < find){
            left = middle+1;
        }
        else if(arr[middle] > find){
            right = middle-1;
        }
        else{
            return middle;
            break;
        }
    }
}
void fillArr(int arr[],int size){
    srand(time(NULL));
    for(int i=0;i<size;i++){
        arr[i]=rand()%1000;
    }
}

int main(){
    int size,find;
    printf("Input array size : ");
    scanf("%d",&size);
    int arr[size];
    fillArr(arr,size);
    SS(arr,size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\nInput search number : ");
    scanf("%d",&find);
    printf("find index : %d",BS(arr,find,size));
}