#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
typedef long long int ll;
//convert decimal int to binary no
string decimalToBinary(int n)
{
    //finding the binary form of the number and
    //converting it to string.
    string s = bitset<64> (n).to_string();
 
    //Finding the first occurance of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');
 
    if(loc1 != string::npos)
        return s.substr(loc1);
 
    return "0";
}
 
//Generate all divisors for a number in O(n) time complexity
vector<int> genDiv(int n) {
    vector<int> v;
    for(int i=1;i<=sqrt(n);i++) {
        if(n%i==0) {
            if(i == n/i) {
                v.push_back(i);
            }
            else {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    return v;
}
 
//Print all prime factors
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}
 
//Pascal's triangle program to find out nCr
// int initialize()
// {
 
//     // 0C0 = 1
//     l[0][0] = 1;
//     for (int i = 1; i < 1001; i++) {
//         // Set every nCr = 1 where r = 0
//         l[i][0] = 1;
//         for (int j = 1; j < i + 1; j++) {
 
//             // Value for the current cell of Pascal's triangle
//             l[i][j] = (l[i - 1][j - 1] + l[i - 1][j])%mod;
//         }
//     }
// }
 
//find nCr
// int C(int n,int m) {
//     return l[n][m];
// }
 
//find factorial of a number
int fact(int n) {
    int prod = 1;
    while(n>0) {
        prod = (long long)prod*n%mod;
        n--;
    }
    return prod;
}
 
//find product of a large number
int product(int a,int b) {
    int prod = (long long)a*b%mod;
    return prod;
}
 
int largestDigit(int n) {
    int big = -1;
    while(n>0) {
        int rem = n%10;
        n = n/10;
        if(rem>big) {
            big = rem;
        }
        if(rem == 9) {
            return 9;
        }
    }
    return big;
}
 
int memo(int i,int j,int a[],int m) {
    // if(j<1 || j>m) {
    //     return 0;
    // }
    if(i == 0) {
        if(a[i] == 0) {
            return 1;
        }
        else if(abs(a[i]-j) <= 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if(a[i] == 0) {
        int sum = 0;
        for(int k=1;k<=m;k++) {
            sum += memo(i-1,k,a,m);
        }
        return sum;
    }
    return memo(i-1,j-1,a,m)+memo(i-1,j,a,m)+memo(i-1,j+1,a,m);
}
 
int dp[200001] = {0};
 
int dfs(vector<int> g[],int u,int n,int count) {
 
    for(int i=0;i<g[u].size();i++) {
        count += 1+dfs(g,g[u][i],n,0);
    }
    return dp[u]=count;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 
    int n;
    cin>>n;
    int a[n+1];
    vector<int> g[n+1];
    for(int i=2;i<=n;i++) {
        cin>>a[i];
        g[a[i]].push_back(i);
    }
    dfs(g,1,n,0);
    for(int i=1;i<=n;i++) {
        cout<<dp[i]<<" ";
    }
    return 0;
}
