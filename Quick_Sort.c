
//QuickSort by siraj

// Appx Time Consuming is 5-9 ms

#include <stdio.h>
#include <time.h>

int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; // pivot element  
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  
/* function to implement quick sort */  
void quick(int a[], int start, int end) /* a[] = array to be sorted, start = Starting index, end = Ending index */  
{  
    if (start < end)  
    {  
        int p = partition(a, start, end); //p is the partitioning index  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  

void main(){
    
     int a[]={10,8,6,2,656,1,65,36,43,646461,16,41,6,4,13,3,54,61,543,16464,646,46,12,1,11,65,16,3,16,6323,3131,165,36143,164131,16232,156413,31641,19466,
     13,531515,64654,1656154,65465165,615654,654654,656164,6465464,1654564,64651654,651561654,16549846,564646,64651646,16164616,61655465,615616,6165946,645646,
     4651,6161,16451,6164,65461215,1216145,615461,616132,161515,-164,-48,-1,-1,1564};
    
	int n=sizeof(a)/sizeof(int);
    
    clock_t begin=clock();
    
    quick(a, 0, n - 1);  
    
    clock_t end=clock();
    
    printf("\n\nAfter sort the element\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    printf("\nTime Consuming is %f ms",(((double)(end-begin)*1000000)/CLOCKS_PER_SEC));

}



