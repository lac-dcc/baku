/*
 
 ________      
|\   ____\         _____              _          ___   ___   
\ \  \___|_ ___  _|_   _|__ _   _ ___| |_   _   / _  V  _ \ 
 \ \_____  V _ \/ __; |/ _ \ | | / __; | | | | | |_| | |_| |
  \|____|\  \ _/| | | | |_|  |_| \__ \ | |_| | |  _  |  _  |
    ____\_\  \_||_|_| |\___/\__,_|___/_|\__, |0|_| |_|_| |_|
   |\_________\   |_____|               {___/                
   \|_________|                
 
*/
 
#include <bits/stdc++.h>
using namespace std;
#define sz(x) (ll)(x).size()
#define trav(x) for(auto& it: x)
#define all(x) x.begin(), x.end()
#define stp fixed<<setprecision(20)
#define tc ll tt; cin>>tt; while(tt--)
#define For(i, st, en) for(ll i=st; i<en; i++)
#define rFor(i, st, en) for(ll i=st; i>=en; i--)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define printv(x) For(i, 0, sz(x)){cout<<x[i]<<" ";} cout<<endl;  
#define print2v(x) For(i, 0, sz(x)){For(j, 0, sz(x[i])){cout<<x[i][j]<<" ";} cout<<endl;}
#define scan2v(x,n,m) For(i, 0, n){vi tp(m,0);For(j, 0, m){cin>>tp[j];}x.pb(tp);}
#define scanv(x,n) For(i, 0, n){cin>>tttt; x.pb(tttt);}
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define po pop_back
#define mp make_pair
#define ss substr
typedef deque<int> di;
typedef vector<int> vi; 
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
typedef map <int, int> mii;
typedef priority_queue <int> pq;
#define endl '\n'   
#define MAXN 300005
#define MOD 1000000007  
#define INF 1000000000000000007
#define bitc __builtin_popcountll
 
int begtime = clock(); ll tttt;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
 
#define end_routine() cout << "\n\nTime elapsed: " << (double)(clock() - begtime)*1000/CLOCKS_PER_SEC << " us\n";
 
void splitx(string s, char c, vector<string> &v){
    int i=0, j;
    while(i<sz(s)){
        j=i; string temp;
        while(j<sz(s) && s[j]!=c){temp+=s[j]; j++;}
        v.pb(temp); i=j+1; }}
struct TreeNode { int val; TreeNode *left; TreeNode *right; 
		TreeNode(int x) : val(x), left(NULL), right(NULL) {} };
 
 
signed main()
{   
	tc{
		int x,y;
		cin>>x>>y;
		//vi h,v;
		int v00=1,m,n;
		if(x==1 and y==1)
		{
			cout << 1 << endl;
			continue;
 
		}
		if(x>y)
		{
			n=x;
			if(x%2)
			{
				m=(x-1)*(x-1)+1;
			}
			else
				m=x*x;
 
		}
		else
			{
				n=y;
			if(y%2==0)
			{
				m=(y-1)*(y-1)+1;
			}
			else
				m=y*y;
			}
			n=min(x,y)-1;
			if(x>y and x%2)
				cout << m+n << endl;
			if(x>y and x%2==0)
				cout << m-n << endl;
			if(x<=y and y%2==0)
				cout << m+n << endl;
			if(x<=y and y%2)
				cout << m-n << endl;
  }
   return 0;
}
