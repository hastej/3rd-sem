#include<iostream>

using namespace std;

void inputsp(int matrix[][3],int n){

    for(int i = 0;i<n;i++){

        cout<<"Input row ,col and val of element "<< i+1<<" : ";
        cin>>matrix[i][0];
        cin>>matrix[i][1];
        cin>>matrix[i][2];   
    }

}

void display(int size,int mat[][3]){

      int k = 0;

      for(int i =0;i<size;i++){
          for(int j=0;j<size;j++){
              if(mat[k][0]==i && mat[k][1]==j){
                  cout<<mat[k][2]<<" ";
                  k++;
              }
              else cout<<"0 ";
          }
          cout<<endl;
      }
     
}

void sorting(int matrix[][3],int n){

        for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1;j++){
            if(matrix[j][0]*10 + matrix[j][1]>=matrix[j+1][0]*10 + matrix[j+1][1]){
                //swaping
                swap(matrix[j][0],matrix[j+1][0]);
                swap(matrix[j][1],matrix[j+1][1]);
                swap(matrix[j][2],matrix[j+1][2]);
            }
        }
    }
}

void transposing(int matrix[][3],int n){
    for(int i = 0;i<n;i++){
        int swap = matrix[i][0];
        matrix[i][0] = matrix[i][1];
        matrix[i][1] = swap;
    }
    sorting(matrix,n);
}

void transpose(){
    int size;
    cout<<"Input size of matrix : ";
    cin>>size;

    int n;
    cout<<"Input number of element in matrix : ";
    cin>>n;
    int matrix[n][3];

    inputsp(matrix,n);
    
    cout<<endl<<"Input matrix is : "<<endl;
    display(size,matrix);

    transposing(matrix,n);

    cout<<endl<<"Transpose matrix is : "<<endl;
    display(size,matrix);
    
}

void inputformultiply(int size,int n1,int n2,int matrix1[][3],int matrix2[][3]){
   
    inputsp(matrix1,n1);
    cout<<endl<<"Matrix1 is : "<<endl;
    display(size,matrix1);
    
    inputsp(matrix2,n2);
    cout<<endl<<"Matrix 2 is :"<<endl;
    display(size,matrix2);

}


void multiply(){
    int size;
    cout<<"Input size of matrices : ";
    cin>>size;

    int n1;
    cout<<"Input number of element in matrix 1 : ";
    cin>>n1;
    int matrix1[n1][3];
    
    int n2;
    cout<<"Input number of element in matrix 2 : ";
    cin>>n2;
    int matrix2[n2][3];

    inputformultiply(size,n1,n2,matrix1,matrix2);

    transposing(matrix2,n2);
    
    int ans[n1*n2][3];

    int k = 0;
   
    for(int i = 0;i<n1;i++){
        
        for(int j = 0;j<n2;j++){
           
            if(matrix1[i][1]==matrix2[j][1]){
             
                ans[k][0] = matrix1[i][0];
                ans[k][1] = matrix2[j][0];
                ans[k][2] = matrix2[j][2] * matrix1[i][2];
                k++;

             
            }
        }
    }

    cout<<endl<<"Multiplied matrix is : "<<endl;
    display(size,ans);
   
}



int main(){

    int k;

    cout<<"Press the numer to perform operation"<<endl<<"1 for transpose"<<endl<<"2 for multiplication"<<endl;
    cin>>k;

    if(k==1)transpose();
    if(k==2)multiply();


    return 0;
}