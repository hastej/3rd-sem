#include<iostream>

using namespace std;

void insert(int arr[],int data,int idx,int size){
   
       for(int i = size+1;i>idx;i--){
           arr[i] = arr[i-1];
       } 

       arr[idx] = data;
      
}

void del(int arr[],int idx,int size){
    
       for(int i = idx;i<size;i++){
           arr[i] = arr[i+1];
       } 

       arr[size-1] = 0;
       
}

int main(){
   
   int arr[50];//assuming max size 50

   int size ;
   cin>>size;
   cout<<"Enter array"<<endl;

   for(int i = 0;i<size;i++){
       cin>>arr[i];
   }

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;


   int data,insertidx,deleteidx;
   cin>> data>>insertidx>>deleteidx;

   insert(arr,data,insertidx,size++);

   cout<<endl;

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;


    del(arr,deleteidx,size--);

    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    } 

    return 0; 
}