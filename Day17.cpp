//Trapping rainwater harvesting
#include <bits/stdc++.h>
using namespace std;
int rain_water(vector<int> a){
    stack<int> st;
    int ans=0;
    int n= a.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            int cur=st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int  diff=i-st.top()-1;
            ans+=(min(a[st.top()],a[i])-a[cur])*diff;
        }
        st.push(i);
    }
    return ans;
}

/*PS: Given a non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining*/

int main(){
    //Array: [0,1,0,2,1,0,1,3,2,2,1]
    /*
    Height: 0 1 0 2 1 0 1 3 2 1 2 1
    Right:  3 3 3 3 3 3 3 3 2 2 2 -
    Left :  - 0 1 2 2 2 3 3 3 3 3 3
    min(R,L 0 0 1 2 2 2 3 2 2 2 0
    Ans adding max(min(L,R)-Height[i],0) Length>Breadth

    */
   vector<int> a={0,1,0,2,1,0,1,3,2,2,1};
   cout<<rain_water(a);
    return 0;
}