#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
 
 
// Always use ranges [lidx,ridx)
 
struct Node
{
    ll sum = 0, max_pre = 0, max_suf = 0, max_sub = 0;
    int lidx, ridx, midx;
    Node *lchild = nullptr, *rchild = nullptr;
    
    void update(){
        if(lchild == rchild) return;
        if(lchild == nullptr){
            sum = rchild->sum;
            max_pre = rchild->max_pre;
            max_suf = rchild->max_suf;
            max_sub = rchild->max_sub;
            return;
        }
        if(rchild == nullptr){
            sum = lchild->sum;
            max_pre = lchild->max_pre;
            max_suf = lchild->max_suf;
            max_sub = lchild->max_sub;
            return;
        }
        sum = lchild->sum + rchild->sum;
        max_pre = max(lchild->max_pre,lchild->sum + rchild->max_pre);
        max_suf = max(rchild->max_suf,lchild->max_suf + rchild->sum);
        max_sub = max(max(lchild->max_sub,rchild->max_sub),lchild->max_suf + rchild->max_pre);
    }
 
    Node(int lidx, int ridx) : lidx(lidx), ridx(ridx) {midx = (lidx + ridx) >> 1;}
 
    void gen_child(){
        lchild = new Node(lidx, midx);
        rchild = new Node(midx, ridx);
    }
 
    int seg_size(){
        return ridx - lidx;
    }
};
 
 
struct SegTree
{
    Node *head;
 
    void set_val(Node *n, int idx, ll val){
        if(n->seg_size() == 1){
            n->sum = val;
            n->max_pre = val;
            n->max_suf = val;
            n->max_sub = val;
        }
        else{
            if(n->lchild == nullptr) n->gen_child();
    
            if(idx < n->midx) set_val(n->lchild,idx,val);
            else set_val(n->rchild,idx,val);
 
            n->update();
        }
    }
 
    void set_val(int idx, ll val){
        set_val(head,idx,val);
    }
 
    SegTree(int l, int r) {head = new Node(l,r);};
};
 
int main(){
    int N,M,K,X;
    cin >> N >> M;
    SegTree S(1,N+1);
    for(int i = 1;i <= N;i++){
        cin >> X;
        S.set_val(i,X);
    }
    for(int i = 1;i <= M;i++){
        cin >> K >> X;
        S.set_val(K,X);
        cout << max(S.head->max_sub,0LL) << '\n';
    }
 
    return 0;
}
