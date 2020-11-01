#include<iostream>

using namespace std;

class friendfunc1{
public:
    int num1 , num2;

friendfunc1(int a,int b){
    this->num1 = a;
    this->num2 = b;

}
friendfunc1(){
    this->num1 = 0;
    this->num2 = 0;

}

};


class friendfunc2{
public:
  int num1,num2,num3;
friendfunc2(int a,int b,int c){
    this->num1 = a;
    this->num2 = b;
    this->num3 = c;
}

friendfunc2(){
    this->num1 = 0;
    this->num2 = 0;
    this->num3 = 0;
}

};

int Friend(friendfunc1* obj1,friendfunc2* obj2){
  
    int avg = 0;
    avg+= obj1->num1;
    avg+=obj1->num2;
    avg+=obj2->num1;
    avg+=obj2->num2;
    avg+=obj2->num3;
   
   return avg/5;
}

int main(){

    friendfunc1* obj1 = new friendfunc1();

    friendfunc2* obj2 = new friendfunc2();


//taking input values in object of class 1 
    cout<<endl<<"Enter 2 numbers for object of class 1 : ";
    cin>>obj1->num1;
    cin>>obj1->num2;
//taking input values in object of class 2
    cout<<"Enter 3 numbers for object of class 2 : ";
    cin>>obj2->num1;
    cin>>obj2->num2;
    cin>>obj2->num3;

    cout<<endl<<"Avg of 5 numbers is "<<Friend(obj1,obj2)<<endl;

    return 0;
}