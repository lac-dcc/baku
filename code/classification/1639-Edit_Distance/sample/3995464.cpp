#include <bits/stdc++.h>
using namespace std;
 
// Define Template          Python++
// Math
const int mod = 1e9+7;
// const int INF = INT32_MAX;
// const long long INF = LLONG_MAX;
#define updatemax(var,val)  var=max(var,val);
#define updatemin(var,val)  var=min(var,val);
#define intlen(num)         to_string(num).size()
// Data Structure and Algorithm
#define all(vec)            vec.begin(),vec.end()
#define arrsize(arr)        sizeof(arr)/sizeof(int)
#define sortarr(arr)        sort(arr,arr+arrsize(arr));
#define sortvec(vec)        sort(all(vec));
#define minarr(arr)         *min_element(arr,arr+arrsize(arr))
#define minvec(vec)         *min_element(all(vec))
#define maxarr(arr)         *max_element(arr,arr+arrsize(arr))
#define maxvec(vec)         *max_element(all(vec))
#define sumarr(arr)         accumulate(arr,arr+arrsize(arr),0)
#define sumvec(vec)         accumulate(all(vec),0)
#define reversearr(arr)     reverse(arr,arr+arrsize(arr));
#define reversevec(vec)     reverse(all(vec));
#define range(i,s,e)        for(int i=s;i<e;i++)
#define range2(i,s,e)       for(int i=s;i>=e;i--)
#define append(var)         push_back(var);
#define len(arr)            arr.size()
#define member(DS,val)      (DS.find(val)!=DS.end())
#define countmap(mp,arr)    for(auto tmp:arr)mp[tmp]++;
// Input Output Manage
#define fileread            freopen("input.txt","r",stdin);
#define fileout             freopen("output.txt","w",stdout);
#define query               int QUERY;cin>>QUERY;while(QUERY--)
#define inputarr(arr,am)    int arr[am];for(int &num:arr)cin>>num;
#define inputvec(vec,am)    vector<int> vec(am);for(int &num:vec)cin>>num;
#define inputline(var)      getline(cin,var);
#define input(var)          int var;cin>>var;
#define inputs(var)         string var;cin>>var;
#define print(var)          cout<<var<<endl;
#define print2(var1,var2)   cout<<var1<<" "<<var2<<" ";
#define print2l(var1,var2)  cout<<var1<<" "<<var2<<endl;
#define printp(paired)      cout<<paired.first<<" "<<paired.second<<" ";
#define printpl(paired)     cout<<paired.first<<" "<<paired.second<<endl;
#define prints(var)         cout<<var<<" ";
#define printyes(cond)      cout<<(cond?"YES":"NO")<<endl;
#define printarr(arr)       for(auto num:arr){cout<<num<<" ";};cout<<endl;
#define printmap(hashmap)   for(auto container:hashmap)cout<<container.first<<" : "<< container.second<<endl;
#define endline             cout<<endl;
 
 
 
int stringedit(string word, string target){
    // calculating the number of string editing we should do
    // to change word into the target word
    // with just insert, remove, and modify operation
    // Time Complexity : O(n^2)
    const int inf = 1e9;
    // DP dimension
    int n = word.size() + 1;
    int m = target.size() + 1;
    //int dp[n][m]={};
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // fill first row and collumn 
    for(int i=1;i<n;i++)dp[i][0]=dp[i-1][0]+1;
    for(int j=1;j<m;j++)dp[0][j]=dp[0][j-1]+1;
    
    // DP approach for all position
    for(int i=1;i<n;i++)for(int j=1;j<m;j++){
        dp[i][j] = min(
            dp[i][j-1] + 1,min( // insert character
            dp[i-1][j] + 1, // remove character
            dp[i-1][j-1] + (word[i-1] != target[j-1])) // if chracter don't match modify character
        );
    }
    
    return dp[n-1][m-1]; // return DP in bottom right
}
 
 
int main(){
    inputs(word)
    inputs(target)
    print(stringedit(word,target))
    
    return 0;
}
