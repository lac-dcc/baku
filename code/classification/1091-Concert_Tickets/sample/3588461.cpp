#include <bits/stdc++.h>
#define ll long long
#define node tuple<int,int>
#define pi 3.14159265359
#define inf 1e9
#define oo 1e18+8
#define log(x , y) log10(y)/log10(x)
#define memset(t , x)  memset(t , x , sizeof t)
#define fill(t , x) fill(t , t+(sizeof t/4) , x)
#define nax (int)(1e6+6)
#define MOD (int)(1e9+7)
#define left p<<1 , l , (l+r)>>1
#define right p<<1|1 , ((l+r)>>1)+1 , r
#define A(a,n) int a[n];    for(int i=0;i<n;i++)    cin>>a[i];
#define AA(a,n) ll a[n];    for(int i=0;i<n;i++)    cin>>a[i];
#define S(s) string s  ; cin>>s;
#define comma(ans,n)    setprecision(n)<<fixed<<ans<<endl;
#define coutt(x)     printf("%d\n", x);
#define Endl    endl
#define sortt(a)    sort(a.begin(),a.end())
#define binary(x,n)     std::string str = std::bitset<n>(x).to_string()
#define line            cout<<endl<<"-------------------------------"<<endl
using namespace std;
//#include "debug.cpp"
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        map <int,int> mp;
        set <int> st;
        vector <int> b(m);
        for(int i=0;i<n;i++){
            int x; cin>>x;
            mp[x]++;
            st.insert(x);
        }   
        for(int i=0;i<m;i++)    cin>>b[i];
        for(int i=0;i<m;i++){
            if(st.size() > 0){
                auto it = st.upper_bound(b[i]);
                if(it == st.begin()  &&  *it > b[i])    cout<<-1<<endl;
                else{
                    it--;
                    cout<<*it<<endl;
                    mp[*it]--;
                    int x = mp[*it];
                    if(x == 0)  st.erase(it);
                }
            }
            else    cout<<-1<<endl;
            // line;
        }
    }       
    return 0;
}
