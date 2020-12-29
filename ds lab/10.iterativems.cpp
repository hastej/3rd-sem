#include<iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) 
{ 
      int i, j, k; 
    int count1 = m - l + 1; 
    int count2 = r - m; 

    int leftarray[count1], rightarray[count2]; 
  
    for (i = 0; i < count1; i++) 
        leftarray[i] = arr[l + i]; 
    for (j = 0; j < count2; j++) 
        rightarray[j] = arr[m + 1 + j]; 
  
    i = 0,j = 0,k = l;  
  
    while (i < count1 && j < count2) { 
        if (leftarray[i] <= rightarray[j]) { 
            arr[k] = leftarray[i]; 
            i++; 
        } 
        else { 
            arr[k] = rightarray[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < count1) { 
        arr[k] = leftarray[i]; 
        i++; 
        k++; 
    } 
  
    while (j < count2) { 
        arr[k] = rightarray[j]; 
        j++; 
        k++; 
    } 
} 
    
void mergeSort(int arr[], int n) 
{ 
   for (int i =1;i<=n-1; i = 2*i) 
   { 
       for (int j=0; j<n-1; j+= 2*i) 
       { 
           int mid = min(j + i - 1, n-1); 
           int k = min(j + 2*i - 1, n-1); 
  
           merge(arr, j, mid, k); 
       } 
   } 
} 
  
int main(){

    int size;
    cout<<"Enter size : ";
    cin>>size;

    int arr[size];
    
    cout<<"Enter elements : "<<endl;

    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
    
    mergeSort(arr,size);

    cout<<endl<<"Sorted array is : ";

    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    
    return 0;

}