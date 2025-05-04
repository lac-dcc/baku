#include<bits/stdc++.h>
#define l long long
l o=9e18,n,k,q;
int main() {
	std::cin>>n>>k;
	l a[k];
	for(l &i:a)std::cin>>i;
	for(l m=0;m<(1<<k);++m) {
		l p=1;
		for(int i=0;i<k;++i)
			if(m>>i&1){
				if(p>=o/a[i]) {
					p=o;
					break;
				}
				p*=a[i];
			}
		q+=n/p*((__builtin_popcount(m)&1)?1:-1);
	}
	std::cout<<q+n;
	return 1;
}
