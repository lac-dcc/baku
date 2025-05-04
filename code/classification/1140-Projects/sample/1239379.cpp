#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct project{
  int st,end,rew;
};
bool comp(project &p1,project &p2){
  return p1.end<p2.end;
}
int dis(vector<int>&endPoint,int val){
  auto it=lower_bound(endPoint.begin(),endPoint.end(),val);
  if(it==endPoint.begin()){
    return 0;
  }else{
    it--;
     return 1+distance(endPoint.begin(),it);
  }
}
ll find(vector<project>&arr){
  int n=arr.size();
  vector<int>endPoint;
   for(int i=1;i<arr.size();i++){
      endPoint.push_back(arr[i].end);
   }
  ll dp[n+1];
  dp[0]=0;
  for(int i=1;i<n;i++){
    ll op1=dp[i-1];
    ll op2=arr[i].rew;
    int j=dis(endPoint,arr[i].st);
    op2+=dp[j];
    dp[i]=max(op1,op2);
  }
  return dp[n-1];
}
int main(){
  int n;
  cin>>n;
  vector<project>arr(n+1); 
  for(int i=1;i<=n;i++){
    cin>>arr[i].st>>arr[i].end>>arr[i].rew;
  }
  sort(arr.begin()+1,arr.end(),comp);
  cout<<find(arr);
  return 0;
}
