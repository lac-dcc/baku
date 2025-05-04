#include<bits/stdc++.h>
using namespace std ;
# define int long long
#define endl '\n'
const int N=200005 ;
int n,q ;
int ara[N] ;
struct node
{
        int sum ;
        int prif ;
        int suff ;
        int ans ;
} ;
 
node seg[4*N] ;
 
node combine(node a, node b)
{
        node temp ;
 
        temp.sum=a.sum+b.sum ;
        temp.prif=max(a.prif,a.sum+b.prif) ;
        temp.suff=max(b.suff,b.sum+a.suff) ;
        temp.ans=max(a.ans,b.ans) ;
        temp.ans=max(temp.ans,a.suff+b.prif);
 
       
 
return temp ;
}
 
 
void build(int vertex, int b, int e)
{
        if(b==e)
        {
               seg[vertex].sum=ara[b] ;
               seg[vertex].prif=max(ara[b],0ll) ;
               seg[vertex].suff=max(ara[b],0ll) ;
               seg[vertex].ans=max(ara[b],0ll) ;
                return ;
        }
        int left=2*vertex ;
        int right=left+1;
        int mid=(b+e)/2 ;
 
        build(left,b,mid) ;
        build(right,mid+1,e);
        
        seg[vertex]=combine(seg[left],seg[right]) ;
}
 
void update(int vertex, int b, int e, int pos, int val)
{
 
        if(e==b)
        {
                seg[vertex].sum+=val ;
                ara[b]+=val ;
                seg[vertex].prif=max(ara[b],0ll) ;
                seg[vertex].suff=max(ara[b],0ll) ;
                seg[vertex].ans=max(ara[b],0ll) ;
                return ;
        }
        int left=2*vertex ;
        int right=left+1;
        int mid=(b+e)/2 ;
        if(pos<=mid)update(left,b,mid,pos,val) ;
        else update(right,mid+1,e,pos,val);
        seg[vertex]=combine(seg[left],seg[right]) ;
}
 
 
 
 
 
void pro()
{
        cin >> n >> q ;
        for(int i=1; i<=n; i++) cin >> ara[i] ;
        build(1,1,n) ;
        
        while(q--)
        {
                int a, b ;
                cin >> a >> b ;
                update(1,1,n,a,(-ara[a]+b)) ;
                cout << seg[1].ans    << endl;
        }
        
}
 
int32_t main()
{
 
        ios_base :: sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
        
                
        pro() ;
        
 
        return 0;
}
 
