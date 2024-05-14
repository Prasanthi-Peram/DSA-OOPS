#include <bits/stdc++.h>
using namespace std;
//Stack using queue
/*There are two methods to do this
1. Masking push method costly
2. Making pop method costly
*/
//Pop is costly

//Linked list implementation of queues
//Dynamic queue
O(1) only for adding element not O(n)
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class queue{
    node* front;
    node* back;

    public:
    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* n= new node(x);
       


        if(front==NULL){
            back=n;
            front=n;
        }
        back->next=n;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;

        delete todelete;
        
    }
    int peek(){
        if(front==NULL){
            cout<<"No"<<endl;
            return;
        }

        return front->data;
    }

    bool empty(){
        if(front==NULL) return true;
        return false;
    }
};

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class queue{
    node* front;
    node* back;
}

class Deque
{	
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check full or not
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } 
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        else
        {
             rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
         if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
       if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
		if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
            return true;
        }
        else
        {
            return false;
        }
    }
};//Implemenation of dequeue

class Mystack{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Mystack(){
        N=0;
    }
    int size(){
        return N;
    }
    void pop(){
        if(q1.empty()){
            return;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        N--;

        //Exchaning q1 and q2 using temporary queue
        // swap(q1,q2);
        queue<int> temp;
        temp=q1;
        q1=q2;
        q2=temp;
    }

    void push(int val){
        q1.push(val);
        N++;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        int ans= q1.front();
        q2.push(ans);

        queue<int> temp=q1;
        q1=q2;
        q2=temp;

        return ans;
    }
};
//Queues using stacks
//Approach 1

class Myqueue1{
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x){
        s1.push(x);
    }

    int pop1(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topVal=s2.top();
        s2.pop();
        return topVal;
    }
    int pop2(){
        if(s1.empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        int x= s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item=pop2();
        s1.push(x);
        return item;

    }
  bool empty(){
    if(s1.empty()){
        return true;
    }
    return false;
  }  
};
int main(){

    Mystack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    /*Myqueue1 q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);*/

    /*cout<<q.pop2()<<endl;
    cout<<q.pop2()<<endl;
    cout<<q.pop2()<<endl;
    cout<<q.pop2()<<endl;
    cout<<q.pop2()<<endl;*/
    /*cout<<q.pop1()<<endl;
    q.push(7);
    cout<<q.pop1()<<endl;
    cout<<q.pop1()<<endl;
    cout<<q.pop1()<<endl;
    cout<<q.pop1()<<endl;
    cout<<q.pop1()<<endl;
    cout<<q.empty()<<endl;*/



    return 0;
}
//Approach 2- Using function call stack
/*Dequeue:
1. If stack1 is empty then print error
2. If stack1 has only one element then return it
3. Recursively pop everthing from stack1, store the popped item in a variable res, push the res back to stack1 and return res
*/

//Queue: Stores a list of items in which an item can be inserted at one end and removed from the other end only-FIFO 
/*Operations enqueue(x),dequeue(),peek() : prints the front element,empty(),front,back pointers*/

//Array implementation of queues
#define n 20
class Myqueue{
    int *arr;
    int front;
    int back;

    public:
    Myqueue(){
        arr= new int[n];
        front=-1;
        back=-1;
    }

    void push(int x){
        if(back==n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"No elements in queue"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            cout<<"No elements in queue"<<endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
            cout<<"No elements in queue"<<endl;
            return true;
        }

        return false;
    }
};

/*int main(){
    Myqueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}*/
