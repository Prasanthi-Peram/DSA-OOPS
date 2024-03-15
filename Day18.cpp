#include <bits/stdc++.h>
using namespace std;
//Stock span problem
/*Span of a stock: Span of stock's price today== The maximum number of consecutive days(starting from today and going backwards) for which the price of the stocks was less than or equal to today's price

PS: To find the span of stocks for all the days
*/

//Redundant Parenthesis: We require to handle only four operators: +,-,*, Are there extra brackets.
//Stack based Approach
int main(){
    /*
      Push brackets and operators into the stack. When a closed bracket is encountered see to it that there is an operator in the stack and that the stack is not empty.
      Useful brackets contain operators      
    */
   string s; cin>>s;
   stack<char> st;
   bool ans=false;
   for(int i=0;i<s.size();i++){
    if(s[i]=='+'|| s[i]=='-'||s[i]=='*'||s[i]=='/'){
        st.push(s[i]);
    }
    else if(s[i]=='('){
        st.push(s[i]);
    }
    else if(s[i]==')'){
        if(st.top()=='('){
            ans=true;
        }
        while(st.top()=='+'|| st.top()=='-'||st.top()=='*'||st.top()=='/'){
            st.pop();
        }
        st.pop();
    }
   }
   cout<<ans;
    return 0;
}