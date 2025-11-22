#include<stdio.h>
#include<stdlib.h>
#define N 100
int stack[N];
int top=-1;
void display();
void push(){
    int l;
    printf("enter element to be inserted\n");
    scanf("%d",&l);
    if(top==N-1){printf("Stack overflow");}
    else{
        top++;
        stack[top]=l;
        printf("%d is pushed into stack\n",stack[top]);
        display();
    }
}
void pop(){
    if(top==-1){printf("Stack underflow");}
    else{
       int item =stack[top];
       top--;
       printf("%d is popped out of stack\n",item);
       display();
    }
}
void peek(){
    if(top==-1){printf("Stack underflow");}
    else{
        printf("top element in stack is:%d",stack[top]);
    }
}
void display(){
    if(top==-1){printf("empty stack");}
    else{
        printf("\nElements in the stack are:\t");
        for(int i=top;i>=0;i--){
            printf("%d\t",stack[i]);
        }
    }
}
int main(){
    int ch;
    while(1){
        printf("\n1.Push\t2.Pop\t3.Peek\t4.Dislpay\t5.Exit\n");
        printf("Enter stack opertaion:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
                break;
            }
    }
    return 0;
}
