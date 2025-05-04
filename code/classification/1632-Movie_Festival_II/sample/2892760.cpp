#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5;
int n, k;
multiset<int> kth;
 
struct filmes{
	int ini, fim;
	bool operator<(filmes a)const{
		if(fim != a.fim)	return (fim < a.fim);
		return (ini < a.ini);
	}
};
filmes film[maxn];
 
int main(){
	scanf("%d %d",&n,&k);
	for(int x = 1; x <= n; x++)
	{
		int i, j;
		scanf("%d %d",&i,&j);
		film[x].ini = i;
		film[x].fim = j;
	}
 
	int resp = 1;
	sort(film+1, film+n+1);
	kth.insert(-film[1].fim);
	for(int x = 1; x < k; x++)
		kth.insert(0);
	for(int x = 2; x <= n; x++)
	{
		auto it = kth.lower_bound(-film[x].ini);
		if(it == kth.end())	continue;
 
		kth.erase(it);
		kth.insert(-film[x].fim);
		resp++;
	}
	printf("%d\n",resp);
}