// Problem: Movie Festival II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1632
// Memory Limit: 512 MB
// Time Limit: 1000 ms
 
 
/*
	
*/
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
   #define now(x) cout<<#x<<" : "<<x<<'\n'; 
   #define pm(m)  cout<<#m<<" : "; for(auto it:m) cout<<it.fs<<" "<<it.ss<<'\n'; 
   #define fv(v)  cout<<#v<<" : "; for(auto it:v) cout<<it<<" "; cout<<'\n'; 
#else
   #define now(x) ;	
   #define fv(v) ;	
   #define pm(m) ;	
#endif
const int mod = 1000000007; 
const double pi = 3.1415926536;
const long long oo=1e18;
#define FOR(i,z,n) for(int i=z;i<n;i++)
#define f(n) for(int i=0;i<n;i++)
#define int ll
typedef long long ll;
typedef  map<int,int> mii;
typedef  vector<int> vi;
#define fs first 
#define ss second
#define itf(v) v.begin(),v.end()
#define itr(v) v.rbegin(),v.rend()
int modu(int a,int b=mod) 	{return (a%b+b)%b;}
int log2(int x){return __builtin_clzll(1LL) - __builtin_clzll(x);}
template<typename T> T maxxx() {return numeric_limits<T>::max();}
const int maxx=maxxx<int>();
 
/* ---------------TEMPLATE ENDS HERE-------------*/
 
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
 
 
bool comp(pair<int,int> a,pair<int,int> b){
	//if(a.ss==b.ss) return a.fs<b.fs;
	return a.ss<b.ss;
}
void solve()
{
       int n=0,m=0,k=0,x=0,count=0,sum=0,ans=0;
       cin>>n>>m;
       vector<pair<int,int>> v(n);
       f(n){
       	cin>>v[i].fs>>v[i].ss;
       	
       }
       sort(itf(v),comp);
       
       multiset<int> ms;
       for(int i=0;i<n;i++)
       {
       	auto it=ms.upper_bound(v[i].fs);
       	if(it==ms.begin() && m!=0)
       	{
       		m--;
       		ms.insert(v[i].ss);
       		ans++;
       	}
       	else if(it!=ms.begin()){
       		ans++;
       		ms.erase(--it);
       		ms.insert(v[i].ss);
       	}
       }
       cout<<ans<<'\n';
      
       
       
	
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	/*
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif 
	*/
		
	 int test_case=1;
	//cin>>test_case;
	for(int _=0;_<test_case;_++)
	{	//cout<<"Case #"<<_+1<<": ";
		solve();
	}
	return 0;
 
}
