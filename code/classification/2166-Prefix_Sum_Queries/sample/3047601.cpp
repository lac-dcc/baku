#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define openr() freopen("input.txt","r",stdin)
#define openw() freopen("output.txt","w",stdout)
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
typedef long long int ll;
const int inf=1e9;
const int maxn=200001;
 
 
struct node
{
    ll sum;
    ll pre;
};
 
vector<node>seg(maxn*4+5);
vector<ll>a(maxn);
 
void update(int l, int r, int pos, int id)
{
    if(id < l || id>r)  return;
    if(l==r)
    {
        seg[pos].sum=a[id];
        seg[pos].pre = max((ll)0,a[id]);
        return;
    }
    int mid = (l+r)/2;
    update(l,mid,2*pos,id);
    update(mid+1,r,2*pos+1,id);
    seg[pos].sum = seg[pos*2].sum + seg[pos*2+1].sum;
    seg[pos].pre = max(seg[pos*2].pre, seg[pos*2].sum + seg[pos*2+1].pre);
 
}
 
 
node tim(int q1,int q2, int l, int r, int pos)
{
    if(q1 > r || q2 < l)    return {0,0};
    if(q1<=l && r<=q2)  return seg[pos];
    int mid = (l+r)/2;
    node temp1 = tim(q1,q2,l,mid,pos*2);
    node temp2 = tim(q1,q2,mid+1,r,pos*2+1);
    node temp;
    temp.sum = temp1.sum + temp2.sum;
    temp.pre = max(temp1.pre, temp1.sum + temp2.pre);
    return temp;
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //openr();
    int n,q;  cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(1,n,1,i);
    }
    while(q--)
    {
        int type;   cin>>type;
        if(type ==1)
        {
            int k,u;    cin>>k>>u;
            a[k]=u;
            update(1,n,1,k);
        }
        else
        {
            int l,r;    cin>>l>>r;
            cout<<tim(l,r,1,n,1).pre<<"\n";
        }
    }
 
 
    return 0;
}
