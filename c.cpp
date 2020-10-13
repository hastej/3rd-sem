#include<iostream>
#include<vector>

using namespace std;

vector<int> arr = {2,5,7};

int ans(int n,vector<int> ans){
    if(n==0){
        for(int i =0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }

        return 1;
    }

    

    int flag = 0;

    if(n-3>=0){
        ans[0]++;
        flag = ans(n-3,ans);
        ans[0]--;
    }

    if(flag==1) return flag;
    if(n-5>=0){
        ans[1]++;
        flag =ans(n-5,ans);
        ans[1]--;
    }

    if(flag==1) return flag;
    if(n-7>=0){
        ans[2]++
       flag = ans(n-7,ans);
       ans[2]--;
    }

    return 0;
}


int main(int args,char** argv){

   int t;
   cin>>t;

    vector<int> arr(3,0);

    while(t-->0){
    int n;
    cin>>n;

    int x = ans(n,arr);
    if(x==0) return -1;
    }

return 0;
}