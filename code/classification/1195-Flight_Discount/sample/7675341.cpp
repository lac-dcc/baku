#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<ll,pair<ll,ll>>
 
ll mod = 1e9 + 7;
bool isPossible(ll time , vector<ll> &nums, ll t){
    
    ll count = 0 ;
    
    for(auto x: nums){
        count += time/x ;
    }
    return count >= t;
}
 
void solve(ll n , int mask , ll curr_weight , ll rides, vector<ll> nums, ll &mini, ll cap){
     
    
    if(mask==((1<<n) - 1)){
        mini = min(mini , rides) ;
        return ;
    }
    for(ll i = 0 ; i < n ; i++){
        if((mask&(1<<i))==0){
            curr_weight += nums[i] ;
            mask |= (1<<i) ;
            if(curr_weight > cap){
                curr_weight = nums[i];
                rides++ ;
            }
            solve(n , mask , curr_weight , rides , nums , mini, cap) ;
            mask &= ~(1<<i);
            curr_weight -= nums[i];
        }
    }
}
ll cheapestFlights(vector<pair<ll,ll>> flights[] , ll src , ll dest){
    
    //vector<vector<ll>> costToCities(dest + 1 , {INT_MAX,INT_MAX}) ;
    
    vector<ll> dist(dest + 1 , LLONG_MAX);
    vector<ll> disc(dest + 1 , LLONG_MAX);
    //costToCities[src][0] = 0;
    //costToCities[src][1] = 0;
    dist[0] = 0 ; dist[1] = 0;
    disc[0] = 0 ; disc[1] = 0;
    
    priority_queue<pi,vector<pi>,greater<pi>> pq ;
    pq.push({0 , {src , 0}}) ;
    //pq.push({0 , {src , 1}}) ;
    
    while(pq.size()){
        
        auto curr = pq.top() ;
        pq.pop() ;
        
        ll cost = curr.first ;
        ll city = curr.second.first ;
        ll flag = curr.second.second;
        
        if(flag==1){
            if(disc[city] < cost) continue;
        }
        if(flag==0){
            if(dist[city] < cost) continue;
        }
        
        for(auto x: flights[city]){
            
            ll nextCity = x.first ;
            ll nextCost = x.second;
            
            if(flag==0){
                
                if(dist[nextCity] > cost + nextCost){
                    dist[nextCity] = cost + nextCost;
                    pq.push({dist[nextCity] , {nextCity , 0}}) ;
                }
                if(disc[nextCity] > cost + nextCost/2){
                    disc[nextCity] = cost + nextCost/2;
                    pq.push({disc[nextCity] , {nextCity , 1}}) ;
                }
            }
            if(flag){
                if(disc[nextCity] > cost + nextCost){
                    disc[nextCity] = cost + nextCost;
                    pq.push({disc[nextCity] , {nextCity , 1}}) ;
                }
            }
        }
    }
    
    return disc[dest] ;
}
int main(){
    
    
    
    ll n , conn , from , to , cost ;
    cin >> n >> conn ;
    
    vector<pair<ll,ll>> flights[n+1] ;
    
    for(ll i = 0 ; i < conn ; i++){
        cin >> from >> to >> cost ;
        flights[from].push_back({to , cost}) ;
    }
    
    cout << cheapestFlights(flights ,1 , n) << endl;
    
    
    
    return 0;
    
}