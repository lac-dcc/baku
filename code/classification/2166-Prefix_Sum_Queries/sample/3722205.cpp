#include <bits/stdc++.h>
using namespace std;
int n,q;
long long longmin=-1e18;
long long x[200010];
long long prefix[200010];
struct segnode{
     long long val;
     long long z;
     long long l,r;
     struct segnode *left,*right;
};
struct segnode *getnode(){
     struct segnode *ret=new segnode;
     ret->val=longmin;
     ret->z=0;
     ret->left=NULL;
     ret->right=NULL;
     return ret;
}
void buildsegnode(struct segnode *node,int l,int r,long long a[])
{
     node->l=l;
     node->r=r;
     if(l==r)
     {
          node->val=a[l];
          return;
     }
     node->left=getnode();
     node->right=getnode();
     buildsegnode(node->left,l,(l+r)/2,a);
     buildsegnode(node->right,(l+r)/2+1,r,a);
     node->val=max(node->left->val,node->right->val);
}
void update(struct segnode *node,int l,int r,long long inc)
{
     if(node->l>r||node->r<l)
          return;
     if(node->l>=l&&node->r<=r)
     {
          node->z+=inc;
          node->val+=inc;
          return;
     }
     update(node->left,l,r,inc);
     update(node->right,l,r,inc);
     node->val=max(node->left->val,node->right->val)+node->z;
}
long long getmax(struct segnode *node,int l,int r,long long inc)
{
     if(node->l>r||node->r<l)
          return longmin;
     if(node->l>=l&&node->r<=r)
          return node->val+inc;
     long long ret1=getmax(node->left,l,r,inc+node->z);
     long long ret2=getmax(node->right,l,r,inc+node->z);
     return max(ret1,ret2);
}
struct segnode *root=getnode();
long long getmax(int l,int r)
{
     return getmax(root,l,r,0);
}
void update(int l,int r,long long inc)
{
     update(root,l,r,inc);
}
int main(){
     cin>>n>>q;
     for(int i=1;i<=n;i++)
          cin>>x[i];
     for(int i=1;i<=n;i++)
          prefix[i]=prefix[i-1]+x[i];
     buildsegnode(root,1,n,prefix);
     while(q--)
     {
          int type;
          cin>>type;
          if(type==1)
          {
               int k;
               long long u;
               cin>>k>>u;
               long long dif=u-x[k];
               x[k]=u;
               update(k,n,dif);
          }
          else
          {
               int l,r;
               cin>>l>>r;
               long long ret=getmax(l,r);
               l--;
               if(l)
                    ret-=getmax(l,l);
               ret=max(ret,(long long)0);
               cout<<ret<<'\n';
          }
     }
     return 0;
}
