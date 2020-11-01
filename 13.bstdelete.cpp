#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int data)
    {
        this->data = data;
    }
};

void display(Node* root){
    if(root==nullptr) return;

    display(root->left);

    cout<<root->data<<"->";

    display(root->right);
}

Node* addData(Node* root, int data){
    if(root==nullptr) return new Node(data);
    if(root->data >data)root->left= addData(root->left,data);

    if(root->data<data) root->right= addData(root->right,data);

    return root;
}

Node* DeleteAllLeafNodes(Node* root) 
{ 
    if (root == nullptr) 
    return nullptr; 

    if (root->left == nullptr && root->right == nullptr) { 
        
        return nullptr; 
    } 
  
    root->left = DeleteAllLeafNodes(root->left); 
    root->right = DeleteAllLeafNodes(root->right); 
  
    return root; 
} 

int main()
{
    cout<<"Enter First Node : ";
    int data;
    cin>>data;
    Node* root = new Node(data);

    int n = 0;

    while (n!=4)
    {
        cout << "INTPUT NUMBER : "<<endl;
        
        cout << "1. ADD "<<endl;
        cout << "2. REMOVE ALL LEAFS"<<endl;
        cout << "3. DISPLAY"<<endl;
        cout << "4. EXIT"<<endl;
        
        cin >> n;

        cout<<endl;

        if(n==1){
            int val;
            cout << "Enter the number you want to add: ";
            cin >> val;
            addData(root,val);
        }
         else if(n==2){
             root = DeleteAllLeafNodes(root);
             cout<<endl<<"All leafs removed"<<endl<<endl;
        }

        else if(n==3){
           
            display(root);
            cout<<"end"<<endl<<endl;}

        else break;
    }

    return 0;
    
}