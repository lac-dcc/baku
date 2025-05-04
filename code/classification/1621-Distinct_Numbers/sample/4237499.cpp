#include<bits/stdc++.h>
using namespace std;
#define int long long  
#define pb push_back
#define sq(a) (a) * (a) 
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int mod = pow(10,9) + 7 ; 
int32_t main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    int n; 
    cin >> n; 
    int x; 
    set<int> st ;
    for(int i = 0 ;i < n ; i++ )
    {
        cin >> x; 
        st.insert(x) ; 
    }
    cout << st.size() << endl ;
    return 0;
}
