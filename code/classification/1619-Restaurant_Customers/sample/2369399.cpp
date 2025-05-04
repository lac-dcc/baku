#include<bits/stdc++.h>
 
using namespace std;
 
 
 
 
void solve();
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef double db;
typedef char ch;
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define mpch map<ch, ll>
#define vll vector<ll>
#define vpll vector<pll>
#define str string
#define si size()
typedef char ch;
#define be begin()
#define en end()
#define vs vector<string>
#define vc vector<char>
#define ppi pair<int,pair<int,int>
#define minh  priority_queue <int, vector<int>, greater<int> >
#define min_pair  priority_queue <ppi, vector<ppi>, greater<ppi> >
#define maxh  priority_queue <int>
#define max_pair  priority_queue <ppi>
#define sll set<ll>
#define loop(i,n) for(int i = 0; i < n; ++i)
#define pi 3.14159265358979323846264338327
#define nope string::npos
#define max2(a,b) ((a<b)?b:a)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a>b)?b:a)
#define min3(a,b,c) min2(min2(a,b),c)
 
 
 
/*..............................................................................................................................
 
							Ashish Ranjan
 
...............................................................................................................................*/
 
 
 
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
 
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
 
 
/*.......................................................................................................*/
 
 
int main(){
 
	#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
	#endif
 
    fast();
 
 
    // int tc;
    // cin>>tc;
    // while(tc--){
    // 	solve();
    // }
 
    solve();
 
	cout<<"\n";
	return 0;
}
 
/*#################################################################################
 
					श्रीगुरु चरन सरोज रज, निज मनु मुकुरु सुधारि।
					बरनऊं रघुबर बिमल जसु, जो दायकु फल चारि।।
					बुद्धिहीन तनु जानिके, सुमिरौं पवन-कुमार।
					बल बुद्धि बिद्या देहु मोहिं, हरहु कलेस बिकार।।	
 
##################################################################################*/
 
 
 
 
 
 
 
 
 
 
 
// void solve(){
// 	ll n;
// 	cin>>n;
// 	vpll v(n);
// 	for(int i=0;i<n;i++){
// 		cin>>v[i].first>>v[i].second;
// 	}
// 	sort(v.begin(),v.end());
// 	debug(v);
 
// 	ll ans=1,temp=1, x=v[0].first,y=v[0].second;
 
// 	for(int i=1;i<n;i++){
// 		ll enter=v[i].first, exit=v[i].second;
// 		if(y>=enter){
// 			temp++;
// 			ans=max(temp,ans);
// 		}
// 		else
// 		{
// 			temp=1;
// 			y=exit;
// 		}
// 	}
// 	cout<<ans<<"\n";
 	
// }
 
 
 
// 3
// 8
// -1
 
 
 
 
 
void solve(){
	
	ll n, ans=0,temp=0;
	cin>>n;
	vpll v;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,1});
		v.push_back({b,-1});
	}
	sort(v.begin(), v.end());
	for(auto x:v){
		temp+=x.second;
		ans=max(ans,temp);
	}
	cout<<ans<<'\n';
 	
}
 
 
 
 
 
 
 
 
 
 
 
 
/*#################################################################################
 
						जय हनुमान ज्ञान गुन सागर।
						जय कपीस तिहुं लोक उजागर।।
 
						रामदूत अतुलित बल धामा।
						अंजनि-पुत्र पवनसुत नामा।।
 
						महाबीर बिक्रम बजरंगी।
						कुमति निवार सुमति के संगी।।
 
						कंचन बरन बिराज सुबेसा।
						कानन कुंडल कुंचित केसा।।
						हाथ बज्र औ ध्वजा बिराजै।
						कांधे मूंज जनेऊ साजै।
 
						संकर सुवन केसरीनंदन।
						तेज प्रताप महा जग बन्दन।।
 
						विद्यावान गुनी अति चातुर।
						राम काज करिबे को आतुर।।
 
 
						प्रभु चरित्र सुनिबे को रसिया।
						राम लखन सीता मन बसिया।।
						सूक्ष्म रूप धरि सियहिं दिखावा।
						बिकट रूप धरि लंक जरावा।।
 
						भीम रूप धरि असुर संहारे।
						रामचंद्र के काज संवारे।।
 
						लाय सजीवन लखन जियाये।
						श्रीरघुबीर हरषि उर लाये।।
 
						रघुपति कीन्ही बहुत बड़ाई।
						तुम मम प्रिय भरतहि सम भाई।।
						सहस बदन तुम्हरो जस गावैं।
						अस कहि श्रीपति कंठ लगावैं।।
 
						सनकादिक ब्रह्मादि मुनीसा।
						नारद सारद सहित अहीसा।।
 
						जम कुबेर दिगपाल जहां ते।
						कबि कोबिद कहि सके कहां ते।।
 
						तुम उपकार सुग्रीवहिं कीन्हा।
						राम मिलाय राज पद दीन्हा।।
						तुम्हरो मंत्र बिभीषन माना।
						लंकेस्वर भए सब जग जाना।।
 
						जुग सहस्र जोजन पर भानू।
						लील्यो ताहि मधुर फल जानू।।
 
						प्रभु मुद्रिका मेलि मुख माहीं।
						जलधि लांघि गये अचरज नाहीं।।
 
						दुर्गम काज जगत के जेते।
						सुगम अनुग्रह तुम्हरे तेते।।
						राम दुआरे तुम रखवारे।
						होत न आज्ञा बिनु पैसारे।।
 
						सब सुख लहै तुम्हारी सरना।
						तुम रक्षक काहू को डर ना।।
 
						आपन तेज सम्हारो आपै।
						तीनों लोक हांक तें कांपै।।
 
						भूत पिसाच निकट नहिं आवै।
						महाबीर जब नाम सुनावै।।
						नासै रोग हरै सब पीरा।
						जपत निरंतर हनुमत बीरा।।
 
						संकट तें हनुमान छुड़ावै।
						मन क्रम बचन ध्यान जो लावै।।
 
						सब पर राम तपस्वी राजा।
						तिन के काज सकल तुम साजा।
 
						और मनोरथ जो कोई लावै।
						सोइ अमित जीवन फल पावै।।
						चारों जुग परताप तुम्हारा।
						है परसिद्ध जगत उजियारा।।
 
						साधु-संत के तुम रखवारे।
						असुर निकंदन राम दुलारे।।
 
						अष्ट सिद्धि नौ निधि के दाता।
						अस बर दीन जानकी माता।।
 
						राम रसायन तुम्हरे पासा।
						सदा रहो रघुपति के दासा।।
						तुम्हरे भजन राम को पावै।
						जनम-जनम के दुख बिसरावै।।
 
						अन्तकाल रघुबर पुर जाई।
						जहां जन्म हरि-भक्त कहाई।।
 
						और देवता चित्त न धरई।
						हनुमत सेइ सर्ब सुख करई।।
 
						संकट कटै मिटै सब पीरा।
						जो सुमिरै हनुमत बलबीरा।।
						जै जै जै हनुमान गोसाईं।
						कृपा करहु गुरुदेव की नाईं।।
 
						जो सत बार पाठ कर कोई।
						छूटहि बंदि महा सुख होई।।
 
						जो यह पढ़ै हनुमान चालीसा।
						होय सिद्धि साखी गौरीसा।।
 
						तुलसीदास सदा हरि चेरा।
						कीजै नाथ हृदय मंह डेरा।।
 
##################################################################################*/
 
