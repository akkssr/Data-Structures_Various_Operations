// Queue using Linked-List by siraj


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

void insert(){
    
    int temp_data;
    
    node *temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Memory Not allocated\n");   exit(-1);   }
    
    printf("\nEnter the element - ");
    scanf("%d",&temp_data);
    
    temp->data=temp_data;
    
    if(front==NULL && rear==NULL){                          //if Queue is empty
        temp->next=NULL;
        front=temp;
        rear=temp;
    }
    else{                                                   //insert only rear end
        temp->next=rear;
        rear=temp;
    }
}

void delete(){
    
    node *ptr=rear;
    
    if(ptr==NULL){      printf("\nQueue is empty\n");       return;     }       //if Queue is empty
    
    while(ptr->next!=front && ptr->next!=NULL){    ptr=ptr->next;  }            //moving ptr to before front node and if only one node ptr should not move
    
    if(ptr->next==NULL){                                                        //if Queue has only one node
        front=NULL;
        rear=NULL;
    }
    else{                                                                       //Queue has more than one node
        free(front);
        ptr->next=NULL;
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
        while(ptr!=NULL){
            printf("%d  ",ptr->data);
            ptr=ptr->next;
        }
        printf("-->front\n");
    }
}

void main()
{
    int choice;
    while(1){
        printf("\n1.Insert\t2. Delete\t3. Display\t4. Exit -");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: insert();       break;
            case 2: delete();       break;
            case 3: display();      break;
            default: free(front);   free(rear);
                     front=NULL;    rear=NULL;
                     exit(1);
        }
    }
}
