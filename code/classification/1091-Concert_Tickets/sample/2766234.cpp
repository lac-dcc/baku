/*
 
 
 
Link :
 
Algorithm/Basic Idea : 
 
*/
 
#include<bits/stdc++.h>
#define ll long long
 
using namespace std;
 
void solve()
{
    ll N,M;
    cin>>N>>M;
    map<ll,ll> prices;
    vector<ll> max_prices;
    ll a;
    for(ll i=0;i<N;i++)
    {
        cin>>a;
        prices[a]++;
    }
 
    ll max_price;
    for(ll i=0;i<M;i++)
    {
        cin>>max_price;
        max_prices.push_back(max_price);
    }
    for(auto max_price:max_prices)
    {
        
        auto it=prices.upper_bound(max_price);
        if(it==prices.begin())
        {
            cout<<"-1"<<"\n";
        }
        else
        {
            it--;
            cout<<it->first<<"\n";
            ll val=it->first;
            prices[val]--;
            if(prices[val]==0)
            {
                prices.erase(val);
            }
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
}
