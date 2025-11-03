#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1,rear=-1;
void enqueue(int x){
    if( rear==-1 && front==-1){
        front=rear=0;
        queue[rear]=x;
        printf("%d is inserted into queue\n",x);
    }
    else if(rear==N-1){
        printf("Queue overflow\n");
    }
    else{
        queue[++rear]=x;
        printf("%d is inserted into queue\n",x);
    }
}
void dequeue(){
    if (front==-1 | front>rear){
        printf("Queue underflow\n");
    }
    else{
        printf("%d is deleted from queue\n",queue[front++]);
    }
}
void display(){
    if (front==-1 | front>rear){
        printf("Queue underflow\n");
    }
    else{
        printf("Elements in the queue are\n");
        for(int i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}
int main(){
    int ch;
    while(1){
        printf("\nselect operation on queue to perform\n");
        printf("1.Insertion\t2.Deletion\t3.Display\t4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter an element to be inserted:");
                int x;
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
