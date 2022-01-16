
// Stack Operations Using Arrays by siraj


#include <stdio.h>
#include <stdlib.h>

int top=-1;

void push(int *arrays){
    
    int temp;
    
    arrays=(int *)realloc(arrays,sizeof(int));
    if(arrays==NULL){       printf("\nError\n");        exit(-1);   }
    
    printf("\nEnter the Element - ");
    scanf("%d",&temp);
    
    arrays[++top]=temp;
}

void pop(){
    
    if(top==-1){        printf("\nStack is empty\n");   return;     }
    
    top--;
    
}

void display(int *arrays){
    
    if(top==-1){        printf("\nStack is empty\n");   return ;    }
    
    for(int i=top;i>=0;i--){                                    // Last in First Out
        printf("%d\t",arrays[i]);
    }
}

void main()
{
        int N,choice;

start:  printf("Enter the Number of Element - ");
        scanf("%d",&N);
        if(N<1){    printf("\nInvalid Number\n");       goto start;     }
    
        int *arrays=(int *)malloc(sizeof(int)*N);
        if(arrays==NULL){       printf("\nError\n");        exit(-1);   }
        
        printf("\nEnter the %d Elements\n",N);
        for(int i=0;i<N;i++){                           //last Element is the top of the stack
            scanf("%d",&arrays[i]);
            top++;
        }
        while(1){        
            printf("\n1. Push\t2. Pop\t3. Display\t4. Exit -");
            scanf("%d",&choice);
        
            switch(choice){
                case 1: push(arrays);         break;
                case 2: pop();                break;
                case 3: display(arrays);      break;
                default: free(arrays);
                         arrays=NULL;
                         exit(1);
            }
        }
}

