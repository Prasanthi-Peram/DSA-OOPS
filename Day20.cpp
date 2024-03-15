                #include <bits/stdc++.h>
                using namespace std;
//Longest substring(continous) subsequence may or maynot be continuous just the order is same without repeating haracter
int main(){
//i, start+ all characters=-1 initially if an element is repeated then increment start by 1.
string s;
cin>>s;
vector<int> dict(256,-1);
int maxLen=0,start=-1;
for(int i=0;i<s.size();i++){
    if(dict[s[i]]>start)
    start=dict[s[i]];
    dict[s[i]]=i;
    maxLen=max(maxLen,i-start);
}
cout<<maxLen;
}
            
                //Maximum consecutive 1's
                /*ps: Given an array A of 0's and 1's, we may change up to k values from 0 to 1. Return the length of the longest(contiguous) subarray that contains only 1s.
                */
        // int main(){
                /*Algorithm: Find the longest subarray with at most k zeros.
                -for each a[j], try and find the longest subarray.
                -if a[i]-a[j] has zeros<=k, we continue to increment j
                -...>k, we increment i(as well as j).
                */
            /*int n; cin>>n;
            int k; cin>>k;
            vector<int> a(n);
            for(auto &i : a) cin>>i;
            int zerocount=0,i=0, ans=0;
            for(int j=0;j<a.size();j++){
                if(a[j]==0) zerocount++;
                while(zerocount>k){
                    if(a[i]==0) zerocount--;
                    i++;
                }
                ans =max(ans,j-i+1);
            }
            cout<<ans;
                return 0;
            }*/
                //PS: Given an array and a value, find if there exists three members whose sum is equalt to the given value
                //int main(){
                    //Brute force: O(n3) a[i]+a[j]+a[k]==target
                    //Two pointer technique
                    /*1. Sort the array
                    2. Traverse the array and fix the first element of the triplet. The problem reduces to find if there exist two elements having sum equal to x=a[i]

                    Time complexity: Sort: O(NlogN)
                    Iterating each element and applying two sum problem to rest of the array: O(N*N)

                    Final Time complexity: O(N2)

                    The two sum two pointer approach is applied to a sorted array
                    */

            /*    int n; cin>>n;
                int target; cin>>target;

                vector<int> a(n);
                for(auto &i : a) cin>>i;
                bool found =false;
                sort(a.begin(),a.end()); 
                for(int i=0;i<n;i++){
                    int lo=i+1,hi=n-1;
                    while(lo<hi){
                        int current=a[i]+a[lo]+a[hi];
                        if(current==target){
                            found=true;
                        }
                        if(current<target) lo++;
                        else hi--;
                    } 
                    
                }
                if(found) cout<<"True";
                else cout<<"False";
                return 0;
                }*/
