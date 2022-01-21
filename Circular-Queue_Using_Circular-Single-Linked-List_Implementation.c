// Circular Queue using Circular-Single-Linked-List by siraj

/* Functions - void enqueue(), void dequeue(),
               void display()                   */
               

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

void enqueue(){
    
    int temp_data;
    
    node *temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Memory Not allocated\n");   return;   }
    
    printf("\nEnter the element - ");
    scanf("%d",&temp_data);
    
    temp->data=temp_data;
    
    if(front==NULL && rear==NULL){                          //if Queue is empty
        temp->next=temp;
        front=temp;
        rear=temp;
    }
    else{                                                   //insert only rear end
        temp->next=rear;
        front->next=temp;
        rear=temp;
    }
}

void dequeue(){
    
    node *ptr=rear;
    
    if(ptr==NULL){      printf("\nQueue is empty\n");       return;     }       //if Queue is empty
    
    while(ptr->next!=front){    ptr=ptr->next;  }                                //moving ptr to before front node
    
    if(ptr->next==rear){                                                        //if Queue has only one node
        front=NULL;
        rear=NULL;
    }
    else{                                                                       //Queue has more than one node
        free(front);
        ptr->next=rear;
        front=ptr;
    }
}

void display(){
    
    node *ptr=rear;
    
    if(ptr==NULL){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\nRear-->  ");
        while(1){                                                     
            printf("%d  ",ptr->data);				//this is the sequence because its circular-Linked-List
            ptr=ptr->next;
            if(ptr==rear){         break;         } 
        }
        printf("-->front\n");
    }
}

void main()
{
    int choice;
    while(1){
        printf("\n1.Enqueue\t2. Dequeue\t3. Display\t4. Exit -");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:  enqueue();       break;
            case 2:  dequeue();       break;
            case 3:  display();       break;
            default: free(front);   free(rear);
                     front=NULL;    rear=NULL;
                     exit(1);
        }
    }
}
