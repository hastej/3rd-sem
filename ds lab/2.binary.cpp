#include<iostream>

using namespace std;

int main(){
    int size;
    cin>>size;

    int arr[size];

    for(int i =0;i<size;i++){
        cin>>arr[i];
    }

    int data;
    cin>>data;
  
  for(int i =0;i<size-1;i++){
       for(int j =0;j<size-1;j++){
            if(arr[j+1]<arr[j]){
            int swap  = arr[j+1];
             arr[j+1]=arr[j];
             arr[j] = swap;

            }
        }
    }

    int left =0,right = size -1;

   while(left<=right){
       int mid = (left + right)/2;
       if(arr[mid]==data){
           cout << "Element is found at " << mid <<endl;
           break;
       }
       else if(arr[mid]<data){
           left = mid+1;
       }
       else
       {
           right = mid-1;
       }
       
   }

   
    if(left>right) cout<<"Not found"<<endl;

    return 0;


}