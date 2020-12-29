#include<iostream>

using namespace std;

bool isdiff(int arr[],int n,int S){
    int fast = 1;
    int slow = 0;

    while(fast <n && slow<n){
        
        if(arr[fast]-arr[slow]==S){
            return true;
        }
        else if(arr[fast]-arr[slow]>S){
            slow++;
        }
        else 
        {
            fast++;
        }
    }

    return false;


    return false;
}

int main(){

    int n=5,S = 5;
    
    int arr[] = {0,4,5,7,10};

    
    cout<<isdiff(arr,n,S);
    
    return 0;
}