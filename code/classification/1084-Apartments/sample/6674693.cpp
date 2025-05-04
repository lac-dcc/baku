#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vs vector<string>
#define PB push_back
#define MP make_pair
#define FOR(c, a, b) for(int c=a;i<b;c++)
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<"\n";
#else
#define debug(x)
#endif
template<class T> void _print(T &x){cerr<< x;}
template<class T> void _print(vector<T> &x){cerr<< "[ ";for(T &a:x)cerr<< a<< ", ";cerr<<"]";}
inline void solution();
int main(){
  #ifndef ONLINE_JUDGE
  freopen("error.txt", "w", stderr);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solution();
}
 
 
 
inline void solution(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> desired(n);
  vector<int> size(m);
  int t=0;int j=0; int ans=0;
  for(int i =0;i<n;i++){
    cin>>desired[i];
  }
  for(int i=0;i<m;i++) cin >> size[i];
  sort(desired.begin(),desired.end());
  sort(size.begin(),size.end());
  while(t<n and j<m){
    if(abs(desired[t]-size[j]) <= k){
      t++;j++;ans++;
    }
    else{
      if(desired[t] > size[j]) j++;
      else t++;
    }
  }
  cout<< ans;
}
