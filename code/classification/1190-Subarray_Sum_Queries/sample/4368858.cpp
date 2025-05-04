#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define down '\n'
#define lli long long int
#define ulli unsigned long long int
#define ld long double
using namespace std;
using namespace __gnu_pbds;
 
struct node
{
    lli max_val = 0, max_prefix = 0 , max_suffix = 0 , sum = 0;
    int left = 0, right = 0,  pos_left = 0, pos_right = 0;
    /// max_val  lưu giá trị subarray lớn nhất trong khoảng node quản lí ( và range của sub array từ left đến right )
    inline void merge_node( node & left_node , node & right_node , int l , int m , int r )
    {
        /// left_node has range from l => m , right_node has range from m + 1 => r
 
        sum = left_node.sum + right_node.sum;
        max_prefix =  left_node.max_prefix;
        pos_left = left_node.pos_left;
        if( pos_left == m && right_node.max_prefix >= 0 )
        {
            max_prefix += right_node.max_prefix;
            pos_left = right_node.pos_left;
        }
        if( (left_node.sum + right_node.max_prefix) > max_prefix )
        {
            max_prefix = (left_node.sum + right_node.max_prefix);
            pos_left = right_node.pos_left;
        }
        if( sum >  max_prefix )
        {
            max_prefix = sum;
            pos_left = r;
        }
        /////////////////////////////////////////////////
 
        max_suffix = right_node.max_suffix;
        pos_right = right_node.pos_right;
        if( pos_right == m + 1 && left_node.max_suffix >= 0 )
        {
            max_suffix +=  left_node.max_suffix;
            pos_right = left_node.pos_right;
        }
        if( ( left_node.max_suffix + right_node.sum) > max_suffix )
        {
            max_suffix = ( left_node.max_suffix + right_node.sum);
            pos_right = left_node.pos_right;
        }
        if( sum > max_suffix )
        {
            max_suffix = sum;
            pos_right =  l;
        }
 
 
        ////////////////////////////////////////////////
        if( left_node.right == m && right_node.left == m + 1 && left_node.max_val >= 0 && right_node.max_val >= 0 )
        {
            max_val = left_node.max_val + right_node.max_val;
            left = left_node.left;
            right =  right_node.right;
        }
        else
        {
            if( left_node.max_val > right_node.max_val )
            {
                max_val = left_node.max_val;
                left = left_node.left;
                right = left_node.right;
            }
            else
            {
                max_val = right_node.max_val;
                left = right_node.left;
                right = right_node.right;
            }
        }
 
        if( max_prefix > max_val )
        {
            max_val = max_prefix;
            left = l;
            right = pos_left;
        }
        if( max_suffix > max_val )
        {
            max_val = max_suffix;
            left = pos_right;
            right = r;
        }
        if( (left_node.max_suffix + right_node.max_prefix) > max_val )
        {
            max_val =  (left_node.max_suffix + right_node.max_prefix);
            left = left_node.pos_right;
            right = right_node.pos_left;
        }
    }
    void assign_node( lli val , int pos )
    {
        max_prefix = max_suffix = max_val = sum = val;
        pos_left = pos_right = left = right = pos;
    }
    friend ostream & operator << ( ostream & out  , node & other )
    {
        cout << " max_val = "<< other.max_val <<" prefix = "<< other.max_prefix <<" suffix = "<< other.max_suffix ;
        return out;
    }
};
 
const int maxn = 2e5+100;
 
node sg[maxn*4] ;
lli a[maxn];
int n,q;
 
void build( int id , int left , int right )
{
    if( left == right )
    {
        sg[id].assign_node( a[left] , left );
        return;
    }
    int mid = ( left + right )/2;
    build( id*2, left , mid );
    build( id*2+1 , mid+1, right );
    sg[id].merge_node( sg[id*2] , sg[id*2+1] , left , mid , right );
}
void update( int id , int left , int right , int pos )
{
    if( left > pos || right < pos )return;
    if( left == right )
    {
        sg[id].assign_node( a[left] , left );
        return;
    }
    int mid = ( left + right )/2;
    update(id*2,left,mid,pos);
    update(id*2+1,mid+1,right,pos);
    sg[id].merge_node( sg[id*2], sg[id*2+1] , left , mid , right );
//    cout <<" range left = "<< left <<" right = "<< right <<" node = "<< sg[id] <<endl;
//    cout <<" node_left left = "<< left <<" mid = "<< mid <<" node = "<< sg[id*2] <<endl;
//    cout <<" node_right left = "<< mid+ 1<<" right = "<< right <<" node = "<< sg[id*2+1] <<endl<<endl;
}
 
void read()
{
    cin >> n >> q;
    for( int i = 1; i <= n; i ++ ) cin >> a[i];
    build( 1, 1 , n );
}
void solve()
{
    lli pos , val;
    for( int i = 1; i <= q; i ++ )
    {
        cin >> pos >> val;
        a[pos] = val;
//        cout <<" i = "<< i <<endl;
//        cout <<" arr = "<<endl;
//        for( int i = 1; i <= n;i ++ ) cout << a[i] <<" ";
//        cout <<endl;
        update(1,1,n,pos);
        cout << max( 0LL , sg[1].max_val )<< down;
//        cout <<endl<<"________________________________________"<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    read();
    solve();
    return 0;
}
