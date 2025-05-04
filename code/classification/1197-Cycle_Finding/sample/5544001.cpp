#include<bits/stdc++.h>
using namespace std;
 
//typedef pair<int,int> pi;
 
void print(vector<int> &nums){
    cout << "------" << endl;
    for(auto num : nums){
    	cout << num << " ";
    }
    cout << endl;
    cout << "------" << endl;
}
 
void print(vector<long> &nums){
    cout << "------" << endl;
    for(auto num : nums){
    	cout << num << " ";
    }
    cout << endl;
    cout << "------" << endl;
}
 
void print(vector<string> &strings){
	cout << "------" << endl;
    for(auto str : strings){
    	cout << str << " ";
    }
    cout << endl;
    cout << "------" << endl;
}
 
void print(vector<vector<int>>& grid){
	for(auto& row: grid){
		for(auto& cell: row){
			if(cell == INT_MAX){
				cout << "#" << " ";
			}else{
				cout << cell << " ";
			}
		}
		cout << endl;
	}
}
 
void print(vector<vector<char>>& grid){
	for(auto& row: grid){
		for(auto& cell: row){
				cout << (char)cell << " ";
		}
		cout << endl;
	}
}
 
void print(vector<vector<pair<int,int>>>& grid){
	for(auto& row: grid){
		for(auto& cell: row){
			cout << cell.first << ":" << cell.second << " ";
		}
		cout << endl;
	}
}
 
 
/*class PriceComparator{
public:
	bool operator()(pi item1, pi item2){
		return item1.second < item2.second;
	}
};*/
 
/*
So when we type 2 and then hit enter, std::cin captures the string "2\n" as input. 
It then extracts the value 2 to variable choice, leaving the newline character behind for later. 
Then, when std::getline() goes to extract text to name, 
it sees "\n" is already waiting in std::cin, 
and figures we must have previously entered an empty string! Definitely not what was intended.
 
**************************************************************
sgetline(cin >> ws, name); 
**************************************************************
*/
 
 /*class comp{
 public:
 	bool operator()(const pair<long,int>& item1, const pair<long,int>& item2)const{
 		return item1.first > item1.second;
 	}
 };*/
 
 
long inf = 1L<<47;
 
bool isOverFlowing(long a, long b){
	return (a < 0 && b < 0 && (a+b)>0) || (a>0 && b>0 && (a+b)<0);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	//cout << LONG_MAX << endl;
 	//cout << LONG_MAX + (-2) << endl;
	int n,m;
	cin >> n >> m;
	vector<vector<int>> g;
 
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		u--; v--;
		g.push_back({u, v, w});
	}
 
	vector<long> distance(n, inf);
	vector<int> p(n, -1);
	distance[0] = 0;
	int last_vertex = -1;
	for(int i=0;i<n;i++){
		last_vertex = -1;
		for(auto& edge: g){
			int u = edge[0], v = edge[1], w = edge[2];
			//if(!isOverFlowing(distance[u],w) && distance[v] > distance[u] + w){
			if((w<0 || distance[u]<inf) && distance[v] > distance[u] + w){
				distance[v] = distance[u]+w;
				p[v] = u;
				last_vertex = v;
			}
		}
		//print(distance);
	}
 
	if(last_vertex == -1){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		int  y = last_vertex;
		//cout << y << endl;
		for(int i=0;i<n;i++){
			y = p[y];
		}
		stack<int> path;
		for(int i=y; ; i=p[i]){
			path.push(i);
			if(i == y && path.size()>1){
				break;
			}
		}
		while(!path.empty()){
			cout << path.top()+1 << " "; path.pop();
		}
		cout << endl;
	}
 
	return 0;
	
 
}
