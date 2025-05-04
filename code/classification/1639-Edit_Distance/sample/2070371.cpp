// Problem: Edit Distance
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1639
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
 
 
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
              /*DEBUGGING OP  */
              #define  int  long long int
#define d1(x)                cout<<#x<<": "<<x<<endl
#define d2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define d3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define d4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define d5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define d6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
 
 
          /* SOME ITERATORS */
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
        /*SOME SHORTCUTS*/    
 
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define vll vector<ll ,ll >
#define pll pair< ll ,ll >
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int MOD = 1e9 + 7;
const int mod = 1e9 + 7;
bool prime[1000001];
#define all(v) (v).begin(),(v).end()
#define some(v,i,j)  ((v).begin()+i),((v).begin()+j)
void sieve() {
	 
	memset(prime, true, sizeof(prime));	
	for (int i = 2; i * i <= 1000000; i++)
	if (prime[i])	
		for (int j = i * i; j <= 1000000; j+= i)
			prime[j] = false;
	prime[0] = prime[1] = false;
	
}
int cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,ans1=0,ans2=0,ans3=0;
int m,n;
string s1,s2;
int dp[5001][5001];
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
int find(int i,int j ){
	//d3(i,j,ans);
	if( i==0){
		return j;
	}
	if(j==0){
		return i;
	}
	if(dp[i-1][j-1]!=-1){
		return dp[i-1][j-1];
	}
	if(s1[i-1]==s2[j-1]){
		return dp[i-1][j-1]=find(i-1,j-1);
	}
	return dp[i-1][j-1]=1+min(find(i-1,j-1) ,find(i,j-1) ,find(i-1,j));
}
void solve(){
	cin>>s1>>s2;
	n=s1.size();
	m=s2.size();
	f(i,0,5001){
		f(j,0,5001){
			dp[i][j]=-1;
		}
	}
	int a1=find(n,m);
	cout<<a1<<endl;
	return;
}
signed main(){
	IOS;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}