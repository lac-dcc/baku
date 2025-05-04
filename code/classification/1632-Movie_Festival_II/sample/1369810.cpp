#include <bits/stdc++.h>
#define ll long long
const ll M = 1e5 + 10;
#define nd second
#define st first
using namespace std;
 
vector < pair<ll , ll> > a;
multiset < ll , greater< ll > > s;
ll n , m , res = 1 , x;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    cin>>n>>x;
    for(int i = 0 ; i < n ; i++)
    {
        ll k , l;
        cin>>k>>l;
        a.push_back({l , k});
    }
 
    sort(a.begin() , a.end());
    s.insert(a[0].st);
    for(int i = 0 ; i < x - 1; i++)
        s.insert(0);
 
    for(int i = 1 ; i < n ; i++)
    {
        ll val = a[i].nd;
        multiset< ll >::iterator it = s.lower_bound(val);
        if((*it)==s.size())
		{
            if((*it) <= val and s.find(val) != s.end())
            {
                s.erase(it);
                s.insert(a[i].st);
                res++;
            }
		}
        else
		{
			s.erase(it);
			s.insert(a[i].st);
			res++;
		}
    }
    cout<<res;
    return 0;
}