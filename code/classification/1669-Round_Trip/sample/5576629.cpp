#include<bits/stdc++.h>
 
// ++++++++++++++++++++++++++++++++++++++++++++  @its_shyam640 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
/********************    Codeforces Header Files    *************************************/
 
// #include <atcoder/convolution>       
// // Convolution of two arrays is defined as C[i + j] = ∑(a[i] * b[j]) for every i and j
// using namespace atcoder;
 
 
 
using namespace std;
 
#define               li                        long int
#define               lf                        long float
#define               ld                        long double
#define               lli                       long long int
#define               llf                       long long float
#define               lld                       long long double
#define               usig                      unsigned
#define               sig                       signed
#define               def_mod                   1000000007
#define               infi                      1e18
#define               neg_infi                  -1e18
#define               endl                      "\n"
#define               vi                        vector<int>
#define               vc                        vector<char>
#define               vs                        vector<string>
#define               vlli                      vector<long long int> 
#define               vllf                      vector<long long float>
#define               vlld                      vector<long long double>
 
#define               pf                        push_front
#define               pb                        push_back
#define               ob                        pop_back
#define               of                        pop_front
 
 
#define               it(var)                   var.begin(),var.end()
#define               rit(var)                  var.rbegin(),var.rend()
#define               mid(left,right)           (left+(right-left)/2)
#define               fast_io                   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define               _print(x)                 cerr << #x << " = " << x << endl;
 
template <typename T> T _gcd(T a, T b){if(a%b) return _gcd(b,a%b);return b;}
template <typename T> T _lcm(T a, T b){return (a*(b/_gcd(a,b)));}
template <typename T, typename... Args> auto sum(T a, Args... args) { return a + sum(args...); }
template<typename T> bool comparator(pair<T,T>& a, pair<T,T>& b){return (a.second<b.second);}
bool all_Chars_Same(string s) {return (s.find_first_not_of(s[0]) == string::npos);}
 
 
const long double pi = atan2(0, -1);
string pi100 = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
 
 
class Debug{
   public:
      template <typename T> 
      void dbg(T var) {cerr << var;}
 
      // pair print
      template <class T, class V> 
      void dbg(pair <T, V> p) {cerr<< "pair = {"; dbg(p.first); cerr << ","; dbg(p.second); cerr << "}" << endl;}
 
      // vector print
      template <class T> 
      void dbg(vector <T> v) {cerr << "array = { "; for (T i : v) {dbg(i); cerr << " ";} cerr << "}" << endl;}
 
      // print set
      template <class T> 
      void dbg(set <T> v) {cerr << "set = [ "; for (T i : v) {dbg(i); cerr << " ";} cerr << "]" << endl;}
      
      // print map
      template <class T, class V> 
      void dbg(map <T, V> v) {cerr << "map = [ \n"; for (auto i : v) {dbg(i); cerr << endl;} cerr << "]" << endl;}
      
      // print unordered_map
      template <class T, class V> 
      void dbg(unordered_map <T, V> v) {cerr << "ump = [ "; for (auto i : v) {dbg(i); cerr << " ";} cerr << "]" << endl;}
      
      // print multiset
      template <class T> 
      void dbg(multiset <T> v) {cerr << "multiset = [ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]" << endl;}
};
 
 
/*###########################################       Usefull Functions          #############################################*/
 
/**************************** Check if number is prime or not   ********************************/
bool isPrime(lli n){auto count = 0;for(auto idx=1;(idx*idx)<=n;idx++){if((idx*idx)==n){count++;continue;}if(n%idx==0)count+=2;}if(count==2)return true;return false;}
 
 
/****************************** GENERATE PRIME FACTORS  ********************************/
map<lli,lli> primeFactors(lli n){ map<lli,lli> factors; while (n % 2 == 0) { factors[2]++; n = n/2; } for (int i = 3; i <= sqrt(n); i = i + 2) { while (n % i == 0) { factors[i]++; n = n/i; } } if (n > 2) factors[n]++; return factors; }
 
/****************************** GENERATE Factorial  *******************************/
string stringFactorial(lli n){ if (n>1000){ cout << " Integer Overflow"<< endl; return ""; } lli counter; unsigned long long int sum = 0; if (n == 0) return "1"; for (counter=1;counter<=n;counter++) sum = sum + log(counter); string result = to_string(round(exp(sum))); return result; }
 
lli moduloFactorial(lli n, lli p){if (n >= p) return 0; lli result = 1; for (lli i = 1; i <= n; i++) result = (result * i) % p; return result;}
 
 
/****************************** Generate Testcases **************************/
template <typename Container, typename T>  
void genTestArr(Container &arr, T pivot) { generate(arr.begin(), arr.end(), [&pivot]{ return (rand() % pivot); });}
 
/****************************** SORT MAP BY VALUE **************************/
lli inversions(vlli A) { lli N = A.size(); if (N <= 1) { return 0; } vector<pair<lli, lli>> sortList; lli result = 0; for (lli i = 0; i < N; i++) { sortList.emplace_back(A[i], i); push_heap(sortList.begin(), sortList.end()); } vector<lli> x; while (!sortList.empty()) { pair<lli, lli> v = sortList.front(); pop_heap(sortList.begin(), sortList.end()); sortList.pop_back(); lli y = lower_bound(x.begin(), x.end(), v.second) - x.begin(); result += v.second - y; x.insert(lower_bound(x.begin(), x.end(), v.second), v.second); } return result; }
 
 
/****************************** SORT MAP BY VALUE **************************/
void sortMapByValue(map<string, int>& M) { multimap<int, string> MM; for (auto& it : M) { MM.insert({ it.second, it.first }); } for (auto& it : MM) { cout << it.second << ' ' << it.first << endl; } }
 
 
/******** Getting GCD on subsegements ************/
// Like [0],[0,1],[0,2],[0,3]....,[0,n-1]
 
