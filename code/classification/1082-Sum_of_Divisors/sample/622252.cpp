#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) ((int)a.size())
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define forse(i, s, e) for (int i = (int)s; i < (int)e; i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
using dbl = double;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
dbl PI = 3.141592653589793;
 
//Modular arithmetic
template<int P>
class Modular{
	public:
		static int init_siz;
		static vector<Modular> inverse,factorial;
		int n=0;
		static Modular exp(Modular a, long long e) {
			Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
			return res;
		}
		static void init(int n){
			init_siz=n;
			inverse.resize(n+1);factorial.resize(n+1);
			factorial[0] = 1;
			for (int i = 1; i <= n; i++) factorial[i] = factorial[i - 1] * i;
			inverse[n]=exp(factorial[n],P-2);
			for (int i = n-1; i>=0; i--) inverse[i] = inverse[i+1] * (i+1);
		}
		static Modular inv(Modular const& a){
			assert(a.n!=0);
			return (init_siz>=a.n? inverse[a.n]*fac(a-1):exp(a,P-2));
		}
		static Modular cinv(Modular const& a){
			return (init_siz>=a.n? inverse[a.n]:exp(fac(a),P-2));
		}
		static Modular fac(Modular const& a){
			if(init_siz>=a.n) return factorial[a.n];
			else{
				Modular out=1;
				for(int i=0;i<a.n;i++) out*=(i+1);
				return out;
			}
		}
		Modular(long long val = 0) {n=val%P;if(n<0) n+=P;}
		Modular& operator+=(Modular const& b) {n += b.n; if (n >= P) n -= P; return *this;}
		Modular& operator-=(Modular const& b) {n -= b.n; if (n < 0) n += P;return *this;}
		Modular& operator*=(Modular const& b) {n = (long long)n * b.n % P;return *this;}
		Modular exp(long long e) {return exp(*this,e);}
		Modular inv(){return inv(*this);}
		Modular& operator/=(Modular const& b){ return *this *=inv(b);}	
		friend std::ostream& operator<<(std::ostream& os,Modular const& a){return os<<a.n;}
		friend Modular operator+(Modular a, Modular const b) { return a += b; }
		friend Modular operator-(Modular a, Modular const b) { return a -= b; }
		friend Modular operator-(Modular const a) { return 0 - a; }
		friend Modular operator*(Modular a, Modular const b) { return a *= b; }
		friend Modular operator/(Modular a, Modular const b) { return a /= b; }
		friend bool operator==(Modular const& a, Modular const& b) {return a.n == b.n;}
		friend bool operator!=(Modular const& a, Modular const& b) {return a.n != b.n;}
};
template<int P> int Modular<P>::init_siz=-1;
template<int P> vector<Modular<P>> Modular<P>::factorial;
template<int P> vector<Modular<P>> Modular<P>::inverse;
template<int P> string to_string(Modular<P> b) { return to_string(b.n);}
const int P=1e9+7;
typedef Modular<P> mint;
 
 
mint get(mint i,mint j){
	return ((i*(i+1))-(j*(j+1)))/2;
}
 
void solve() {
	ll n;
	cin >> n;
	mint out=0;
	for(ll i=n;i>0;){
		ll j=(n/((n/i)+1));
		out+=(n/i)*get(i,j);
		i=j;
	}
	cout << out;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
	for (int c = 1; c <= T; c++) {
		solve();
	}
}
