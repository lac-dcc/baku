#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<ll,ll>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define f first
#define s second
const int N = 2e5+5;
int n,q,a[N];
struct node{
    ll sum,pre,suf,mxm;
}st[1<<19];
node combine(node& a,node& b)
{
    node temp;
    temp.sum = a.sum+b.sum;
    temp.pre = max(a.pre , a.sum+b.pre);
    temp.suf = max(b.suf , b.sum+a.suf);
    temp.mxm = max(a.mxm , max(b.mxm , a.suf+b.pre));
    return temp;
}
void upd(int i,ll x,int pos=1,int sl=0,int sr=n-1)
{
    if(sl==sr){
        st[pos] = {x,x,x,x};
        return;
    }
    int mid = (sl+sr)/2;
    if(i<=mid)
        upd(i,x,2*pos,sl,mid);
    else
        upd(i,x,2*pos+1,mid+1,sr);
    st[pos] = combine(st[2*pos],st[2*pos+1]);
}
ll qry()
{
    return st[1].mxm;
}
void solve()
{
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
        upd(i,a[i]);
    }
 
    while(q--)
    {
        int k,x;
        cin>>k>>x;
        k--;
        upd(k,x);
        ll ans = qry();
        if(ans<0)
            cout<<"0\n";
        else
            cout<<ans<<"\n";
    }
}
 
int main()
{
    fio;
    solve();
}
