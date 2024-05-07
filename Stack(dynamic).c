#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int key;
}element;

element *stack;
int capacity = 1;
int top = -1;

int IsEmpty(){
    if(top == -1) return 1;
    else return 0;
}
void stackFull(){
    stack = realloc(stack,2*capacity*sizeof(*stack));
    capacity *=2;
}
void stackinit(){
    free(stack);
    stack = malloc(sizeof(*stack));
    top = -1;
    capacity = 1;
}
void push(int n){
    if(capacity == top){
        stackFull();
    }
    top ++;
    stack[top].key = n;
    printf("push success!\n");
}
int pop(){
    if(IsEmpty()){
        printf("stack is empty, can't pop!\n");
        return 0;
    }
    int temp = stack[top].key;
    top --;
    printf("%d\n",temp);
    return temp;
}
void show(){
    printf("------top------\n");
    for(int i =top ;i >=0;i--){
        printf("|      %d      |\n",stack[i].key);
    }
    printf("----bottom-----\n");
    printf("capacity = %d, top = %d",capacity,top);
}

int main(){
    stack = malloc(sizeof(*stack));
    char command;
    do
    {
        printf("------Command List------\n");
        printf("u = PUSH , p = POP , s = SHOW , i = INITstack\n");
        printf("------------------------\n");
        scanf(" %c",&command);
        switch (command)
        {
        case 'u':
            int n;
            scanf("%d",&n);
            push(n);
            break;
        case 'p':
            pop();
            break;
        case 's':
            show();
            break;
        case 'i':
            stackinit();
            break;
        default:
            break;
        }
    
    } while (command != 'q');
    return -1;
    

}