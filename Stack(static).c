#include <stdio.h>
#define MAX_SIZE 20
int push(int n);
int pop();
void show();
int isEmpty();
int isFull();

int top=-1;
int stack[MAX_SIZE];
int main(){
    char command;
    do
    {
        printf("Command List\n");
        printf("u = push , p = pop , s = show , e = isEmpty , f = isFull\n");
        scanf(" %c",&command);
        switch (command)
        {
        case 'u':
            int n;
            scanf("%d",&n);
            push(n);
            break;
        case 'p':
            printf("%d\n",pop());
            break;
        case 's':
            show();
            break;
        case 'e':
            if(isEmpty()) printf("stack is empty\n");
            else printf("stack is not empty\n");
            break;
        case 'f':
            if(isFull()) printf("stack is full\n");
            else printf("stack is not full\n");
            break;
        default:
            break;
        }
    
    } while (command != 'q');
    return -1;
}
int push(int n){
    if(isFull()){
        printf("stack is full");
        return 0;
    }
    top++;
    stack[top] = n;
    printf("success\n");
}
int pop(){
    if(isEmpty()){
        printf("stack is empty");
        return 0;
    }
    int temp;
    temp = stack[top];
    top--;
    return temp;
}
void show(){
    for(int i= MAX_SIZE-1 ;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("top is : %d\n",top);
}
int isEmpty(){
    if(top == -1) return 1;
    else return 0;
}
int isFull(){
    if(top == MAX_SIZE-1) return 1;
    else return 0;
}