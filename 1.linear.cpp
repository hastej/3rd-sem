#include<iostream>
#include<vector>

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
    
    bool find = false;

   for(int i =0;i<size;i++){
       if(arr[i]==data){
           cout<<"Element if found at idx "<<i<<endl;
           find = true;
           break;
       }
    }

    if(find==false){
        cout<<"Not found"<<endl;
    }
    return 0;


}