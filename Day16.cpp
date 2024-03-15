#include <bits/stdc++.h>
using namespace std;

/*PS: Given an array. Each element represents the height to the histogram's bar and the width of each bar is 1, find the area of largest rectangle in the histogram*/
int get_max_area(vector<int> a){
    int n=a.size(),ans=0,i=0;

    stack<int> st;
    a.push_back(0);
    while(i<n){
        while(!st.empty() && a[st.top()]>a[i]){
            int t=st.top();
            int h =a[t];
            st.pop();
            if(st.empty()){
                ans=max(ans,h*i);
            }
            else{
                int len=i-st.top()-1;
                ans=max(ans,h*len);
            }

        }
        st.push(i);
        i++;
    }
    return ans;
}
int main(){

  //Stack approach: Calculate the potential area and pop till stack elements is greater
  //Brute Force
    /*int ans=0,n=a.size();
    for(int i=0;i<n;i++){
        int minh=inf;
        for(int j=i;j<n;j++){
            minh=min(a[j],minh);
            int len=j-i+1;
            ans=max(ans,len*minh)
        }
    }cout<<ans*/

    vector<int> a={2,1,5,6,2,3};
    cout<<get_max_area(a);
    return 0;
}