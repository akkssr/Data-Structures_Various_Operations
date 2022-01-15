
//Doubled Linked list by siraj

#include <stdio.h>
#include <stdlib.h>


/* Functions - int get_data(),
                void insert_begin(),void insert_end(),void insert_random(),
                void delete_begin(),void delete_end(),void delete_random(),
                void search(), void display()                                   */
				
				
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *head=NULL;


int get_data(){                                         //get the node from user
    int data;
    printf("Enter the data ");
    scanf("%d",&data);
    return data;
}

void insert_begin(){
    
    node *temp,*ptr=head;
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Error\n");  exit(-1);   }
    
    temp->data=get_data();
    
    if(head==NULL){                                     //if no node is there
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    else{
        temp->prev=NULL;
        temp->next=ptr;
        ptr->prev=temp;
        head=temp;
    }
}

void insert_end(){
    node *temp,*ptr=head;
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Error\n");  exit(-1);   }
    
    temp->data=get_data();
    
    if(head==NULL){                                 //if no node is there
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    else{
        while(ptr->next!=NULL){                     //pointer moves to last node
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
        temp->next=NULL;
    }
}

void insert_random(){
    int pos;
    node *temp,*ptr=head;
    
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Error\n");                exit(-1);   }
    
    temp->data=get_data();
    
    printf("Enter the pos ");
    scanf("%d",&pos);
	
    if(pos<=0){     printf("\nInvalid Position\n"); return ;    }	
    
    if(head==NULL){                                                     //if no node is there but gave Position as 1, insert the node at beginning 
        if(pos>1){      printf("\nPosition Invalid\n");   return ;    }
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    else{           
        if(pos==1){                                                     //if got Position as 1, this is enough
            printf("\nPosition Invalid\n");
        }
        else{
            for(int i=1;i<pos-1;i++){                                   //pointer moves to pointer which one is before position node
                ptr=ptr->next;
                if(ptr->next==NULL){         printf("\nPosition Invalid\n");   return ;    }
            }
            temp->next=ptr->next;
            ptr->next->prev=temp;
            ptr->next=temp;
            temp->prev=ptr;
        }
    }
}

void delete_begin(){
    node *ptr=head;
    
    if(head==NULL){
        printf("DLL is empty\n");   return ;
    }
    if(ptr->next==NULL){                                //if only one node is available
        head=NULL;
    }
    else{
        ptr=ptr->next;
        ptr->prev=NULL;
        head=ptr;
    }
}

void delete_end(){
    node *ptr=head;
    
    if(head==NULL){
        printf("DLL is empty\n");    return ;
    }
    if(ptr->next==NULL){                                //if only one node is available
        head=NULL;
    }
    else{
        while(ptr->next!=NULL){                         //pointer moves to last node
            ptr=ptr->next;
        }
        
        ptr=ptr->prev;                                  //pointer should be before last node
       
        ptr->next->prev=NULL;
        ptr->next=NULL;
    }
}

void delete_random(){                               //first node we can perform but not last one (Invalid Position)
    int pos;
    node *ptr=head,*ptr_temp;
    printf("Enter the Position ");
    scanf("%d",&pos);
	
    if(pos<=0){     printf("\nInvalid Position\n"); return ;    }
    
    if(head==NULL){
        printf("DLL is empty\n"); 
    }
    else{    
        if(pos==1 || ((ptr->next==NULL || ptr->next->next==NULL) && (pos==1 || pos==2))){       //if position 1 or only ( 1 node or 2 node ) this condition will execute
            printf("\nPosition Invalid\n");
        }    
        else{
            for(int i=1;i<pos-1;i++){
                ptr=ptr->next;
                if(ptr->next->next==NULL){    printf("\nInvalid Position\n"); return ;    }
            }
            if(ptr->next->next==NULL){    printf("\nInvalid Position\n"); return ;    }
            ptr_temp=ptr->next->next;                                                           // this sequence is must otherwise we lost node
            ptr->next->prev=NULL;
            ptr->next->next=NULL;
            ptr->next=ptr_temp;
            ptr_temp->prev=ptr; 
        }
    }
}

void search(){
    int element,flag=0,count=1;
    node *ptr=head;
    printf("\nEnter the element ");
    scanf("%d",&element);
    
    if(head==NULL){ printf("\nDLL is empty\n"); return ;    }
    
    while(ptr!=NULL){                                                   //check upto last node
        if(element==ptr->data){
            printf("\nElement Found at location is %d\n",count);
            flag=1;
        }
        ptr=ptr->next;
        count++;
    }
    if(flag==0){    printf("\nElement not Found\n");    }
}

void display(){
    node *ptr=head;
    
    if(head==NULL){     printf("\nDLL is empty\n"); return; }
    
    while(ptr!=NULL){                                               //check upto last node
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

void main(){
    int choice;
    while(1){
        printf("\n1.Insert_begin\t2.Insert_end\t3.Insert_random\t4.Delete_begin\t5.Delete_end\t6.Delete_random\t7.Search\t8.Display\t9.Exit \n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1 :    insert_begin();     break;
            case 2 :    insert_end();       break;
            case 3 :    insert_random();    break;
            case 4 :    delete_begin();     break;
            case 5 :    delete_end();       break;
            case 6 :    delete_random();    break;
            case 7 :    search();           break;  
            case 8 :    display();          break;
            default:    exit(1);
        }
    }
}

