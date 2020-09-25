#include<iostream>
#include<stack>

using namespace std;

string postfix(string s){
    
    string ans = "";
    stack<char> st;
    
    for(int i =0;i<s.length();i++){
        if(s[i]!='+' && s[i]!='-' && s[i]!='/'&& s[i]!='*'&& s[i]!='^'&& s[i]!='('&& s[i]!=')'){
            ans+=s[i];
        }
        
        else {
            if(s[i]=='('){
                st.push('(');
            }
            
            else if(s[i]==')'){
                
                while(st.top()!='(')
                {
                ans+=st.top();
                st.pop();
                }
                st.pop();
            }

            else if(s[i]=='^'){
                
                st.push('^');
            }

            else if(s[i]=='+' || s[i] == '-'){
                while(st.size()!=0 && st.top()!='('){
                ans+=st.top();
                st.pop();
                }
                st.push(s[i]);
              }
            
            else if(s[i]=='*' || s[i] == '/'){
                while(st.size()!=0 && st.top()!='(' && (st.top()=='*' || st.top()=='/')) {
                    ans+=st.top();
                    st.pop();}
                    st.push(s[i]);
            }
        }

       

    } while(st.size()!=0){
                ans+=st.top();
                st.pop();
                }

    return ans;
     
}

int main(){
    string s;

    cout<<endl<<"Enter infix expression : ";
    cin>>s;

    cout<<endl<<"Postfix expression is : "<<postfix(s)<<endl;
    
    return 0;
}