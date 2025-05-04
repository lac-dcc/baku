/*
Time limit: 1.00 s Memory limit: 512 MB
In a movie festival, n movies will be shown. Syrjälä's movie club consists of k members, 
who will be all attending the festival.
 
You know the starting and ending time of each movie. 
What is the maximum total number of movies the club members can watch entirely if they act optimally?
 
Input
 
The first input line has two integers n and k: the number of movies and club members.
 
After this, there are n lines that describe the movies. 
Each line has two integers a and b: the starting and ending time of a movie.
 
Output
 
Print one integer: the maximum total number of movies.
 
Constraints
1≤k≤n≤2⋅10^5
1≤a<b≤10^9
Example
 
Input:
5 2
1 5
8 10
3 6
2 5
6 9
 
Output:
4
*/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
 
using namespace std;
using namespace __gnu_pbds; 
 
typedef long long ll;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> index_set;
 
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main() {
    boost;
    int n, k; cin>>n>>k;
    array<int, 3> a[n];
    for(int index = 0; index < n; ++index) {
        cin>>a[index][1]>>a[index][0];
        a[index][2] = index;
    }
 
    sort(a, a + n);
    int indices[n];
    set<array<int, 2>> st;
    int result = 0;
    for(int index = 0; index < n; index++) {
        auto itr = st.lower_bound({a[index][1] + 1});
        if(itr != st.begin()) {
            --itr;
            indices[a[index][2]] = (*itr)[1];
            st.erase(itr);
        }
        else{
            indices[a[index][2]] = st.size();
        }
        if((int)st.size() < k) {
            ++result;
            st.insert({a[index][0], indices[a[index][2]]});
        }
    }
 
    cout<<result<<"\n";
    return 0;
}