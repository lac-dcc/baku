#include <bits/stdc++.h>
using namespace std;
#define FRE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
 
struct item{
    long long seg,pre,suf,sum;
};
 
struct segtree{
    vector<item> val;
    int size;
    
    item merge(item a,item b){
        return {
            max({a.suf+b.pre,a.seg,b.seg}),
            max(a.pre,a.sum+b.pre),
            max(a.suf+b.sum,b.suf),
            a.sum+b.sum
        };
        
    }
    item single(int v){
        if(v>0){
        return {v,v,v,v};
    }else{
        return {0,0,0,v};
    }
    }
    
    void init(int n){
        size=1;
        while(size<n){
            size*=2;
        }
        val.resize(2*size);
        
    }
    
    item NEUT = {0,0,0,0};
    
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                val[x]=single(a[lx]);
            }
            return;
        }
        
        int r=(lx+rx)/2;
        build(a,2*x+1,lx,r);
        build(a,2*x+2,r,rx);
        
        val[x]=merge(val[2*x+1],val[2*x+2]);
    }
    
    
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    
    void set(int i, int v,int x,int lx,int rx){
        if(rx-lx==1){
            val[x]=single(v);
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        val[x]=merge(val[2*x+1],val[2*x+2]);
    }
    
    void set(int i,int x){
        set(i,x,0,0,size);
    }
  
    
    item findm(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l) return NEUT;
        if(lx>=l && rx<=r) {
            return val[x];
        }
        
         int m=(lx+rx)/2;
        item u=findm(l,r,2*x+1,lx,m);
        item v=findm(l,r,2*x+2,m,rx);
        return merge(u,v);
        
    }
    
    item findm(int l,int r){
        return findm(l,r,0,0,size);
    }
    
  
    
    
};
 
int32_t main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    
    
    segtree st;
    st.init(n);
    
    vector<int> a(n,0);
    for(int x=0; x<n; x++){
        cin>>a[x];
    }
    st.build(a);
    
    while(m--){
        int l,v;
            cin>>l>>v;
            l--;
           st.set(l,v);
           
            cout<<st.findm(0,n).seg<<endl;
            
        
        }
    }
    
    
   
     
    
    
 
 
	
  
     
    
    
        
        
 
 
	
  
