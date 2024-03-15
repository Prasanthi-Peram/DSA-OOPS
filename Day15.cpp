#include <bits/stdc++.h>
using namespace std;
//The time complexity of the more optimized approach is O(n) and less optimized one O(nlogn)
//Sliding window maximum problem
int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n);//Range based loop
    for(auto &i: a) cin>>i;

    //More optimized:
    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!q.empty() && a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);

    for(int i=k;i<n;++i){
        while(!q.empty() && q.front()<=i-k){
            q.pop_front();
        }

        while(!q.empty() && a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    for(auto i : ans){
        cout<< i << " ";
    }
    cout<<endl;
    return 0;
}


    //Less optimized
    /*multiset<int,greater<int>> s;
    vector<int> ans;
    for(int i=0;i<k;i++){
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());
    for(int i=k;i<n;i++){
        s.erase(s.lower_bound(a[i-k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());//Time complexity=n.log(n)
    }
    for(auto i: ans)
       cout<<i<<" ";
    return 0;
}*/

/*int main(){
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
    dq.pop_back();
    dq.pop_front();

    for(auto i : dq)
       cout<<i<<" ";
    cout<<"\n";
    cout<<dq.size();//There are many function in dq header

    return 0;
}*/