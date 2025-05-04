#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define pb push_back
#define fr first
#define sd second
#define mp make_pair
#define bg begin()
#define en end()
 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define ppiipii pair<pii, pii>
#define pipii pair<int, pii>
#define vpii vector<pair<int, int>>
#define fi(var, initial, final, update) for(ll var=initial;var<final;var+=update)
#define f(n) for(ll i=0;i<n;i++)
#define frev(n) for(ll i=n;i>=0;i--)
#define fe(s) for(auto i: s)
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
bool equal(pipii a, pipii b){
    return a.sd.fr==b.sd.fr || a.sd.fr==b.sd.sd || a.sd.sd==b.sd.fr || a.sd.sd==b.sd.sd;
}
 
int main(){
    ll n, x;
    cin>>n>>x;
    vll v(n);
    f(n) cin>>v[i];
    vector<pipii> sum;
    f(n){
        fi(j, i+1, n, 1){
            sum.pb({v[i]+v[j], {i, j}});
        }
    }
    sort(sum.bg, sum.en);
    // fe(sum){
    //     cout<<i.fr<<" : "<<i.sd.fr<<" "<<i.sd.sd<<endl;
    // }
    ll l=0,r=sum.size()-1;
    ll a=-1, b, c, d;
    while(l<r){
        // cout<<"Loop:::"<<sum[l].fr<<" "<<sum[r].fr<<endl;
        if(sum[l].fr + sum[r].fr<x)
            l++;
        if(sum[l].fr + sum[r].fr>x)
            r--;
        if(sum[l].fr + sum[r].fr==x){
            // cout<<"IN:::"<<l<<" "<<r<<endl;
            if(!equal(sum[l], sum[r])){
                tie(a, b) = sum[l].sd;
                tie(c, d) = sum[r].sd;
                break;
            }else{
                if(sum[l].fr==sum[l+1].fr)
                    l++;
                else if(sum[r].fr==sum[r-1].fr)
                    r--;
                else
                    l++, r--;
            }
        }
    }
    if(a!=-1)
        cout<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    
    return 0;
}