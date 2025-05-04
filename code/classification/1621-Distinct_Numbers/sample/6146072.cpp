//designed by Nrutas
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define endl '\n'
#define fori for(ll i=0; i<n; i++)
#define fork for(ll k=0; k<n; k++)
#define fors for(ll i=0; i<s.size(); i++)
#define forv for(ll i=0; i<v.size(); i++)
#define sorta sort(a,a+n)
#define rvsa reverse(a,a+n)
#define sorts sort(s.begin(), s.end())
#define rvss reverse(s.begin(), s.end())
#define sortv sort(v.begin(), v.end())
#define rvsv reverse(v.begin(), v.end())
#define prcs cout.precision
#define str string
#define gets getline(cin,s)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pair pair<int,int>
#define vct vector
#define fst first
#define snd second
#define hurryupnrutas ios_base::sync_with_stdio(false);cin.tie();cout.tie()
int main()
{
    ll n,a;
    cin>>n;
    set<ll>v;
    fori
    {
        cin>>a;
        v.insert(a);
    }
    n=0;
    cout<<v.size();
}
