
//Binary Search by siraj

/*  Array should be Sorted otherwise this method can not use            */



#include <stdio.h>


int binary_search(int *a,int beg,int end,int val){
    
    int mid;
    if(end>=beg){
        mid=(beg+end)/2;
        
        if(a[mid]==val){
            return mid+1;
        }
        else if(a[mid]>val){
            return binary_search(a,beg,mid-1,val);
        }
        else{
            return binary_search(a,mid+1,end,val);
        }
    }
    return -1;
}

void main(){
    
    int a[]={11,22,33,44,55,56,57,58};                                          //should be sorted array
    int search,result,len=sizeof(a)/sizeof(int);
    
    while(1){    
        printf("\nEnter the Search Element - ");
        scanf("%d",&search);
    
        result=binary_search(a,0,len-1,search);
    
        (result==-1)? printf("\nElement %d not found\n",search): printf("\nElement %d found at location is %d\n",search,result);
        }
}
