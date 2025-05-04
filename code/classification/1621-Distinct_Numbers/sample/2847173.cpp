#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<long long> vl;
typedef vector< vector<long long> > vvl;
 
template<typename T>
ostream& operator<<(ostream& out, const vector<T> &v){
    out << "Size: " << v.size();
    out << " [ ";
    for(int i = 0; i < v.size(); i++){
        out << v[i];
        if(i != v.size() - 1)
            out << ", ";
    }
    out << " ]" << endl;
    return out;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> s;    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(x);
    }
    cout << (int)s.size() << endl;
}