#include <bits/stdc++.h>
using namespace std;
//Deque is a mix of stack and queue: Double end queue: Insert and delete from start or end. Push and pop from end. Header file<deque>
//Sliding window Maximum 
int main(){
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    
    cout<<dq.front()<<"\n";
    cout<<dq.back()<<"\n";

    for(auto i : dq)
         cout<<i<<" ";
    cout<<"\n";
    return 0;
}