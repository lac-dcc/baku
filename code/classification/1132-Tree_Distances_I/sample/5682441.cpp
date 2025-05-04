#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(t)            int t; cin>>t; while(t--)
#define rl(i,m,n) 		for(int i=n;i>=m;i--)
#define st(v) 			sort(v.begin(),v.end())
#define rv(v) 			reverse(v.begin(),v.end())
 
//Input
#define arrinput(arr,n,type) for(int i=0 ; i<n ; i++){type c ; cin >> c ; arr.pb(c) ;}
#define graphinput(graph,n,type) for(int i=0 ; i<n ; i++){type a , b ; cin >> a >> b ; graph[a].pb(b) ; graph[b].pb(a) ;}
#define matrixinput(mat,n,m,type) for(int i=0 ; i<n ; i++){vector<type>temp(m); for(int j=0 ; j<m ; j++) cin>>temp[j] ; mat.pb(temp) ;}
 
//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
 
//Bits
int binarytodecimal(string n){string num = n;int dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
string decimaltobinary(int a){string ans="" ;while(a>0){char c =a%2+'0';ans=c+ans;a/=2;}return ans;}
 
//Check
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}
 
// Mathematical functions
int vecsum(vector<int>& v){return accumulate(v.begin(),v.end(),0*1ll);}
int gcd(int a, int b){if (b == 0)return a;return gcd(b, a % b);}
int lcm(int a, int b){return (a/gcd(a,b)*b);}
 
// code below  
vector<vector<int>> graph ;
vector<int> dis ;
 
int fun(int i){
	unordered_map<int,int> mp ;
	queue<int> q ;
	q.push(i) ;
	mp[i]=1 ;
	dis[i]=max(dis[i],mp[i]-1) ;
	while(!q.empty()){
		int x=q.front() ;
		q.pop() ;
		for(auto d:graph[x]){
			if(mp[d]) continue ;
			q.push(d) ;
			mp[d]=mp[x]+1 ;
			dis[d]=max(dis[d],mp[x]) ;
		}
	}
	int ans=i ;
	for(auto d:mp){
		if(d.second>mp[ans]) ans=d.first ;
	}
	return ans ;
} 
 
void solve()
{	
	int n ;
	cin >> n ;
	graph=vector<vector<int>>(n+1) ;
	dis=vector<int>(n+1) ;
	for(int i=2 ; i<n+1 ; i++){
		int a , b ;
		cin >> a >> b ;
		graph[a].pb(b) ;
		graph[b].pb(a) ;
	}
	int req=fun(1) ;
	int temp=fun(req) ;
	int x=fun(temp) ;
	for(int i=1 ; i<=n ; i++) cout << dis[i] << " " ;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve() ;
}
