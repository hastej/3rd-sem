#include<iostream>

using namespace std;

void merge(){
    string s1,s2,s3;
    cout<<"Enter string 1 : ";
    cin>>s1;
    cout<<"Enter string 2 : ";
    cin>>s2;

    s3 = s1+s2;
    cout<<endl<<"Mergerd string is : " <<s3;
}

void reverse(){
    string s;
    cout<<"Input string : ";
    cin>>s;

    for(int i = 0;i<s.length()/2;i++){
            char swap = s[i];
            s[i] = s[s.length()-1-i];
            s[s.length()-1-i] = swap;
    }

    cout<<endl<<"Reversed string is : "<< s;
}

int main(){
    int n;

    cout<<"PRESS THE NUMBER"<<endl<<"1 TO MERGE"<<endl<<"2 TO REVERSE"<<endl;

    cin>>n;

    if(n==1){
        merge();
    }

    if(n==2){
        reverse();
    }

    cout<<endl;

    return 0;
}