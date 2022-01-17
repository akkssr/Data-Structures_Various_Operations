

// 	OPerations of array using DMA by siraj

#include <stdio.h>
#include<stdlib.h>


#define X int 										 //if integer array
#define Y "%d"

/* Functions  - void insert_array(), void delete_array(), void display()        */


void insert_array(int *arr,int *no_of_array_elements){

	int pos,tmp_val;
    printf("\nPosition of insert\n");
    scanf("%d",&pos);

    if(pos<=0){         printf("\nInvalid Position\n");     return;     }

    if((pos-*no_of_array_elements)!=1 && pos>*no_of_array_elements){    printf("\nOut of range\n");   return;   }

    arr=(X *)realloc(arr,sizeof(X));         		 //realloc the array

    printf("\nEnter the value\n");
    scanf(Y,&tmp_val);

    if((pos-*no_of_array_elements)==1){							//if pos is last then no need to do extra works (upcoming lines)
        arr[*no_of_array_elements]=tmp_val;
         *no_of_array_elements+=1;
        return;
    }

    X *tmp_array=(X *)malloc((*no_of_array_elements-pos)*sizeof(X));   //creating temporary array

    if(tmp_array==NULL){   printf("\nerror allocation of temporary array"); exit(-1);   }


    pos-=1;  										//converting position into normal array no_of_array_elements


    for(int i=pos,j=0;i<*no_of_array_elements;i++,j++){
        tmp_array[j]=arr[i];              			//storing the values in temp array upto the position
    }

    arr[pos]=tmp_val;								//storing the value at the mentioned position

    for(int i=pos+1,j=0;i<=*no_of_array_elements;i++,j++){
        arr[i]=tmp_array[j];						//restoring the array from the temp array
    }

    *no_of_array_elements+=1;										//increment 1 no_of_array_elements of the array

    free(tmp_array);								//free the temp array
    tmp_array=NULL;
}


void delete_array(int *arr,int *no_of_array_elements){

    int pos;

    if(*no_of_array_elements==0){       printf("\nArray is empty\n");   return ;    }

    printf("\nPosition to delete\n");
    scanf("%d",&pos);

    if(pos<=0){         printf("\nInvalid Position\n");     return;     }

    if(pos>*no_of_array_elements){    printf("Out of range\n");  return;   }


    X *tmp_array=(X *)malloc((*no_of_array_elements-pos)*sizeof(X));    //temporary array for storing the array

    if(tmp_array==NULL){   printf("\nerror allocation of temporary array"); exit(-1);   }


    for(int i=pos,j=0;i<*no_of_array_elements;i++,j++){
        tmp_array[j]=arr[i];              		  //storing the remaining values in temp array
    }


    for(int i=pos-1,j=0;i<=*no_of_array_elements;i++,j++){
        arr[i]=tmp_array[j];					 //overwriting the array
    }

    free(tmp_array);
    tmp_array=NULL;

    *no_of_array_elements-=1;									//decrement 1 no_of_array_elements of the array
}

void display(int *arr,int no_of_array_elements){

    if(no_of_array_elements==0){       printf("\nArray is empty\n");   return ;    }

    for(int i=0;i<no_of_array_elements;i++){
        printf("%d\t",arr[i]);
    }
}


void main(){

          int no_of_array_elements=0,choice;

start:    printf("Enter the No. of arrays elements\n");
          scanf("%d",&no_of_array_elements);

          if(no_of_array_elements<=0){         printf("\nInvalid Number.. Try again...! (must be >0)\n\n");     goto start;     }

          X *arr=(X *)malloc(no_of_array_elements*sizeof(X));

          if(arr==NULL){    exit(-1);    }

          printf("\nEnter the elements\n");

          for(int i=0;i<no_of_array_elements;i++){
            scanf(Y,&arr[i]);
          }
          while(1){
                printf("\n1.Insertion  2. Deletion  3.Display  4.exit\t");
                scanf("%d",&choice);
                switch(choice){
                    case 1: insert_array(arr,&no_of_array_elements);  break;
                    case 2: delete_array(arr,&no_of_array_elements);  break;
                    case 3: display(arr,no_of_array_elements);  break;
                    default: free(arr);
                             arr=NULL;
                             exit(1);
                }
        }
}

