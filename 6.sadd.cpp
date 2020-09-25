#include<iostream>

using namespace std;

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

void addition(int mat1[][3],int mat2[][3],int ans[][3],int size1,int size2,int n){

    int i =0,j=0,k=0;

    while(i<size1 && j<size2){

        if(mat1[i][0]==mat2[j][0]){
              if(mat1[i][1]==mat2[j][1]){
                    ans[k][0] = mat1[i][0];
                    ans[k][1] = mat1[i][1];
                    ans[k][2] = mat1[i][2] + mat2[j][2];
                    k++;
                    j++;
                    i++;
              } 

              else if(mat1[i][1]<mat2[j][1]){
                    ans[k][0] = mat1[i][0];
                    ans[k][1] = mat1[i][1];
                    ans[k][2] = mat1[i][2];
                    k++;
                    i++;
              }   
              
              else if(mat1[i][1]>mat2[j][1]){
                    ans[k][0] = mat2[j][0];
                    ans[k][1] = mat2[j][1];
                    ans[k][2] = mat2[j][2];
                    k++;
                    j++;

              }   
        }
        else if(mat1[i][0]<mat2[j][0]){
                    ans[k][0] = mat1[i][0];
                    ans[k][1] = mat1[i][1];
                    ans[k][2] = mat1[i][2];
                    k++;
                    i++;
        }   
              
        else if(mat1[i][0]>mat2[j][0]){
                    ans[k][0] = mat2[j][0];
                    ans[k][1] = mat2[j][1];
                    ans[k][2] = mat2[j][2];
                    k++;
                    j++;

        }
    }

        while(i!=size1){
             ans[k][0] = mat1[i][0];
                ans[k][1] = mat1[i][1];
                ans[k][2] = mat1[i][2];
                k++;
                i++;
           }
 
    
        while(j!=size2){
                ans[k][0] = mat2[j][0];
                ans[k][1] = mat2[j][1];
                ans[k][2] = mat2[j][2];
                k++;
                j++;

            }
    
    
    cout<<k;

    cout<<endl<<"Added matrix is : "<<endl;
    display(n,ans);

}

void input(int size1,int mat1[][3],int size2 ,int mat2[][3],int n){
     
    for(int i = 0;i<size1;i++){

        cout<<"Input row of element "<<i+1<<" : ";
        cin>>mat1[i][0];

        cout<<"Input col of element "<<i+1<<" : ";
        cin>>mat1[i][1];

        cout<<"Input value of element "<<i+1<<" : ";
        cin>>mat1[i][2];   
    }
    cout<<"Matrix 1 is : "<<endl;
    display(n,mat1);
    
    for(int i = 0;i<size2;i++){

        cout<<"Input row of element "<<i+1<<" : ";
        cin>>mat2[i][0];

        cout<<"Input col of element "<<i+1<<" : ";
        cin>>mat2[i][1];

        cout<<"Input value of element "<<i+1<<" : ";
        cin>>mat2[i][2];   
    }

    cout<<"Matrix 2 is : "<<endl;
    display(n,mat2);

    int ans[size1+size2][3];

    addition(mat1,mat2,ans,size1,size2,n);

}



int main(){

    int n;
    cout<<"Input size of matrices : ";
    cin>>n;

    int ele1;
    cout<<"Input number of element in matrix 1 : ";
    cin>>ele1;
    int matrix1[ele1][3];
    
    int ele2;
    cout<<"Input number of element in matrix 2 : ";
    cin>>ele2;
    int matrix2[ele2][3];
    input(ele1,matrix1,ele2,matrix2,n);

    return 0;
}

