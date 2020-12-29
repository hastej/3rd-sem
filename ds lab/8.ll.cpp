#include<iostream>

using namespace std;

class Node{
    public:
    
    int val = 0;
    Node* next = nullptr;

    Node(int data){
        this->val = data;
    }
};

Node* insert(int data,int idx,Node* head){

    if(head==nullptr)
    {
        Node* ele = new Node(data);
        return ele;     
    }
    
    if(head->next==nullptr)
    {
        Node* ele = new Node(data);
        head->next = ele;
        ele->next = head;

        if(idx==0) return ele;        
    }
    
    else{

        Node* p = head;
        Node* ele = new Node(data);

        if(idx == 0){
             
            while(p->next!=head){
                p = p->next;
            }
 
            ele->next = p->next;
            p->next = ele;
        
            return ele;
        }

       for(int i=0;i<idx-1;i++){
            p = p->next;
        }
        
        ele->next = p->next;
        p->next = ele;

    }

    return head;

}

Node* del(int idx,Node* head){

    if(head==nullptr){
        cout<<"Empty "<<endl;
        return nullptr;
    }
    
    if(head->next==nullptr)
    {
        return nullptr;       
    }
    else{

        Node* p = head;

        if(idx == 0){
             
            while(p->next!=head){
                p = p->next;
            }
 
            Node* dele = p->next;
            p->next = dele->next;
            dele->next = nullptr;

            return p->next;
        }

       for(int i=0;i<idx-1;i++){
            p = p->next;
        }
        
        Node* dele = p->next;
        p->next = dele->next;
        dele->next = nullptr;

        return head;

    }

}

void display(Node* head){
    
    if(head==nullptr) {
        cout<<"Empty list";
        return;
    }
    
    Node* i = head;
    
    while(i->next!=head){
        cout<<i->val<<" -> ";
        i = i->next;
    }

    cout<<i->val<<endl;
}

int main(){ 

    cout<<"Enter first element : ";

    int data;
    cin>>data;

    Node* head = new Node(data);
    
    int i = 1;

    while(i!=4){
        cout<<"Click the numbers for : "<<endl<<"1. Insert"<<endl<<"2. Delete"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl;
        cin>>i;
        if(i==1){
            int data,idx;
            cout<<"Input data and index : ";
            cin>>data>>idx;
            head = insert(data,idx,head);
        }
        if(i==2){
            int idx;
            cout<<"Input index : ";
            cin>>idx;
            head = del(idx,head);
        }
        if(i==3){
            cout<<endl<<"Circular list is : ";
            display(head);
            cout<<endl;
        }
        if(i==4)break;

    }
    
    return 0;
}