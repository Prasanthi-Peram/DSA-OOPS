#include <bits/stdc++.h>
using namespace std;
//Note that the code only works for single digit numbers

//Postfix expression evaluation
int postfixEvaluation(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<=9){
            st.push(s[i]-'0');
        }

        else{
            int op2= st.top();
            st.pop();
            int op1=st.top();
            st.pop();

            switch(s[i]){
                case '+':
                  st.push(op1+op2);
                case '-':
                  st.push(op1-op2);
                case '*':
                  st.push(op1*op2);
                case '/':
                  st.push(op1/op2);
                case '^':
                  st.push(pow(op1,op2));
                default: break;
                
            } 
        }
    }
    return st.top();
}

int prefixEvaluation(string s){
    stack<int> st;

    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(s[i]){
            case '+':
              st.push(op1+op2);
              break;
            case '-':
              st.push(op1-op2);
              break;
            case '*':
              st.push(op1*op2);
              break;
            case '/':
              st.push(op1/op2);
              break;
            case '^':
              st.push(pow(op1,op2));
              break;

              default: break;
        }
        }
    }
    return st.top();
}

//Prefix,Infix,Postfix expression
/*Infix <operand><operator><operand>: Operator precedence. Associativity L->R expect bracket and expo

-Prefix: <operator><operand><operand> //Polish notation
-Postfix expression <operand><operand><operator> //Reverse Polish notation*/
//Prefix evaluation using stack

int main(){
    
    cout<<prefixEvaluation("-+7*45+20")<<endl;
    cout<<postfixEvaluation("46+2/5*7+")<<endl;
    return 0;
}