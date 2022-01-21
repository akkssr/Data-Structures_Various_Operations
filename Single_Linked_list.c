
// Single_Linked_List by siraj

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


int get_data(){															// function for get the data
    int data;
    printf("Enter the data ");
    scanf("%d",&data);
    return data;
}

void insert_begin(){
    node *temp;
    temp=(node *)malloc(sizeof(node));
    
    if(temp==NULL){     printf("Memory not Allocated\n");	return;   }
    
    temp->data=get_data();
    
    temp->next=head;
    
    head=temp;
}

void insert_end(){
    node *temp,*ptr;
    temp=(node *)malloc(sizeof(node));
    
    if(temp==NULL){     printf("Memory not Allocated\n");	return;   }
    
    temp->data=get_data();
    
    if(head==NULL){
        temp->next=head;
        head=temp;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
}

void insert_random(){
    int pos;
    node *temp,*ptr=head,*ptr_before=head;
    
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){     printf("Memory not Allocated\n");	return;   }
    
    temp->data=get_data();
    
    printf("\nEnter the pos ");
    scanf("%d",&pos);

    if(pos<=0){     printf("\nInvalid Position\n"); return ;    }	
	
	if(head==NULL){
		temp->next=NULL;
		head=temp;
	}
	else{
		
		if(pos==1){											//we should not insert 1st node (because already insert_begin is there)
			printf("\nPosition Invalid\n");
		}
		else{
			ptr=ptr->next;
			for(int i=1;i<pos-1;i++){
            
				if(ptr==NULL){ 	printf("\nPosition Invalid\n");   return ;  }
            
				ptr=ptr->next;
				ptr_before=ptr_before->next;
			}
			ptr_before->next=temp;
		}	temp->next=ptr;       
    }
}

void delete_begin(){
    node *ptr=head;
    
    if(head==NULL){ printf("LL is empty\n");    return ;    }
    
    head=ptr->next;
}

void delete_end(){
    node *ptr=head,*ptr_before;
    
    if(head==NULL){ printf("LL is empty\n");    return ;    }
    
    while(ptr->next!=NULL){
        ptr_before=ptr;
        ptr=ptr->next;
    }
    ptr_before->next=NULL;
}

void delete_random(){																//first and last node can not delete, inbetween nodes only can delete
    int pos;
    node *ptr=head,*ptr_before=head;
    
    if(head==NULL){ printf("LL is empty\n");    return ;    }
    
    printf("\nEnter the pos ");
    scanf("%d",&pos);
    
    if(pos<=0){     printf("\nInvalid Position\n"); return ;    }
    
    if( pos==1){ 																	//if position as 1, this condition should execute (because already we have delete_begin)
        printf("\nPosition Invalid\n");
    }
    else{
		ptr=ptr->next;
        for(int i=1;i<pos-1;i++){
        
            ptr_before=ptr;
        
            ptr=ptr->next;
			
			if(ptr==NULL){          printf("\nPosition Invalid\n");  return ;      }
        }
    
        ptr_before->next=ptr->next;
    }
}

void search(){
    int element,count=1,flag=0;
    node *ptr=head;
    
    if(head==NULL){      printf("LL is empty\n");    return ;     }
    
    printf("\nEnter the element to search ");
    scanf("%d",&element);
    
    while(ptr!=NULL){
        if(ptr->data==element){
            printf("\nElement found at location is %d\n",count);
            flag=1;
        }
        ptr=ptr->next;
        count++;
    }
    if(flag==0){    printf("\nElement not found\n");    }
}

void display(){
    node *temp=head;
    if(head==NULL){ printf("\nLL is empty\n");  }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
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
            default:    free(head);	head=NULL;
			exit(1);
        }
    }
}

