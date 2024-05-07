#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct{
    int key;
}Queue;
int front = -1;
int rear = -1;
Queue queue[MAX_SIZE];

int queueFull(){
    if(rear == MAX_SIZE && front == MAX_SIZE){
        rear = -1;
        front = -1;
    }
}
int isEmpty(){
    if(rear==front) return 1;
    else return 0;
}
void addQ(int n){
    queueFull();
    rear ++;
    queue[rear].key = n;
}
int deleteQ(){
    if(isEmpty()){
        printf("Q is empty\n");
        return 0;
    }
    front++;
    printf("%d\n",queue[front].key);
    
}
void show(){
    for(int i = front+1; i <= rear ; i++){
        printf("%d ",queue[i].key);
    }
    printf("front = %d ",front);
    printf("rear = %d\n",rear);

}
int main(){
    char command;
    do
    {
        printf("------Command List------\n");
        printf("a = addQ , d = deleteQ , s = SHOW\n");
        printf("------------------------\n");
        scanf(" %c",&command);
        switch (command)
        {
        case 'a':
            int n;
            scanf("%d",&n);
            addQ(n);
            break;
        case 'd':
            deleteQ();
            break;
        case 's':
            if(isEmpty()){
                printf("Q is empty!\n");
            }
            show();
            break;
        default:
            break;
        }
    
    } while (command != 'q');
    return -1;
}