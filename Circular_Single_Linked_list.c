
// Circular_Single_Linked_List by siraj

#include <stdio.h>
#include <stdlib.h>

/* Functions - int get_data(),
                void insert_begin(),void insert_end(),void insert_random(),
                void delete_begin(),void delete_end(),void delete_random(),
                void search(), void display()                                   */
                
typedef struct node{
    int data;
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
    
    if(head==NULL){                                     //if no data present
        temp->next=temp;
        head=temp;
        return ;
    }
    if(ptr->next==head){                                //if only one node present
        ptr->next=temp;
        temp->next=ptr;
        head=temp;
    }
    else{                                               //if more than one node
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=head;
        head=temp;
    }
}


void insert_end(){
    node *temp,*ptr=head;
    
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Error\n");      exit(-1);   }
    
    temp->data=get_data();
    
    if(head==NULL){                                 //if no data is present
        temp->next=temp;
        head=temp;
    }
    else{                                           //if atleast one node is present
        while(1){
            if(ptr->next==head){
                ptr->next=temp;
                temp->next=head;
                return ;
            }
            ptr=ptr->next;
        }
    }
}

void insert_random(){                              												 //first node and last node can not insert,but if node is empty and position got as 1 it will insert
    int pos;
    node *temp,*ptr=head;
    
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Error\n");  exit(-1);   }
    
    temp->data=get_data();
    
    printf("Enter the position ");
    scanf("%d",&pos);
   
    if(pos<=0){     printf("\nInvalid Position\n"); return ;    }
	
    if(head==NULL){  
        if(pos>1){      printf("Cir_SLL is empty\n");   return ;    }
        temp->next=temp;                                               							 //if node is empty
        head=temp;
    }
    else{
        if(pos==1){                                     						                //if position is 1
            printf("\nInvalid Position\n");      
        }
        else{																					// if position is more than one
            for(int i=1;i<pos-1;i++){
                if(ptr->next==head){      printf("\nInvalid Position\n");     return;     }
                ptr=ptr->next;
            }
            if(ptr->next==head){      printf("\nInvalid Position\n");     return;     }
            temp->next=ptr->next;
            ptr->next=temp;
        }
    }
}

void delete_begin(){
    node *ptr=head;
    
    if(head==NULL){     printf("Cir_SLL is empty\n");   return ;    }
    
    if(head==ptr->next){                            //if only one node
        head=NULL;
    }
    else{
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        
        head=head->next;                            //this squence is must
            
        ptr->next->next=NULL;
        
        ptr->next=head;
    }
}

void delete_end(){
    node *ptr=head;
    
    if(head==NULL){     printf("Cir_SLL is empty\n");       return ;    }
    
    if(ptr->next==head){                            //if only one node
        head=NULL;
    }
    else{
        while(ptr->next->next!=head){
            ptr=ptr->next;
        }
        ptr->next->next=NULL;
        ptr->next=head;
    }
}

void delete_random(){                                     					 //first and last node can not delete,but if only one node is present it will delete
    int pos;
    node *ptr=head,*ptr_before=head;										 // ptr_before (deletable node) & ptr (node before deletable node)
    
    if(head==NULL){     printf("Cir_SLL is empty\n");       return ;    }
    
    printf("Enter the Position ");
    scanf("%d",&pos);
    
    if(pos<=0){     printf("\nInvalid Position\n"); return ;    }
    
    if(ptr->next==head){                                                     //when only 1 node available, this condition will execute
        if(pos>1){      printf("\nInvalid Position\n");   return ;    }
        head->next=NULL;
        head=NULL;
    }
    else{
		ptr=ptr->next;
        if((pos==1 || pos==2) && ptr_before==ptr->next){                     //when only 2 nodes available, this condition will execute    
               printf("\nInvalid Position\n");
        }
        else{                                         						 //more than 2 nodes available, this condition will execute    
			for(int i=1;i<pos;i++){
                
                if(ptr->next==head){        printf("\nInvalid Position\n");   return ;    }
                
                ptr_before=ptr_before->next;
                
                ptr=ptr->next;   
            }     
			
            while(ptr->next!=ptr_before){     ptr=ptr->next;  }				 //moving 'ptr' to before 'ptr_before' node so that we can perform operations easily            
            
            ptr->next=ptr_before->next;
            
            ptr_before->next=NULL;
            
            if(head->next==NULL){                           				 // because if 1st node deleted, head node wont be there so we should assign
                head=ptr->next;             
            }
        }
    }
}
    
void search(){
	int element,flag=0,count=1;
	node *ptr=head;
	
	printf("Enter the element ");
	scanf("%d",&element);
	
	if(head==NULL){
		printf("Cir_SLL is empty\n");
		return ;
	}
	
	if(ptr->next==head){												//only one node to search,this is the logic
		if(ptr->data==element){
			printf("Element found at location is %d\n",count);	
			flag=1;
		}
	}
	else{
		while(ptr->next!=head){										//more than one node to search,this is the logic			
			count++;
			if(ptr->data==element){
				printf("Element found at location is %d\n",count);
				flag=1;
			}
			ptr=ptr->next;
		}
	}
	if(flag==0){	printf("Element not found\n");	}
}
    
void display(){
    node *ptr=head;
    if(head==NULL){
        printf("Cir_SLL is empty\n");   return;
    }
    while(1){
        printf("%d\t",ptr->data);
        if(ptr->next==head){  return ;    }
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

