//Balanced Parenthesis
//Balanced {[()]}
//unbalanced [{()]}
//Infix to pefix conversion
/*Algoritm: Reverse the string and swap opening and closing brackets. If operand print If '(' push to stack. If ')' pop from stack and print until '(' is found. If operator pop from stack and print until an operator with less precedence is found. Then reverse the answer */
//Infix to postfix conversion
/*Algorithm: If operand print
If '(' push to stack, If ')' pop from stack and print until '(' is found, If operator pop from stack and print until an operator with less precedence is found, bascically operators and brackets are pushed into the stack*/
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    int n=s.size();

    stack<char> st;
    bool ans=true;

    for(int i=0;i<n;i++){
        if(s[i]=='{'|| s[i]=='('||s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(s[i]=='}'){
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(s[i]==']'){
            if(!st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                ans=false;
                break;
            }
        }
    }
    if(!st.empty()) return false;
    else return ans;
}



int prec(char c){

    if(c=='^'){
        return 3;
    }
    else if(c=='*'|| c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else return -1;
}
string infixtoPrefix(string s){
    reverse(s.begin(),s.end());
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || s[i]>='A'&&s[i]<='Z'){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){//Reversing opening and closing brackets
            while(!st.empty() && st.top()!=')'){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && (prec(st.top())>=prec(s[i]))){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    reverse(res.begin(),res.end());
    return res;    
}
string infixtoPostfix(string s){

    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || s[i]>='A'&&s[i]<='Z'){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && (prec(st.top())>prec(s[i]))){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}

int main(){
    string s= "{[()}]";

    if(isValid(s)){
        cout<<"Valid String"<<endl;
    }
    else{
        cout<<"Invalid string"<<endl;
    }

    cout<<infixtoPostfix("(a-b/c)*(a/k-l)")<<endl;
    cout<<infixtoPrefix("(a-b/c)*(a/k-l)");
    return 0;
}