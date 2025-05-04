#include<bits/stdc++.h>
using namespace std; 
 
#define FAST ios::sync_with_stdio(0);cin.tie(0)
#define deb(var) "[" << (#var) << " : " << var <<"] "
#define debv(v) "[" << (#v) << " : {";for(int i = 0; i < v.size() - 1; ++i)\
					cout << v[i] <<", ";cout << v.back() << "}] "
#define deba(a,n) "[" << (#a) << " : {";for(int i = 0; i < n - 1; ++i)\
					cout << a[i] << ", ";cout << a[n - 1] << "}] "
#define debp(p) "[" << (#p) << " : {" << p.first << ", " << p.second << "}] "
#define debs(s) "[" << (#s) << " : {";auto _itr = s.begin();\
					for(int k = s.size(); k > 1; --k) {cout << *_itr << ", "; ++_itr;} cout << *_itr << "}] "
#define debt(t) "[" << (#t) << " : " << "{" << get<0>(t) << ", " <<get<1>(t) << ", " << get<2>(t) << "}]"
/*LETS BEGIN WITH THE NAME OF LORD MAHADEV*/
using ll = long long;
 
int main(){
	FAST;
	int T;
	cin >> T;
	while(T--){
		int r, c;
		cin >> r >> c;
		ll mx = (ll)max(r, c);
		ll mn = (ll)min(r, c);
		if(mx & 1){
			if(r <= c){
				cout << (mx * mx) - (mn - 1) << endl;
			}else{
				cout << (mx - 1) * (mx - 1) + mn << endl;
			}
		}else{
			if(r <= c){
				cout << (mx - 1) * (mx - 1) + mn << endl;
			}else{
				cout << (mx * mx) - (mn - 1) << endl;
			}
		}
	}
	return 0;
}