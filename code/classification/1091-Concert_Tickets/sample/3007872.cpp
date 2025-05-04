// $ Author @CAP_10
#include<bits/stdc++.h>
#include<ctime>
#include<chrono>
using namespace std;
// $ Just believe in yourself
 
 
 
//@ Defining the the shortcuts for long words
#define ll long long
#define ld long double
#define ar array
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define pop pop_back 
#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
 
 
//@ Defining all types of for loops 
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
 
 
 
//@ Converting to strings
 
//< Converting char to string
string to_string(char c) {
	return string(1, c);
}
 
//< Converting bool to string
string to_string(bool b) {
	return b?"true":"false";
}
 
//< Converting char array to string
string to_string(const char* s) {
	return string(s);
}
 
//< Just returning string if given input is string
string to_string(string s) {
	return s;
}
 
//< Bool array to string
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}
 
//< Converts bitset to a string
template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
 
//< Converts any array or set into string(Just for debug)
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}
 
 
 
//@ This is custom min and max functions which work for all data types
 
//< MIN
template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
 
//< MAX
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
} 
 
 
//@ Returning random integer
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}
 
 
//@ Directions
//< Graph 4 direction
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
 
//< Graph 8 direction
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
 
 
 
//@ This is for reading section
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
 
//< Reading double
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
 
//< Reading long double
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
 
//< Reading multiple inputs
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
 
//< Reading vectors
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
 
//< Reading array
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}
 
//@ Initializing
//< Intializing vector
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
	v=vt<T>(n, x);
}
 
//< Initializing 2-D vector
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
	v=vt<T>(n);
	EACH(a, v)
		vti(a, x, m);
}
 
 
//@ Binary Search func
//< Binary search function for lower
ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1; 
	} 
	return lb;
}
 
//< Binary search function for upper
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		f(mb)?lb=mb:rb=mb-1; 
	} 
	return lb;
}
 
 
//@ Offset
//< Offset funtion
template<class T> void offset(ll o, T& x) {
	x+=o;
}
 
//< Offset funtion vector
template<class T> void offset(ll o, vt<T>& x) {
	EACH(a, x)
		offset(o, a);
}
 
//< Offset funtion array
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	EACH(a, x)
		offset(o, a);
}
 
//@===================== The Stuff I Don't Know =========================
//<--------------------- Need To Explore --------------------------------
 
template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
 
void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 
//<=============================================================================
 
// @==================================== Write The Useful Code Here ============================
 
// @Make it one if there is some test cases
bool TESTCASES = 0;  // @=====================
// @ =======================================
 
// $  Goal - CM
 
//* Write the binary search function here 
bool binfunc(){
    return 1;
}
 
struct Node{
 
};
 
void solve(){
    
    int n,m;
    read(n,m);
    multiset<int> has;
    int val;
    FOR(n){
        cin>>val;
        has.insert(val);
    }
 
    FOR(m){
        cin>>val;
        auto poi=has.upper_bound(val);
        if(poi==has.begin()){
            cout<<-1<<"\n";
            continue;
        }
        --poi;
        int res=*poi;
        poi=has.find(res);
        cout<<res<<"\n";
        has.erase(poi);
    }
        
 
}
 
 
// < This is the Main Function
int main()
{   
    bool FLAG=0;
    auto start = std::chrono::system_clock::now();
 
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
 
    //< Checking we are offline or not
    #ifndef ONLINE_JUDGE
        freopen("cppinput.txt", "r", stdin);
        freopen("cppoutput.txt", "w", stdout);
        FLAG=1;
    #endif
 
 
    int T=1;
 
    if (TESTCASES)
        cin>>T;
 
    while(T--)
        solve();
    
    if(FLAG){
        auto end = std::chrono::system_clock::now();
        cout<<"\n";
        cout<<"THIS IS A CPP OUTPUT FILE"<<endl;
        chrono::duration<double> elapsed_seconds = end-start;
        time_t end_time = std::chrono::system_clock::to_time_t(end);
        cout<< "TIME: " << elapsed_seconds.count() << " sec\n";
        cout << ctime(&end_time);
    }
    return 0;
}
