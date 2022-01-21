
// DeQueue using Circular-Single-Linked-List by siraj

/* Functions - void enqueue_front(), void enqueue_rear(), void dequeue_front(), void dequeue_rear(),
               void display()                   */
               

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

int get_data(){                                                                 //get the data from user
    int temp; 
    printf("\nEnter the element - ");
    scanf("%d",&temp);
    return temp;
}

void enqueue_front(){
    
    node *temp=(node *)malloc(sizeof(node));
    if(temp==NULL){         printf("\nMemory not Allocated\n");     return; }
    
    temp->data=get_data();
    
    if(front==NULL){
        temp->next=temp;
        front=temp;
        rear=temp;
    }
    else{
        temp->next=rear;
        front->next=temp;
        front=temp;                                                             // insertion shoud be front end
    }
}

void enqueue_rear(){
    
    node *temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("\nMemory not Allocated\n");     return;     }
    
    temp->data=get_data();
    
    if(rear==NULL){
        temp->next=temp;
        front=temp;
        rear=temp;
    }
    else{
        temp->next=rear;
        front->next=temp;
        rear=temp;                                                              // insertion should be rear end
    }
}

void dequeue_front(){
    
    node *ptr=rear;
    
    if(rear==NULL){        printf("\nQueue is empty\n");    return;      }
    
    if(ptr->next==rear){                                                        //if only one node
        rear=front=NULL;       
    }
    else{                                                                       //if more than one node
        while(ptr->next!=front){        ptr=ptr->next;      }
    
        free(front);
        ptr->next=rear;
        front=ptr;
    }
}

void dequeue_rear(){
    
    node *ptr=rear;
    
    if(rear==NULL){         printf("\nQueue is empty\n");   return;     }
    
    if(ptr->next==rear){                                                        //if only one node
        front=rear=NULL;
    }
    else{                                                                       //if more than one node
        rear=rear->next;
        front->next=rear;
        free(ptr);
        ptr=NULL;
    }
}

void display(){
    
    node *ptr=rear;
    
    if(rear==NULL){     printf("\nQueue is empty\n");       return; }
    printf("\nRear-->  ");
    while(1){
        printf("%d  ",ptr->data);                                               //this is the sequence for Circular-Single-Linked-List
        ptr=ptr->next;
        if(ptr==rear){      break;      }
    }
    printf("-->Front\n");
}

void main()
{
    int choice;
    while(1){
        printf("\n1. Enqueue_front\t2. Enqueue_rear\t3. Dequeue_front\t4. Dequeue_rear\t5. Display\t6. Exit -");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:  enqueue_front();       break;
            case 2:  enqueue_rear();        break;
            case 3:  dequeue_front();       break;
            case 4:  dequeue_rear();        break;
            case 5:  display();             break;
            default: free(front);   front=NULL;
                     free(rear);    rear=NULL;
                     exit(1);
        }
    }
}
