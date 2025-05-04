#include <bits/stdc++.h>
#define REP(i,n) for (int i=1;i<=n;i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long int>
#define vii vector<pair<int,int>>
#define lli long long int
#define lld double
#define mod 1000000007
#define siz 1000002
#define larg 1e9
 
using namespace std;
 
void preprep()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 
string word1 , word2;
 
void solve()
{
    cin>>word1>>word2;
    size_t len1 = word1.size();
    size_t len2 = word2.size();
 
    vector<lli> dp(len1+1);
    vector<lli> prev(len1+1);
    prev[0] = 0;
 
    for(lli i=1 ; i<=len1 ; i++)    prev[i] = prev[i-1] + 1;
 
    for(auto ch : word2)
    {
        dp[0] = prev[0] + 1;
 
        for(lli i=1 ; i<=len1 ; i++)
        {
            if(ch == word1[i-1])
            {
                dp[i] = prev[i-1];
                continue;
            }
 
            lli op1 = prev[i] + 1;
            lli op2 = dp[i-1] + 1;
            lli op3 = prev[i-1] + 1;
 
            dp[i] = min(op1 , min(op2,op3));
        }
 
        swap(dp,prev);
        fill(dp.begin() , dp.end() , 0);
    }
 
    cout<<prev[len1]<<"\n";
 
}
 
 
 
 
 
int main()
{
    preprep();
    lli q = 1;
    //cin>>q;
    while(q--)      solve();
 
}
