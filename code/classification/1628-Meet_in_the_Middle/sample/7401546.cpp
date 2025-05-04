#include <bits/stdc++.h>
 
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn = 1e5+5;
const int mxm = 1e5+5;
const int MOD = 1e9+7;
 
struct custom_hash{
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x^=FIXED_RANDOM;
        return x^(x >> 16);
    }
};
 
int n, x, v1[22], v2[22];
ll resp;
unordered_map<int, int, custom_hash> freq;
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> x;
    int mid = n/2;
    if(n&1){
        mid++;
    }
    for(int i=0; i<mid; i++){
        cin >> v1[i];
    }
    for(int i=0; i<n/2; i++){
        cin >> v2[i];
    }
    freq.reserve(1e7);
    freq[0]=1;
    for(int i=1; i<(1<<mid); i++){
        ll soma=0;
        for(int j=0; j<mid; j++){
            if(i&(1<<j)) soma+=v1[j];
        }
        if(soma>x) continue;
        freq[soma]++;
    }
    resp+=freq[x];
    for(int i=1; i<(1<<(n/2)); i++){
        ll soma=0;
        for(int j=0; j<(n/2); j++){
            if(i&(1<<j)) soma+=v2[j];
        }
        if(soma>x) continue;
        if(freq.count(x-soma)) resp+=freq[x-soma];
    }
    cout << resp << endl;
    return 0;
}
