#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>A(n/2);
    vector<int>B(n-n/2);
    
    for(int i=0;i<n/2;++i){
        cin>>A[i];
    }
    for(int i=0;i<n-n/2;++i){
        cin>>B[i];
    }
 
    vector<long long>X;
    vector<long long>Y;
 
    int a=A.size();
    int b=B.size();
 
    for(int i=0;i<(1<<a);++i){
        long long sum=0;
        for(int j=0;j<a;++j){
            if(i&(1<<j)){
                sum+=A[j];
            }
        }
        X.push_back(sum);
    }
 
    for(int i=0;i<(1<<b);++i){
        long long sum=0;
        for(int j=0;j<b;++j){
            if(i&(1<<j)){
                sum+=B[j];
            }
        }
        Y.push_back(sum);
    }
 
    sort(Y.begin(),Y.end());
 
 
    long long ans=0;
    for(int i=0;i<(int)X.size();++i){
        long long y=x-X[i];
        if(y>=0){
            auto ps=lower_bound(Y.begin(),Y.end(),y);
            auto pe=upper_bound(Y.begin(),Y.end(),y);
            ans+=pe-ps;
        }
    }
    cout<<ans;
}
 
/*
As x <= 10^9, DP is not possible
 
As n <= 40, some brute force is possible
However, generating all subsets results in O(2^n) time complexity => TLE
 
"Meet in the middle" technique can speed up from O(2^n) to O(2^(n/2)) => AC
 
Divide the array into 2 sets, generate all possible subsets in each set 
Iterating through all values in one set and use binary search on the other set to find the complement to get a total sum of x
Time complexity: 2 * O(2^(n/2))
*/
