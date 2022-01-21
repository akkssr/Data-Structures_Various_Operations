
// Stack Operations Using Linked-List by siraj

/* Functions - void push(), void pop(),
               void display()                       */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL;


void push(){
    
    node *temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Memory not Allocated\n");	return;   }
    
    printf("\nEnter the Element - ");
    scanf("%d",&temp->data);
    
    if(head==NULL){
        temp->next=NULL;
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}

void pop(){
    
    node *temp=head;
    
    if(head==NULL){
        printf("\nstack is empty\n");
    }
    else{
        head=head->next;
        free(temp);
    }
}

void display(){
    
    node *temp=head;
    
    if(head==NULL){     printf("\nstack is empty\n");   return;     }
    
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void main()
{
        int choice;
        while(1){        
            printf("\n1. Push\t2. Pop\t3. Display\t4. Exit -");
            scanf("%d",&choice);
        
            switch(choice){
                case 1:  push();         break;
                case 2:  pop();          break;
                case 3:  display();      break;
                default: free(head);    head=NULL;
                         exit(1);
            }
        }
}

