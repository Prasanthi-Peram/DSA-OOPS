#include <bits/stdc++.h>
using namespace std;
/*Vectors are dynamic arrays. They have the ability to resize itself when it gets
filled. The size of the vector gets doubled each time when they get filled.*/
/*int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);//Adding elements to the array

    //Accessing the elements in the array
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";//1 2 3
    cout<<endl;

    vector<int> ::iterator it;
    for(it=v.begin();it!=v.end();it++) cout<<*it<<" ";
    cout<<endl;

    for(auto element:v) cout<<element<<" ";
    cout<<endl;

    v.pop_back();//1 2

    vector<int> v2(3,50);//50 50 50
    swap(v,v2);

    for(auto element:v) cout<<element<<" ";
    cout<<endl;

    sort(v.begin(),v.end());
    for(auto element:v) cout<<element<<" ";
    cout<<endl;

    return 0;
}*/


//Pairs
/*bool myCompare(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}*/
/*int main(){
    pair<int,char> t;
    t.first=3;
    t.second='p';

    /*Reduce acc. to index 10 16 7 14 5 3 12 9 ---> 4 7 2 6 1 0 5 3 
    Logic: Sort the array, preserve the indices at the index of the smallest element place 0 */
    /*int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
    vector<pair<int,int>> v;

    // Creating pairs of elements and their original indices
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        v.push_back(make_pair(arr[i], i));
    }

    // Sorting pairs based on the first element of each pair (the values in arr[])
    sort(v.begin(), v.end(), myCompare);

    //To print the first element of array of pairs

    /*vector<pair<int,int>> ::iterator it;
    for(it=v.begin();it!=v.end();it++){
        int firstelement=it->first;
        cout<<firstelement<<" ";
    }
    cout<<endl;*/

    // Updating arr[] with the new indices after sorting
    /*for(int i = 0; i < v.size(); i++){
        arr[v[i].second] = i;
    }

    // Printing the modified array
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] << " ";
    }

return 0;
}*/



//Dynamic programming can be implemented in two ways: 1. (Top-Down) Recursion+Memoization. 2. (Bottom-up) Tabulation

//Memoization approach O(N),O(N)
/*int fib(int n, vector<int> &dp){
    //base case
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    vector<int> dp(n+1); //fib(0) to fib(n)-->n+1
    for(int i=0;i<=n;i++) dp[i]=-1; //Initialization

    cout<<fib(n,dp)<<endl;
    return 0;
}*/

//Tabulation approach-->Looping
/*int main(){
    int n;
    cin>>n;

    //step 1
    vector<int> dp(n+1);

    //step2
    dp[1]=1; dp[0]=0;

    //Step 3
    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];

    cout<<dp[n]<<endl;
    return 0;
}*/

//Optimization: use prev1,prev2 iterator from2, O(N),O(1)

//Minimum Cost of climbing stairs: Recursion, memoization, tabulation
//Recursion approach
/*int ways(int n){
    if(n==1 || n==2){
        if(n==1) return 1;
        if(n==2) return 2;
    }
    else return ways(n-1)+ways(n-2);
}
int main(){
    int n;
    cin>>n;

    cout<<ways(n)<<endl;
    return 0;
}*/


//Memoization approach
/*int ways(int n,vector<int> &dp){
    if(n==1 || n==2){
        if(n==1) return 1;
        if(n==2) return 2;

        if(dp[n]!=-1) return dp[n];

        else dp[n]=ways(n-1,dp)+ways(n-2,dp);
        return dp[n];
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n);

    for(int i=1;i<=n;i++) dp[i]=-1;
    cout<<ways(n,dp)<<endl;
}*/

//Tabulation-->looping
/*int main(){
    int n;
    cin>>n;

    vector<int> dp(n);
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n]<<endl;
    return 0;
}*/

//DSA-->Knapsack with duplicate items
/*int main(){
    int n,W;
    int v[n],w[n];

    for(int i=0;i<n;i++) cin>>v[n];
    for(int i=0;i<n;i++) cin>>w[n];

    vector<vector<int>> a(n,vector<int>(W));

    for(int i=0;i<n;i++){
        for(int j=0;j<W;j++){

        }
    }

return 0;

}*/


//

//Graphs 
