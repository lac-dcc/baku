#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<int> vi;
typedef pair<int, int> pi;
#define SQ(a) (a) * (a)
#define deb(x) cout << #x << " = " << x << '\n'
#define deb2(x, y) cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
// #define LOCAL_DEFINE 1
 
 
int main(int argc, char const *argv[])
{
 
#ifdef LOCAL_DEFINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
 
    }
    sort(a,a+n);    
    int i=0,j=n-1;
    while(i<j){
        int sum= a[i]+a[j];
        if(sum == x){
            break;
        }
        else if(sum > x){
            j--;
        }
        else{
            i++;
        }
    }
    if(i>=j){
        cout<<"IMPOSSIBLE";return 0;
    }
    int left=0,right=0;
    for(int k=0;k<n;k++){
        if(b[k]==a[i] && !left){
            left=k+1;
        }
        if(b[k]==a[j]){
            right=k+1;
        }
 
    }
    cout<<left<<" "<<right;
 
    return 0;
}
