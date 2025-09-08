#include <stdio.h>
#define Capacity 5
int top = -1, stk[Capacity];

void push(int ele){
    if(top == Capacity - 1){
        printf("Stack overflows\n");
        return;
    }
    top++;
    stk[top] = ele;
}

int pop(){
    if(top == -1){
        printf("Stack underflows\n");
        return 0;
    }
    return stk[top--];
}

void display(){
    for(int i = 0; i <= top; i++){
        printf("%d\n",stk[i]);
    }
}

void peek(){
    if(top == -1){
        printf("Stack is empty");
        return;
    }
    printf("%d\n",stk[top]);
}

int main(){
    pop();
    push(5);
    push(4);
    push(3);
    push(4);
    push(6);
    push(7);
    display();
    return 0;
}
