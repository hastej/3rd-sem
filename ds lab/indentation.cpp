#include<iostream>
#include<stack>

using namespace std;

int is_intended(stack<int>* s, int count,int line){

    if(s->size() == 0 || s->top() <= count ){
        
        s->push(count);
    }

    else{
        while(s->size()!=0 && s->top() > count){
            s->pop();
        }

        if(s->top() != count){
            cout<<"This File Is Not Properly Indented"<<endl<<"Error Found At Line "<<line<<", Not Properly Indented";
            return -1;
        }
       
    }

     return 1;
}

int main(){
    
    FILE *fp;
    char filename[100] ;
    cin>>filename; 
    fp=fopen(filename,"r");
    
    if(fp==NULL){
        cout<<"File entered does not exist;Try again"<<endl;
        exit(1);
    }

    stack<int> *S = new stack<int>;
    int error = 1, currentline = 1,count = 0;;


    while(1){

        char ch;
        ch=fgetc(fp);

        count=0;
        
        if(ch==EOF){
            break;
        }

        while(ch==' '){
            count++;
            ch=fgetc(fp);
        }

        while(ch!=EOF && ch!='\n'){
            ch=fgetc(fp);
        }

        error=is_intended(S,count,currentline);

        if(error==-1){
            break;
        }

        currentline++;
    }

    if(error != -1 ){
        cout<<"THIS FILE IS PROPERLY INDENTED.";
    }

    return 0;

}