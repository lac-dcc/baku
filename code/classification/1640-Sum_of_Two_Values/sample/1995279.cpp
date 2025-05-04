#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll factorial[200001];
bool check(ll a[],ll n,ll x)
{
    for(int i=0;i<n;i++)
    {
        if((x&a[i])!=x)
        {
            return false;
        }
    }
    return true;
}
ll binpow(ll a, ll b, ll m) {                           //binary exponentiation with mod m (a^b)%m
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll invMod(ll a)
{
    return binpow(a,mod-2,mod);
}
ll comb(ll n,ll k,ll factorial[])
{
    if(k==0)return 1;
    ll y=(factorial[k]*factorial[n-k])%mod;
    ll x=factorial[n]%mod;
    return (x*invMod(y))%mod;
}
void toh(ll n,ll a,ll b,ll c)
{
    if(n==1)
    {
        cout<<a<<" "<<c<<"\n";
        return;
    }
    toh(n-1,a,c,b);
    cout<<a<<" "<<c<<"\n";
    toh(n-1,b,a,c);
}
void calcFactorial()
{
    factorial[0]=1;
    factorial[1]=1;
    for(int i=2;i<=200000;i++)
    {
        factorial[i]=(factorial[i-1]*i);
    }
}
void solveNQueens(char a[8][8],int row)
{
    if(row==8)
    {
        // for(ll i=0;i<8;i++)
        // {
        //     for(ll j=0;j<8;j++)
        //     {
        //         cout<<a[i][j];
        //     }
        //     cout<<"\n";
        // }
        // cout<<'\n';
        // exit(0);
        return;
    }
    for(int i=0;i<8;i++)
    {
        if(a[row][i]=='.')
        {
            vector<pair<int,int>>vp;
            a[row][i]='Q';
            for(int j=row+1;j<8;j++)
            {
                if(a[j][i]=='.'){
                a[j][i]='x';
                vp.push_back({j,i});}
            }            
            int col=i;
            for(int x=1;x<8;x++)
            {
                if(row+x<8 && col+x<8)
                {
                    if(a[row+x][col+x]=='.'){
                    a[row+x][col+x]='x';
                    vp.push_back({row+x,col+x});}
                }
                if(row+x<8 && col-x>=0)
                {
                    if(a[row+x][col-x]=='.'){
                    a[row+x][col-x]='x';
                    vp.push_back({row+x,col-x});}
                }
                if(row-x>=0 && col-x>=0)
                {
                    if(a[row-x][col-x]=='.'){
                    a[row-x][col-x]='x';
                    vp.push_back({row-x,col-x});}
                }
                if(row-x>=0 && col+x<8)
                {
                    if(a[row-x][col+x]=='.'){
                    a[row-x][col+x]='x';
                    vp.push_back({row-x,col+x});}
                }
            }
            solveNQueens(a,row+1);
            for(auto it:vp)
            {
                a[it.first][it.second]='.';
            }  
            a[row][i]='.';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);                //optimizing input, output
    cin.tie(0);                             //optimizing input, output
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n);
    vector<ll>v1(n);
    for(ll i=0;i<n;i++){cin>>v[i];v1[i]=v[i];}
    sort(v.begin(),v.end());
    int l=0, r=n-1;
    bool ch=false;
    while(l<r)
    {
        if(v[l]+v[r]==x)
        {
            ch=true;
            ll j;
            for(ll i=0;i<n;i++)
            {
                if(v1[i]==v[l])
                {
                    cout<<i+1<<" ";
                    j=i;
                    break;
                }
            }
            for(ll i=0;i<n;i++)
            {
                if(v1[i]==v[r] && j!=i)
                {
                    cout<<i+1<<" ";
                    break;
                }
            }
            break;
        }
        else if(v[l]+v[r]<x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    if(!ch)
    {
        cout<<"IMPOSSIBLE";
    }
}