vector<map<lli,lli>> gcdOnSubsegments(vlli arr){ vector<map<lli, lli>> sub_gcd(arr.size()); /* Key is gcd, Value is the largest length such that gcd(a[i - len], ..., a[i]) equals to key. */ sub_gcd[0][arr[0]] = 0; for(lli i = 1; i < arr.size(); i++){ sub_gcd[i][arr[i]] = 0; for(auto it: sub_gcd[i - 1]){ lli new_gcd = __gcd(it.first, arr[i]); sub_gcd[i][new_gcd] = max(sub_gcd[i][new_gcd], it.second + 1); } } return sub_gcd; }
 
/********************  CREATE BINARY TREE *********************/
struct TreeNode{
    int data;
    TreeNode* left, * right;
};
 
 
TreeNode* newNode(int data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

template <typename T>
TreeNode* createTreeFromLOT(T arr,lli i, lli n){
   TreeNode *root = nullptr;
   if (i < n){
      root = newNode(arr[i]);
      root->left = createTreeFromLOT(arr,2 * i + 1, n);
      root->right = createTreeFromLOT(arr,2 * i + 2, n);
   }
   return root;
}
 
void displayTree(TreeNode* root){
   if (root != NULL){
      displayTree(root->left);
      cout << root->data<<" -> ";
      displayTree(root->right);
   }
}
 
void file_input_output(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
}
 
/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ SNIPPET ENDED $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
 
 
bool cycle(vlli adj[], vector<bool> &visited, lli node, lli parent, vlli &path){
   visited[node] = true;
   path.push_back(node);
   for(auto it : adj[node]){
      if(!visited[it]){
         if(cycle(adj, visited, it, node, path))
            return true;
      }else if(it != parent){
         path.push_back(it);
         return true;
      }
   }
   path.pop_back();
   return false;
}
 
 
int main(int argc, char const *argv[]) {
   clock_t begin = clock();
   Debug d;
   file_input_output();       // Taking file input and displaying output in output.txt
   // Write your code here....
   lli n,m;
   cin>>n>>m;
   vlli adj[n+1];
   lli u,v;
   for(lli i=0;i<m;i++){
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
 
   vector<bool> visited(n+1, false);
   for(lli i=1;i<=n;i++){
      if(!visited[i]){
         vlli path;
         if(cycle(adj, visited, i, -1, path)){
            lli i=0, j=path.size()-1;
            while(path[i]!=path[j]){
               i++;
            }
            cout<<j-i+1<<endl;
            for(lli k = i;k<path.size();k++)
               cout<<path[k]<<" ";
            cout<<endl;
            return 0;
         }
      }
   }
   cout<<"IMPOSSIBLE"<<endl;
 
 
 
   #ifndef ONLINE_JUDGE 
   clock_t end = clock();
   cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
   cout<<"Date : "<<__DATE__<< endl;
   cout<<"Time : "<<__TIME__<< endl;
   #endif 
   return 0;
}
 
 
 
 
 
/************ INTPUT *****************/
 
 
 
 
/************* OUTPUT *****************/
 
// 149
// 55686 94879 99904 97642 65585 94419 43661 85670 97780 99303 97786 25958 33198 15648 54510 84197 25068 56772 14436 43257 55679 51921 3430 91560 92944 98032 97115 59357 50133 55350 36754 88116 48453 1126 77225 75280 90518 76547 59088 94458 97528 65098 47240 22361 47324 4418 13408 33967 21479 62142 76178 93130 89129 78477 60275 91605 91673 88053 90959 83038 87158 97443 82310 85201 99054 93174 38537 55312 83296 75160 23829 38320 98710 80177 90916 53119 90988 78380 6696 13873 2851 94047 93055 97898 98976 89762 83908 55544 55026 31318 88739 81654 70661 74920 69288 66599 68153 69127 95371 84724 83465 40488 18254 8988 37217 40326 47818 13461 45705 50300 50510 42941 76439 80962 83946 87397 95135 84471 84650 84163 47430 69896 73434 81874 86078 43584 18922 72016 48859 43233 63595 77290 2318 19589 9708 76231 96558 76379 89830 78899 51714 76770 77754 57670 57056 64770 29257 43423 55686 
 
 
// 153
// 55686 94879 99904 97642 65585 94419 43661 85670 97780 99303 97786 25958 78118 33198 15648 54510 84197 25068 56772 14436 43257 55679 51921 3430 91560 92944 98032 97115 59357 50133 55350 46828 36754 88116 48453 1126 77225 75280 90518 76547 59088 94458 97528 65098 47240 22361 47324 4418 13408 5431 33967 21479 62142 76178 93130 89129 78477 60275 91605 91673 88053 90959 83038 87158 97443 82310 85201 99054 93174 38537 55312 83296 75160 23829 38320 98710 80177 90916 53119 32553 90988 78380 6696 13873 2851 94047 93055 97898 98976 89762 83908 55544 55026 31318 88739 81654 70661 74920 69288 66599 68153 69127 95371 84724 83465 40488 18254 8988 37217 40326 47818 13461 45705 50300 50510 42941 76439 80962 83946 87397 95135 84471 84650 84163 47430 69896 73434 81874 86078 43584 18922 72016 48859 43233 63595 77290 2318 19589 9708 76231 96558 76379 89830 78899 51714 76770 77754 57670 57056 64770 29257 43423 55686 
