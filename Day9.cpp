#include <bits/stdc++.h>
using namespace std;
//Prefix,Infix,Postfix expression
/*Infix <operand><operator><operand>: Operator precedence. Associativity L->R expect bracket and expo

-Prefix: <operator><operand><operand>*/


//Reversing a stack: Can be done by creating an extra stack as well
//Elements removed are stored in call stack
/*void insertAtBottom(stack<int>&st,int el){
    if(st.empty()){
        st.push(el);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st,el);

    st.push(topele);
}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele =st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);

}*/

/*void reverseSentence(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' '&& i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    cout<<endl;
}*/
//#define n 100
int main(){
    /*stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;*/
    //string s="Hey, how are you doing?";
  //  reverseSentence(s);
  return 0;
}
//Reversing a sentence using stack


/*class Mystack {
    int *arr;
    int top;

public:
    Mystack() {
        arr = new int[n];
        top = -1;
    }

    void push(int x) {
        if (top == n - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    int getTop() {
        if (top == -1) {
            cout << "No element in stack" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};

int main() {
    Mystack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.getTop() << endl;
    st.pop();
    cout << st.getTop() << endl;
    st.pop();
    st.pop();
    st.pop();

    return 0;
}*/
