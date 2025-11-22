#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1,rear=-1;
void enqueue(int x){
    if((rear==N-1 & front==0) || rear+1==front){
        printf("Queue is full!!\n");
    }
    else{
        if(front==-1 & rear==-1){
            front=rear=0;
        }
        else{rear=(rear+1)%N;}
        queue[rear]=x;
        printf("%d is inserted into queue\n",x);
    }
}
void dequeue(){
    if (front==-1){
        printf("Queue is empty!!\n");
    }
    else{
        if(front==rear){
            printf("%d is deleted from queue\n",queue[front]);
            front=rear=-1;
        }
        else{
        printf("%d is deleted from queue\n",queue[front]);
        front=(front+1)%N;
        }
    }
}
void display(){
    if (front==-1){
        printf("Queue is empty!!\n");
    }
    else{
        printf("Elements in the queue are\n");
        int i=front;
        while(1){
            printf("%d\t",queue[i]);
            if(i==rear){
                break;
            }
            i=(i+1)%N;
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
