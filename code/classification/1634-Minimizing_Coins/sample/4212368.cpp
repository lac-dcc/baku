#include<bits/stdc++.h>
#define ll long long int
#define mii map<int,int>
#define qi queue<int>
#define pqi priority_queue<int>
#define pqgi priority_queue<int,vector<int>,greater<int>>
#define si set<int>
#define vi vector<int>
#define vll vector<long long int>
#define vii vector<pair<int,int>>
#define mii map<int,int>
#define ii pair<int,int>
#define SYNC ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define mod 1000000007
#define mo 998244353
#define inf 1e18
#define F first
#define S second
#define ld long double
#define INF (int)INT_MAX
#define PI 3.1415926535898
using namespace std;
const int N=1e6+5;
clock_t timeStart, timeFinish;
void timeBegin(){
    timeStart = clock();
}
void timeEnd() {
    timeFinish = clock();
}
void timeDuration() {
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}
/*ll po(ll A,ll B)
{
    ll RES=1;
    while(B)
    {
        if(B&1)
            RES*=A;
        B>>=1;
        A*=A;
    }
    return RES;
}*/
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> v(n+1, 0);
    vector<int> dp(x+1, INT_MAX);
    for(int i=1;i<=n;i++)
    {
    	cin>>v[i];
    }
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(i>=v[j] && dp[i-v[j]]!=INT_MAX)
    			dp[i]=min(dp[i],dp[i-v[j]]+1);
    	}
    }
    if(dp[x]!=INT_MAX)
    	cout<<dp[x];
    else cout<<-1;
    return;
}
int main()
{
    SYNC
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        //cout<<"Case #"<<i+1<<":"
        solve();
    }
    //timeDuration();
    return 0;
}
