#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<ll, ll> llll;
typedef vector<llll> vll;
typedef vector<pair<int, ii> > EdgeList; //Edgelist representation of graphs to store an edge and weights for both directions, i.e., in an undirected graph.x
 
#define mod 1000000007
 
int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	vector<int> c(n);
	loop(i, 0, n)
		cin>>c[i];
	vector<int> res(x+1, -1);
	for(int i=1;i<=x;i++){
		for(int j=0;j<n;j++){
			if(c[j]>i)
				continue;
			else if(c[j]==i)
				res[i]=1;
			else{
				int temp=res[i-c[j]]==-1?-1:1+res[i-c[j]];
				if(temp!=-1)
					res[i]=res[i]==-1?temp:min(temp, res[i]);
			}
		}
	}
	printf("%d\n", (int)res[x]);
	return 0;
}