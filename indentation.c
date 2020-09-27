#include<stdio.h>
#include<stdlib.h>

struct stack{

int val[1000];
int top;

};

void init(struct stack* S){
    S->top = -1; 
}

void push(struct stack* S,int data){

    S->top++;
    S->val[S->top] = data;

}

void pop(struct stack* S){
    S->top--; 
}

int top(struct stack* S){
    return S->val[S->top];
}

int is_intended(struct stack* S,int count,int line){
    if( S->val[S->top] <= count || S->top == -1){
        push(S,count);
    }

    else{
        

        while(S->top != -1 && S->val[S->top] > count){
            pop(S);
        }

        if(S->val[S->top] != count){
            printf("\nThis File Is Not Properly Indented\nError Found At Line %d, Not Properly Indented\n",line);
            return -1;
        }

        return 1;

    }
}

int main(){

    int count = 0;
    int islineempty = 1;
    int ok = 1;

    int currentline = 1;

    

    FILE *fp;
    struct stack S1;
    init(&S1);

    char filename[100] ;

    scanf("%s",&filename); 

    printf("%s",filename);
          
    fp=fopen(filename,"r");
    
    if(fp==NULL){
        printf("\nFile entered does not exist;Try again\nCreate test case file then input again at command prompt\n");
        exit(1);
    }

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
            islineempty=0;
            ch=fgetc(fp);
        }

        
            ok=is_intended(&S1,count,currentline);
        

        if(ok==-1){
            break;
        }

        currentline++;
    }

    if(ok != -1 ){
        printf("\nTHIS FILE IS PROPERLY INDENTED.");
    }



    return 0;

}