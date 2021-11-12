#include <stdio.h> 
  
int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        
        if (arr[m] == x) 
            return m; 
  
         
        if (arr[m] < x) 
            l = m + 1; 
  
        
        else
            r = m - 1; 
    } 
  
    
    return -1; 
} 
  
int main() 
{ 
    int arr[] = { 2, 3, 4, 10, 40, 77, 82 , 94 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 77; 
    int result = binarySearch(arr, 0, n - 1, x); 
    
    if(binarySearch(arr, 0, n - 1, x)==-1)
	printf("Item not found");
	else
	printf("\nItem found at %d th position",binarySearch(arr, 0, n - 1, x)+1);
	return 0;
     
}
