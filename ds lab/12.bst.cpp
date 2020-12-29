#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left=nullptr;
    Node* right=nullptr;

    Node(int data){
        this->data=data;
    }
};

void display(Node* node){
    if(node==nullptr) return;

    display(node->left);

    cout<<node->data<<"->";

    display(node->right);
}

bool search(Node* node, int data){
    
    Node* curr=node;
    while (curr!=nullptr)
    {
        if(curr->data==data) return true;
        else if(curr->data < data)curr= curr->right;
        else
        curr=curr->left;
    }
    return false;
    
}

Node* addData(Node* node, int data){
    if(node==nullptr) return new Node(data);
    if(node->data >data)node->left= addData(node->left,data);

    if(node->data<data) node->right= addData(node->right,data);

    return node;
}

int main()
{
    cout<<"Enter first node : ";
    int valroot;
    cin>>valroot;

    Node* node = new Node(valroot);

    int n = 0;

    while (n!=4)
    {
        cout << "INTPUT NUMBER : "<<endl;
        
        cout << "1. ADD "<<endl;
        cout << "2. SEARCH"<<endl;
        cout << "3. DISPLAY"<<endl;
        cout << "4. EXIT"<<endl;
        cin >> n;

        cout<<endl;

        if(n==1){
            int val;
            cout << "Enter the number you want to add: ";
            cin >> val;
            addData(node,val);
        }
         else if(n==2){
            int num;
            cout<<"Enter the number : ";
            cin>>num;
            if(search(node,num)==true)
            {
                cout<<num<<" is present in the tree"<<endl;
            }else
            {
                cout<<num<<" is not present in the tree"<<endl;
            }
        
        }

        else if(n==3){
           
            display(node);
            cout<<"end"<<endl<<endl;}

        else break;
    }

    return 0;
}