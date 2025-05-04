#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <stack>
#include <queue>
#include <set>
 
using namespace std;
 
 	int granica;
	long long int inf = 1192036854775807;
	int modul = 1000000007;
	int n,m;
	long long int baza[524300], l_baza[524300], r_baza[524300], m_baza[524300];
	pair<int,int> lijevo[524300], desno[524300], maks[524300];
 
 
long long int racun(int a, int b){
	a+=granica-1;
	b+=granica-1;
	if(a == b)
		return baza[a];
	
	long long int suma=0;	
	while(a<b){
		if(a&1)
			suma += baza[a++];
		if(!(b&1))
			suma+= baza[b--];
		
		a= a>>1; b = b>>1;
		if(a==b)
			suma+= baza[a];
	}
	return suma;
}
 
 
 
int main(){
	cin >> n>> m;
	for(int i=0; (1<<i) < n; i++) granica=(1<<(i+1));
	
	
	
	for(int i=granica; i<=2*granica; i++){
		if(i<granica+n){
			int a; cin >> a;
			baza[i] = a;
			m_baza[i] = r_baza[i] = l_baza[i] = a;
			lijevo[i] = desno[i] = maks[i] = make_pair(i-granica+1,i-granica+1);
		}
		else{
			baza[i] = 0;
			baza[i] = 0;
			m_baza[i] = r_baza[i] = l_baza[i] = 0;
			lijevo[i] = desno[i] = maks[i] = make_pair(i-granica+1,i-granica+1);
		}
	}
	
	for(int a=granica-1; a>0; a--){
		baza[a] = baza[2*a]+baza[2*a+1];
			
			int rl1 = desno[2*a].first,  ll1 = lijevo[2*a].first,  rr2 = desno[2*a+1].second,  lr2 = lijevo[2*a+1].second;
			long long int desno1 = r_baza[2*a], lijevo2 = l_baza[2*a+1], rez=-inf;
			
			if(desno1> rez) {
				rez = desno1;
			}
			if(lijevo2 > rez){
			 	rez = lijevo2;
			}
			if(lijevo2+desno1> rez) {
				rez = lijevo2+desno1;
			}
			
			//popravljanje granica
			long long int priv = baza[2*a] + lijevo2;
			if(l_baza[2*a] < priv){
				l_baza[a] = priv;
				lijevo[a] = make_pair(ll1,lr2);
			}
			else{
				l_baza[a] = l_baza[2*a];
				lijevo[a] = lijevo[2*a];
			}
			priv = baza[2*a+1] + desno1;
			if(r_baza[2*a+1] < priv){
				r_baza[a] = priv;
				desno[a] = make_pair(rl1,rr2);
			}
			else{
				r_baza[a] = r_baza[2*a+1];
				desno[a] = desno[2*a+1];
			}
			
			
			
			if(rez < m_baza[2*a]){
				rez = m_baza[2*a];
			}
			if(rez < m_baza[2*a+1]){
				rez = m_baza[2*a+1];
			}
			m_baza[a] = rez;
	}
	
	
	for(int i=0; i<m; i++){
		int a,b; cin >> a >>b;
		a+= granica-1;
		
		baza[a] = b;
		m_baza[a] = l_baza[a] = r_baza[a] = b;
		
		a = a>>1;
		while(a>0){
			baza[a] = baza[2*a]+baza[2*a+1];
			
			int rl1 = desno[2*a].first,  ll1 = lijevo[2*a].first,  rr2 = desno[2*a+1].second,  lr2 = lijevo[2*a+1].second;
			long long int desno1 = r_baza[2*a], lijevo2 = l_baza[2*a+1], rez=-inf;
			
			if(desno1> rez) {
				rez = desno1;
			}
			if(lijevo2 > rez){
			 	rez = lijevo2;
			}
			if(lijevo2+desno1> rez) {
				rez = lijevo2+desno1;
			}
			
			//popravljanje granica
			long long int priv = baza[2*a] + lijevo2;
			if(l_baza[2*a] < priv){
				l_baza[a] = priv;
				lijevo[a] = make_pair(ll1,lr2);
			}
			else{
				l_baza[a] = l_baza[2*a];
				lijevo[a] = lijevo[2*a];
			}
			priv = baza[2*a+1] + desno1;
			if(r_baza[2*a+1] < priv){
				r_baza[a] = priv;
				desno[a] = make_pair(rl1,rr2);
			}
			else{
				r_baza[a] = r_baza[2*a+1];
				desno[a] = desno[2*a+1];
			}
			
			
			
			if(rez < m_baza[2*a]){
				rez = m_baza[2*a];
			}
			if(rez < m_baza[2*a+1]){
				rez = m_baza[2*a+1];
			}
			m_baza[a] = rez;
			
			a/=2;
		}
		if(m_baza[1] < 0)
			cout << 0;
		else
			cout << m_baza[1]<< endl;
	}
}
 
/*
8 1
10 9 6 10 10 3 6 7
2 1 3
 
*/
