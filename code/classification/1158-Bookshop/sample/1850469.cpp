#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
//#define square(x) x*x a = square(2+3) 
 
#define ar array
void newt(){
	ios::sync_with_stdio(false);cin.tie(0);      // decrease the time for cin, cout
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	return;
}
const int mxN=1e3,mxX=1e6, M=1e9+7;
int n,x,h[mxN],s[mxN],dp[mxX+1];
 
int main(){
    //newt();
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++){
        //cout<<"i="<<i<<endl;
        for(int j=x;j>=h[i];--j){
            dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
      //      cout<<"j="<<j<<"=>"<<dp[j]<<" ";
        }
    //    cout<<endl;
    }
    cout<<dp[x];
}