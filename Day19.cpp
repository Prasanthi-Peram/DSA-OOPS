#include <bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> prices){
    vector<int> ans;
    stack<pair<int,int>> s;
    for(auto price: prices){
        int days= 1;
        while(!s.empty() && s.top().first<=price){
        days+=s.top().second;
        s.pop();
       
        }
    s.push({price,days});
    ans.push_back(days);
 
       
    }
     return ans;   
}

int main(){
   //Brute force
   /*for(int i=0;i<n:i++){
    int days=0;
    for(int j=i;j>=0;j--){
        if(prices[i]>=prices[j]) days++;
        else break;
    }
   }//Span of ith day is days
   */ 
  //Stack based approach
  vector<int> a={100,80,60,70,60,75,85};
  vector<int> res=stockspan(a);
  for(auto i : res) cout<<i<<" ";
  cout<<"\n";
    return 0;
}