#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
 
using namespace std;
 
int main( )
{
	cout.tie( nullptr );
	cin.tie( nullptr );
	ios::sync_with_stdio( false );
 
	int n = 0;
	int m = 0;
	cin >> n >> m;
 
	vector<vector<pair<long long, long long>>> edges( n + 1 );
 
	for ( int i = 0; i < m; ++i )
	{
		int a = 0;
		int b = 0;
		int c = 0;
 
		cin >> a >> b >> c;
		edges[a].emplace_back( b, c );
	}
 
	vector<long long> distance( n + 1, static_cast<long long>( 1e18 ) );
 
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q( greater<pair<long long, long long>>{} );
	distance[1] = 0;
	q.emplace( 0, 1 );
 
	while ( q.empty( ) == false )
	{
		auto[route, from] = q.top( );
		q.pop( );
 
		if ( route > distance[from] )
		{
			continue;
		}
 
		for ( auto& edge : edges[from] )
		{
			auto[to, length] = edge;
			long long newLength = route + length;
 
			if ( newLength < distance[to] )
			{
				q.emplace( newLength, to );
				distance[to] = newLength;
			}
		}
	}
 
	for ( int i = 1; i <= n; ++i )
	{
		cout << distance[i] << " ";
	}
 
	return 0;
}
