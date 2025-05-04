#include <iostream>
#include <vector>
#include <queue>
using namespace::std;
 
int nodes;
int rootNode;
int maxNode;
bool visited[200001];
bool visited1[200001];
bool visitedRef1[200001];
bool visitedRef2[200001];
vector<int> child[200001];
int arr1[200001];
int arr2[200001];
 
int curMaxNode;
int curMaxAns;
 
int preProcess(int curNode){
	maxNode = max(maxNode, curNode);
	visited[curNode] = true;
	int first=0, second=0;
	for(int i=0; i<child[curNode].size(); ++i){
		if(visited[child[curNode][i]] == false){
			visited[child[curNode][i]] = true;
			int ans = preProcess(child[curNode][i]);
			if(ans >= first){
				second = first;
				first = ans;
			}else if(ans > second){
				second = ans;
			}
		}
	}
 
	if(first + second + 1 >= curMaxAns){
		curMaxAns = first + second + 1;
		curMaxNode = curNode;
	}
 
	return 1 + max(first, second);
}
 
int bfs(){
	queue<int> q;
	visited1[curMaxNode] = true;
	q.push(curMaxNode);
	int ans;
	while(q.size()){
		int curSize = q.size();
		for(int i=0; i<curSize; ++i){
			int curNode = q.front();
			q.pop();
			ans = curNode;
			for(int j=0; j<child[curNode].size(); ++j){
				if(visited1[child[curNode][j]] == false){
					visited1[child[curNode][j]] = true;
					q.push(child[curNode][j]);
				}
			}
		}
	}
	return ans;
}
 
void bfs_from_referecne(int node, int* arr, bool* vis){
	queue<int> q;
	vis[node] = true;
	int curHeight = 0;
	q.push(node);
	while(q.size()){
		int curSize = q.size();
		for(int i=0; i<curSize; ++i){
			int curNode = q.front();
			q.pop();
			vis[curNode] = true;
			arr[curNode] = curHeight;
			for(int j=0; j<child[curNode].size(); ++j){
				if(vis[child[curNode][j]] == false){
					vis[child[curNode][j]] = true;
					q.push(child[curNode][j]);
				}
			}
		}
		curHeight+=1;
	}
}
 
pair<int, int> bfsNodeAndDepth(int node, vector<bool>& vec){
	// cout << "bfsNodeAndDepth() for node:" << node << endl;
	queue<int> q;
	q.push(node);
	vec[node] = true;
	int curHeight = 0;
	int ansNode;
	while(q.size()){
		int curSize = q.size();
		for(int i=0; i<curSize; ++i){
			int curNode = q.front();
			q.pop();
			ansNode = curNode;
			// cout << "curNode:" << curNode << "  ";
			for(int j=0; j<child[curNode].size(); ++j){
				if(vec[child[curNode][j]] == false){
					vec[child[curNode][j]] = true;
					// cout << "Pushing node:" << child[curNode][j] << endl;
					q.push(child[curNode][j]);
				}
			}
		}
		curHeight+=1;
	}
	return make_pair(ansNode, curHeight);
}
 
pair<int, int> fun(){
    // cout << "Entered fun()" << endl;
	int firstNode=0, secondNode=0;
	int firstDepth=0, secondDepth=0;
 
	for(int i=0; i<child[curMaxNode].size(); ++i){
		vector<bool> tempVisited(nodes+1, false);
		tempVisited[curMaxNode] = true;
		pair<int, int> ans = bfsNodeAndDepth(child[curMaxNode][i], tempVisited);	// return < node , depth>;
		// cout << "for i:" << i << "  child:" << child[curMaxNode][i] << "  ans.first=" << ans.first << "  ans.second=" << ans.second << endl;
		if(ans.second > firstDepth){
			secondNode = firstNode;
			secondDepth = firstDepth;
			firstNode = ans.first;
			firstDepth = ans.second;
		}else if(ans.second > secondDepth){
			secondDepth = ans.second;
			secondNode = ans.first;
		}
	}
 
	return make_pair(firstNode, secondNode);
}
 
int main(){
	int n;
	cin >> n;
	nodes = n;
	maxNode = 0;
	// cout << "child[curMaxNode].size() : " << child[21].size() << endl;
	int n1, n2;
	for(int i=1; i<n; ++i){
		cin >> n1 >> n2;
		child[n1].push_back(n2);
		child[n2].push_back(n1);
		visited[n1] = false;
		visited[n2] = false;
		visited1[n1] = false;
		visited1[n2] = false;
		visitedRef1[n1] = false;
		visitedRef1[n2] = false;
		visitedRef2[n1] = false;
		visitedRef2[n2] = false;
	}
	rootNode = n2;
    // cout << "child[curMaxNode].size() : " << child[21].size() << endl;
	curMaxAns = 0;
	preProcess(rootNode);
	// curMaxNode constains the node which which lies on the intersecting point of the longest path
	// cout << "curMaxNode: " << curMaxNode << endl;
	int first, second;  
	// cout << "child[curMaxNode].size() : " << child[curMaxNode].size() <<  endl;
	// cout << "Printing the child of all the relevant nodes" << endl;
	for (int i=1; i<=nodes; ++i){
	    // cout << "child of i:" << i << "  ";
	    for(int j=0; j<child[i].size(); ++j){
	        // cout << child[i][j] << "  ";
	    }
	    // cout << endl;
	}
	// cout << endl << endl;
	if(child[curMaxNode].size() == 1){
		// std::cout << "curMaxNode is the end node of the edge, just to simple bfs" << endl;
		// cout << "Calling simple bfs" << endl;
		first = curMaxNode;
		second = bfs();		// use visited1
	}else{
	    // std::cout << "curMaxNode is NOT the end node of the path, finding both first and second" << endl;
		pair<int, int> ans = fun();
		first = ans.first;
		second = ans.second;
	}
 
	// cout << "first: " << first << " second: " << second << endl;	
	// We have first and second
	// bfs from  first;
	bfs_from_referecne(first, arr1, visitedRef1);	// using the same visited1 with opposite condition
	// bfs from second;
	bfs_from_referecne(second, arr2, visitedRef2);
 
	for(int i=1; i<=nodes; ++i){
		//cout << "i: " << i<< "  " << max(arr1[i], arr2[i]) << "\n";
		cout << max(arr1[i], arr2[i]) << "\n";
	}
}
