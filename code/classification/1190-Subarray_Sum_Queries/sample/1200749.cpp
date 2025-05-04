#define mod 1000000007
#include<bits/stdc++.h>
using namespace std;
 
int n ,m ,t ,x ,y;
struct ii
{
    long long l ,r ,v ,s;
};
ii it[800005];
 
ii ma ( ii a, ii b )
{
    ii res;
    res.l = max( a.l ,a.s + b.l );
    res.r = max( b.r ,b.s + a.r );
    res.s = a.s + b.s;
    res.v = max( a.r+b.l ,max( a.v ,b.v ));
    return res;
}
 
void update( int l ,int r ,int id ,int vt ,int gt )
{
    if( l > vt || r < vt ) return;
    if( l == r )
    {
        it[id] = {gt ,gt ,gt ,gt};
        return;
    }
    int mid = (l+r)/2;
    update(l ,mid ,id*2 ,vt ,gt);
    update(mid+1 ,r ,id*2+1 ,vt ,gt);
    it[id] = ma( it[id*2] ,it[id*2+1] );
}
 
void xl()
{
    cin >> n >> m;
    for( int i = 1 ; i <= n ;i++ )
    {
        cin >> x;
        update(1 ,n ,1 ,i ,x);
    }
 
    for( int i = 1 ; i <= m ;i++ )
    {
        cin >> x >> y;
        update(1 ,n ,1 ,x ,y);
        cout<<max(it[1].v ,0ll)<<'\n';
    }
}
 
int main()
{
    //freopen("CT.inp" ,"r" ,stdin);
    //freopen("CT.out" ,"w" ,stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    t = 1;
    //cin>>t;
    while( t-- )
    {
        xl();
    }
    return 0;
}
