/*#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+10;
 
int main(){
    int n,s;
    cin>>n>>s;
    int arr[max_n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int i=0,j=1;
    while(i<n && j<n){
            if(arr[i]+arr[j]==s){
            i++;j++;
            cout<<i<<" "<<j<<endl;
            return 0;}
            
        }
        
    
    cout<<"IMPOSSIBLE"<<endl;
}*/
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;
 
using ll = long long;
 
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
 
 
int main() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	map<int, int> vals;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if(vals.count(x - a[i])){
			cout << i + 1 << " " << vals[x - a[i]] << "\n";
			return 0;
		}
		vals[a[i]] = i + 1;
	}
	cout << "IMPOSSIBLE" << '\n';
}