#include<iostream>

using namespace std;

class Node{

    public:

    int val;
    Node* next = nullptr;

    Node(int data){
        this->val = data;
    }
};

class stack{

    public:

    int size = 0;
    int top = -1;
    Node* head;
    Node* tail;

    stack(int data){
        this->head = new Node(data);
        tail = head;
        size++;
    }

    void push(int data){

        if(size==0){
            Node* ele = new Node(data);
            head = ele;
            tail = ele;
            size++;
            return;
            
        }

        Node* ele = new Node(data);
        tail->next = ele;
        tail = ele;
        size++;
    }

    void pop(){

        
        if(size==1){
            
            head = nullptr;
            tail = nullptr;
            size--;
            return;
            
        }

        Node* ele = head;

        for(int i =1;i<size-1;i++){
            ele = ele->next;
        }

        ele->next = nullptr;
        tail = ele;
        size--;
    
    }

    int topofstack(){

        return tail->val;

    }

    void display(){
        cout<<endl;

        
         Node* ele = head;

         for(int i =0;i<size-1;i++){
            cout<<ele->val<<" -> ";
            ele = ele->next;
        }

        if(size!=0)cout<<tail->val<<endl;

    }

};

int main(){
    
    int data;

    cout<<"Enter first element of stack : ";

    cin>>data; 

    stack* st = new stack(data);
    
    int i = 1;

    while(i!=5){
        cout<<"Click the numbers for : "<<endl<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Peek"<<endl<<"4. Display"<<endl<<"5. Exit"<<endl;
        
        cin>>i;
        
        if(i==1){
            int data;
            cout<<"Input data : ";
            cin>>data;
            st->push(data);
        }
        if(i==2){
         st->pop();
         }
        if(i==3){
            cout<<endl<<"Top of stack is : ";
            cout<<st->topofstack()<<endl;
        }
        if(i==4)
        st->display();
        if(i==5)
        break;

    }
 
    return 0;

}