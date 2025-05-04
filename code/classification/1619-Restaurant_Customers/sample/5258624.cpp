// Always consider the edge cases when thinking of solutions.
// Edge cases for the given variables for all their combinations.
 
 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
// ordered set
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
 
// *a.find_by_order(k); -->  find kth element
// *a.order_of_key(x);  -->  find no. of elements smaller than x
// *a.lower_bound(x);   -->  first element >= x
// *a.upper_bound(x);   -->  first element > x
 
//less --> less_equal to make it multiset
//less --> greater to store in descending order
//less --> comp to make comparator of your choice
//..<int, null_type.. change int to your data type of choice like ll , double etc.
 
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vpii vector<pair<int,int>>
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define all(v) v.begin()+1,v.end()
#define nline cout<<"\n"
#define prep(a) a.clear(); a.resize(n+1);
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const int N=1e5 + 10;
const ll mod=1e9 + 7;
 
ll binpow(ll a,ll b,ll m){ ll res=1; while(b>0){ if(b&1) res=(res*a)%m; a=(a*a)%m; b>>=1; }return res; }
 
 
 
void mrinmoy(){
 
      int n;
      cin>>n;
 
      int a[n+5],b[n+5]; loop(i,1,n){ cin>>a[i]; cin>>b[i]; }
 
      sort(a+1,a+1+n); sort(b+1,b+1+n);
 
      int l=1,r=1;
 
      int ans=0, cnt=0;
 
      while(l<=n and r<=n)
      {
          if(a[l]<b[r]){ cnt++; l++; }
          else if(b[r]<a[l]){ cnt--; r++; }
          ans=max(ans,cnt);
      }
 
 
 
      cout<<ans;
}
 
int main() {
	// your code goes here
 
  /*#ifendef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif*/
 
    fastio;
 
	    mrinmoy();
 
	return 0;
}
