/*  Author: Tarun Kumar
    E-mail: tarunkumar281200@gmail.com
 
    Don't stop until you feel proud.(P.S. don't feel proud;)
*/#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll int
#define ld long double
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define prqueue priority_queue<ll,vector<ll>,greater<ll>>// top=small
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)
#define fab(i,a,b) for(i=a;i<=b;i++)
#define f0r(i,n) for(i=n-1;i>=0;i--)
#define f1r(i,n) for(i=n;i>=1;i--)
#define fabr(i,a,b) for(i=b;i>=a;i--)
#define memo(a,b) memset(a,b,sizeof(a))
#define display(x) {for(auto dsp:x)cout<<dsp<<" ";cout<<"\n";}
#define hi cout<<"hi\n"
#define ln "\n"
using namespace std;
const ld pi=acos(-1);const ll mod=1e9+7;
 
int main()
{FAST;ll t,n,i,j,k,len,x,y,z,c,f,flag,p,q,mx,mn,l,r,sum,ans,tmp,it,pos,avg,m,cnt;
    string s;char ch;vll v;vpll vec;map<ll,ll> mappu;pair<ll,ll> pr;
    t=1;
    // cin>>t;while(t--)
    {
        f=0;sum=0;flag=0;ans=0;cnt=0;v.clear();mappu.clear();vec.clear();
        cin>>n>>x;
        ll a[n];
        map<ll,vll>adj;
        f0(i,n)
        {
            cin>>tmp;
            a[i]=tmp;
            mappu[tmp]++;
            adj[tmp].pb(i+1);
        }
        
        sort(a,a+n);
        f0(i,n)
        {
        	l=a[i];
            r=x-a[i];
            
            if(l==r)
            {
            	if(mappu[l]<2)
            	continue;
            	
            	cout<<adj[l].back()<<" ";
            	adj[l].ppb();
            	cout<<adj[l].back();
            	adj[l].ppb();
            	
            	return 0;
            }
            
            if(!mappu[l] or !mappu[r])
            continue;
            
            cout<<adj[l].back()<<" "<<adj[r].back();
            return 0;
        }
        
        cout<<"IMPOSSIBLE"<<ln;
    }
	return 0;
}
// Just keep going, no feeling is final