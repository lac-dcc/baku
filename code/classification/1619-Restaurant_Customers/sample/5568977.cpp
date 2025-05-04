        #include "bits/stdc++.h"
#define filei {freopen("c_c++_intput.txt", "r", stdin);}
#define fileo {freopen("c_c++_output.txt", "w", stdout);}
 
#define FIO  { ios::sync_with_stdio(false);cin.tie(0);}
 
// #define int long long
//#define ll long long
//__builtin_popcount
//cerr
#define mod 1000000007
#define amax 1000005
 
using namespace std ;
 
// int arr [200020]; 
 
signed main ()
{
    // filei
    // fileo
    FIO
    int t;
    cin >> t;
    vector <pair <int,int>>vpii; 
    set <int>si; 
    for (int loop = 1; loop <= t; loop++)
    {
        int a, b; 
        cin >> a >> b; 
        vpii.push_back ({a,b});
        si.insert (a); 
        si.insert (b);  
    }
    unordered_map <int,int>mii;
    int idx = 0;  
    for (auto u : si)
    {
        mii [u] = idx; 
        idx++;  
    }
    // int arr [200016]; 
 
 
 
    map <int,int>mii2;
    int prev = 0; 
    int ma = 0;
    for (auto u : vpii)
    {
        mii2 [mii [u.first]] = 1; 
        mii2 [mii [u.second]] = -1; 
        ma = max (ma,u.first); 
        ma = max (ma,u.second);
    }
    int ma2 = 0; 
    for (auto &u : mii2)
    {
        // ma2 = u.second; 
        ma2 = max (u.second,ma2); 
        u.second += prev; 
        prev = u.second;
        ma2 = max (prev,ma2) ;  
    }
    mii2 [ma] += prev; 
    prev = mii2 [ma]; 
   //  int ma2 = 0; 
 
   // for (auto u : mii2)
   // {
   //  ma2 = max (u.second,ma2); 
   // }
   cout << max(prev,ma2) << "\n"; 
 
}
 
 
 
