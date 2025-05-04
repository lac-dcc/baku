#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int n;
    cin>>n;
    vector<pair<int,bool>> v;
    int x; int y;
    while(n--){
    	cin>>x;cin>>y;
    	v.push_back(make_pair(x,true));
    	v.push_back(make_pair(y,false));
    }
   	sort(v.begin(),v.end());
   	int ans =0; int maxx =0;
   	for(int i=0;i<v.size();i++){
   		if(v[i].second==true){
   			ans++;
   			maxx = max(ans,maxx);
   		}else{
   			ans--;
   		}
   	}
   	cout<<maxx<<endl;
return 0;
}
