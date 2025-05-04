// i am not here to do anything i am here to see what Allah does to me
//the curse the curse the curse
// all praise to the Almighty
// i have decided that i will not be using the mobile phone any more
#include<bits/stdc++.h>
#define pb push_back
#define fr(a,b) for(int i = a; i <= b; i++)
#define rep(i,a,b) for(int i = a; i <= b; i++)
 
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define ko cout<<"Yes"<<"\n";
#define kona cout<<"No"<<"\n";
typedef long long ll;
typedef long double ld;
int mod=1e9+7;
using namespace std;
vector<int>aj[200000+1];
vector<int>len(200000+1);
vector<int>ans(200000+1);
 
void make_len(int n,int l,int p)
{
    len[n]=max(ans[n],l+1);
    vector<int>v;
    v.pb(l+1);
    for(int x:aj[n])
    {
        if(x==p){continue;}
        v.pb(ans[x]+1);
    }
 
    while(v.size()<2){v.pb(0);}
 
    sort(v.rbegin(),v.rend());
    for(int x:aj[n])
    {
        if(x==p){continue;}
        if(v[0]==(ans[x]+1)){
            make_len(x,v[1],n);
        }
        else{
            make_len(x,v[0],n);
        }
    }
 
}
 
int  make(int n,int p)
{
    int l=0;
    int co=0;
    for(int x:aj[n])
    {
        if(x!=p){
            l=max(l,make(x,n));
            co++;
        }
    }
    if(co)
    ans[n]=l+1;
    else
    ans[n]=0;
    return ans[n];
}
 
 
void f()
{
 
    int n;cin>>n;
    for(int i=1;i<=(n-1);i++)
    {
        int n1,n2;cin>>n1>>n2;
        aj[n1].pb(n2);
        aj[n2].pb(n1);
    }
    make(1,1);
    len[1]=ans[1];
 
 
    vector<int>v2;
    for(int x:aj[1])
    {
        v2.pb(ans[x]+1);
    }
 
    while(v2.size()<2){v2.pb(0);}
    sort(v2.rbegin(),v2.rend());
 
    for(int x:aj[1])
    {
        if((ans[x]+1)==v2[0]){
            make_len(x,v2[1],1);
        }
        else{
            make_len(x,v2[0],1);
        }
    }
 
    for(int i=1;i<=n;i++)
    {
        cout<<len[i]<<" ";
    }
 
 
 
}
 
//6
//1 2
//2 3
//3 4
//4 5
//5 6
 
 
 
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
 
 
 
 
 
 
//
//   int t;cin>>t;
//   while(t--)
//   {
//       f();
//       cout<<"\n";
//   }
 
      f();
 
 
 
 
 
 
 
 
 
 
//    int t;cin>>t;
//    for(int i=1;i<=t;i++)
//    {
//        ll ans=f();
//        cout<<"Case "<<i<<":"<<" "<<ans<<"\n";
//    }
 
}
 
 
 
