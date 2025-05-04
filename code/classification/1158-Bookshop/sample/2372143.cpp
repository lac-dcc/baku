#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<math.h>
 
using namespace std;
#define ll long long
#define pb push_back
#define ld long double
#define mod 1000000007
 
int flag = -1;
 
 
ll cd(ll a,ll b)
{
	if(a==0)return b;
	else if (b==0)return a;
	else return cd(b,a%b);
}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n,x;
	cin>>n>>x;
 
	int h[n+1],s[n+1];
	for(int i=0;i<n;i++)cin>>h[i];
	for(int i=0;i<n;i++)cin>>s[i];
 
	//int pages[x+5]={0};
	vector<int> pages(x + 5, 0);
	for(int i=0;i<n;i++){
		for(int j=x;j>=0;j--){
			if(j-h[i]>=0){
				pages[j] = max(pages[j], pages[j-h[i]] + s[i]);
			}
		}
	}
	cout<<pages[x]<<endl;
	return 0;
 
}
 
 
