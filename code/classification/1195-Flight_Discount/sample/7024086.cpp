#include <bits/stdc++.h>
using namespace std;
 
const long long inf = (long long) 1e18 + 10;
 
int N, M;
long long Pe[100100][2];
bool Vi[100100][2];
vector<pair<long long,pair<int,int>>> G[100100][2];
priority_queue<pair<long long, pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>>> P;
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0, a, b, p; i < M; i++) {
	    cin >> a >> b >> p;
	    G[a][0].push_back(make_pair(p,make_pair(b,0)));
	    G[a][0].push_back(make_pair(p/2,make_pair(b,1)));
	    G[a][1].push_back(make_pair(p,make_pair(b,1)));
	}
	
	for (int i = 1; i <= N; i++) {
	    Pe[i][0] = inf;
	    Pe[i][1] = inf;
	}
	Pe[1][0] = 0;
	Pe[1][1] = 0;
	P.push(make_pair(Pe[1][0],make_pair(1,0)));
	
	while (!P.empty()) {
	    long long p = P.top().first;
	    int a = P.top().second.first;
	    int b = P.top().second.second;
	    P.pop();
	    if (Vi[a][b]) continue;
	    Vi[a][b] = true;
	    for (long unsigned int i = 0; i < G[a][b].size(); i++) {
	        if (Pe[G[a][b][i].second.first][G[a][b][i].second.second] > p + G[a][b][i].first) {
	            Pe[G[a][b][i].second.first][G[a][b][i].second.second] = p + G[a][b][i].first;
	            P.push(make_pair(Pe[G[a][b][i].second.first][G[a][b][i].second.second], make_pair(G[a][b][i].second.first,G[a][b][i].second.second)));
	        }
	    }
	}
	cout << Pe[N][1] << "\n";
	return 0;
}
