#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define MOD 1e9 + 7;
#define loop_up(a,b) for(ll i=a;i<b;i++)
#define loop_down(a,b) for(ll i=a;i>b;i--)
vector <ll> prime_factors;
 
//__gcd(a,b) is used to find GCD of 2 numbers.
 
//bin-pow (binary exponentiation) - (a^b)%m types.
ll pw(ll a, ll b, ll m){
    if(b==0){
        return a%m;
    }
    if(b%2==0){
        ll t=pw(a, b/2, m);
        return(t*t%m);
    }
    else{
        ll t=pw(a,(b-1)/2, m);
        t=(t*t%m);
        return(a*t%m);
    }
}
 
//multiplicative inverse for division under mod provided that M IS PRIME.
// (a/b)%m = a*(inv b)%m
//invb is multiplicative inverse for division under mod for b - this function returns that
ll modinv(ll x, ll m){
    return(pw(x,m-2,m));
}
 
//PRIME NUMBER CHECK
bool isPrime(ll p){
    if(p==1)return false;
    if(p==2 | p==3)return true;
    if(p%2==0 | p%3==0)return false;
    for(ll i=5; i*i<p; i+=6)
        if(p%i==0 | p%(i+2)==0)
            return false;
    return true;
}
 
//SIEVE OF ERATOSTHENES - prime factors
//remove < if(n%i==0) > to return lll prime numbers before some n
void sieve(ll n){
    vector<bool> temp_isPrime(n+1, true);
    prime_factors.clear();
    for(ll i=2; i<=n; i++){
        if(temp_isPrime[i]){
            if(n%i==0)
                prime_factors.push_back(i);
            for(ll j=i*i; j<=n; j+=i){
                temp_isPrime[j]=false;
            }
        }
    }
}
 
//PALINDROME CHECK
bool isPalindrome(string x){
    ll i=0; ll j=x.length()-1;
    while(i<=j){
        if(x[i]!=x[j])
            return(false);
        i++; j--;
    }
    return(true);
}
 
//STRING REVERSAL
string reverse(string str){
    ll len = str.length();
    ll n = len;
    string r="";
    while(n--)
        r+=str[n];
    return(r);
}
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        times.push_back({start, 1});
        times.push_back({end, -1});
    }
 
    sort(times.begin(), times.end());
 
    int curr_ppl = 0;
    int max_ppl = 0;
    for (const pair<int, int>& t : times) {
        curr_ppl += t.second;
        max_ppl = max(max_ppl, curr_ppl);
    }
 
    cout << max_ppl << endl;
}
