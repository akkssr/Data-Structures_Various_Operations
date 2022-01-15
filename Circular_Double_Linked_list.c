

// Circular_Double_Linked_List by siraj

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


int get_data(){
    int data;
    printf("Enter the data ");
    scanf("%d",&data);
    return data;
}

void insert_begin(){
    node *temp,*ptr=head;
    
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("\nError\n");        exit(-1);   }
    
    temp->data=get_data();
    
    if(head==NULL){
        temp->next=temp;
        temp->prev=temp;
        head=temp;
    }
    else{
        if(ptr->next==head){
            ptr->prev=temp;
            ptr->next=temp;
            
            temp->next=ptr;
            temp->prev=ptr;
            
            head=temp;
        }
        else{
            while(ptr->next!=head){     ptr=ptr->next;  }       //ptr moves to last node
        
            temp->next=head;
            temp->prev=ptr;
        
            ptr->next=temp;
            head->prev=temp;
        
            head=temp;                                          //head pointer moves to begin(temp)
        }
    }
}

void insert_end(){
    node *temp,*ptr=head;
    
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Error\n");      exit(-1);       }
    
    temp->data=get_data();
    
    if(head==NULL){
        temp->next=temp;
        temp->prev=temp;
        head=temp;
    }
    else{
        if(ptr->next==head){
            ptr->prev=temp;
            ptr->next=temp;
            
            temp->next=ptr;
            temp->prev=ptr;
        }
        else{
            while(ptr->next!=head){     ptr=ptr->next;  }       //ptr moves to last node
        
            ptr->next=temp;
            temp->prev=ptr;
        
            temp->next=head;
            head->prev=temp;
        }
    }
}

void insert_random(){                                           //first and last node can not insert (because of insert_end & insert_begin)
    int pos;
    node *temp,*ptr=head,*ptr_before=head;
    
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Error\n");      exit(-1);       }
    
    temp->data=get_data();
    
    printf("Enter the position ");
    scanf("%d",&pos);
    
    if(pos<=0){     printf("\nInvalid Position\n"); return ;    }           
    
    if(head==NULL){
        if(pos>1){      printf("\nInvalid Position\n");     return ;    }
        temp->prev=temp->next=temp;
        head=temp;
    }
    else{
        if(pos==1 || (ptr->next==head && pos==2)){
            printf("\nInvalid Position\n");
        }
        else{
            ptr=ptr->next;
            for(int i=1;i<pos-1;i++){
                
                if(ptr->next==head){        printf("\nInvalid Position\n");     return ;        }       
                
                ptr_before=ptr_before->next;
                ptr=ptr->next;
            }
            
            ptr_before->next=temp;
            temp->prev=ptr_before;
            
            temp->next=ptr;
            ptr->prev=temp;
        }
    }
}

void delete_begin(){
    node *ptr=head;
    
    if(head==NULL){
        printf("\nCir_DLL is empty\n");
    }
    else{
        if(ptr->next==head){                                //for only one node
            ptr->next=ptr->prev=NULL;
            head=NULL;
        }
        else{                                               //more than one node
            ptr=ptr->next;
            
            ptr->prev=head->prev;
            head->prev->next=ptr;
            
            head->prev=head->next=NULL;                     //deleted node assigned to 'NULL'
            head=NULL;
            
            head=ptr;
        }
    }
}

void delete_end(){
    node *ptr=head;
    
    if(head==NULL){
        printf("\nCir_DLL is empty\n");
    }
    else{
        if(ptr->next==head){                                //if only one node
            ptr->next=ptr->prev=NULL;
            head=NULL;
        }
        else{                                               //more than one node
        
            while(ptr->next->next!=head){   ptr=ptr->next;  }   //moving ptr to before last node
            
            ptr->next->next=ptr->next->prev=NULL;
            ptr->next=NULL;
            
            ptr->next=head;
            head->prev=ptr;
        }
    }
}

void delete_random(){                                       //first and last node can not delete (because of delete_begin & delete_end)
    int pos;
    node *ptr=head,*ptr_before=head;
    
    if(head==NULL){     printf("\nCir_DLL is empty\n");     return ;    }
    
    printf("\nEnter the Position ");
    scanf("%d",&pos);
    
    if(pos<=0){     printf("\nInvalid Position\n"); return ;    }
    
    if(pos==1 || ((pos==1 || pos==2) && (ptr->next==head || ptr->next->next==head))){   //if only (1 or 2 nodes) this condition will execute
        printf("\nInvalid Position\n");
    }
    else{
        ptr=ptr->next;
        for(int i=1;i<pos;i++){
            
            if(ptr->next==head){        printf("\nInvalid Position\n");     return ;    }
            
            ptr_before=ptr_before->next;
            ptr=ptr->next;
            
        }
        ptr_before=ptr_before->prev;                                // making node order like this(ptr_before <--> deletable-node <--> ptr)
        
        ptr_before->next->next=ptr_before->next->prev=NULL;
        
        ptr->prev=ptr_before;
        ptr_before->next=ptr;

    }
}

void search(){                                                  //it will saerch duplicate copy also and tell all the locations
    int element,count=1,flag=0;
    node *ptr=head;
    
    if(head==NULL){     printf("\nCir_DLL is empty\n");         return ;    }
    
    printf("\nEnter the element ");
    scanf("%d",&element);
    
    if(head==ptr->next && ptr->data==element){                  //if only one node 
        printf("\nElement found at location is %d\n",count);
    }
    else{                                                       //more than one node
        if(ptr==head && ptr->data==element){                    //for 1st node to search
            flag=1;
            printf("\nElement found at location is %d\n",count);
        }
        ptr=ptr->next;                                          //from the 2nd node (because already 1st node seraching done)
        while(ptr!=head){
            if(ptr->data==element){
                count++;
                printf("\nElement found at location is %d\n",count);
                flag=1;
            }
            else{
                count++;
            }
            ptr=ptr->next;
        }
    if(flag==0){        printf("\nElement not found\n");    }
    }
}

void display(){
    node *ptr=head;
    
    if(head==NULL){     printf("\nCir_DLL is empty\n");     return ;    }
    
    if(ptr==head){
        printf("%d\t",ptr->data);
    }
    ptr=ptr->next;
    while(ptr!=head){
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

