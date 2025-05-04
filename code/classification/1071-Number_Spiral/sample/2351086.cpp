#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
#define pb push_back
#define endl "\n";
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N=1e9+7;
 
void solve()
{
    ll x,y,X,Y;
    cin>>x>>y;
    if (x&1)
        X=(x-1)*(x-1) +1;
    else
        X=x*x;
    if (y&1)
        Y=y*y;
    else
        Y=(y-1)*(y-1)+1;
    //cout<<X<<" "<<Y<<endl;
    if (x>=y)
    {
        if (x&1)
            cout<<X+(y-1);
        else
            cout<<X-(y-1);
    }
    else
    {
        if (y&1)
            cout<<Y-(x-1);
        else
            cout<<Y+(x-1);
    }    
}
 
int main()
{
    clock_t clk = clock();
    sync;
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
        cout<<endl;
    }
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}