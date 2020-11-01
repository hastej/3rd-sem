#include<iostream>

using namespace std;


void swap_value(int a,int b){
    int temp = a;
    a=b;
    b=temp;

    cout<<"After swapping : "<<endl<<"Number 1 is "<<a<<endl<<"Number 2 is "<<b<<endl;
}

void swap_refrence(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}

int main(){

    int num1,num2;
    cout<<"Enter the two numbers : "<<endl;
    cin>>num1 >>num2;
    cout<<endl;

    cout<<"ENTER YOUR CHOICE : "<<endl<<"1. Swap by value"<<endl<<"2. Swap by reference "<<endl;
    int n;
    cin>>n;

    switch (n)
    {
    case 1:
    swap_value(num1,num2);
        break;

    case 2:swap_refrence(num1,num2);
    cout<<"After swapping : "<<endl<<"Number 1 is "<<num1<<endl<<"Number 2 is "<<num2<<endl;
        break;

    default:
        break;
    }

    return 0;
}

