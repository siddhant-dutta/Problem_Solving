/*
https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size(), m=grid[0].size();
	    vector<vector<int>> dist(n, vector<int>(m));
	    vector<vector<bool>> visited(n, vector<bool>(m,false));
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){ 
	        for(int j=0;j<m;j++) {
	            if(grid[i][j]==1)
	                q.push({i,j}), visited[i][j]=1;
	        }
	    }
	    
	    while(!q.empty()){
	        auto node = q.front();
	        int r = node.first;
	        int c = node.second;
	        q.pop();
	        vector<int> d = {0,1,0,-1,0};
	        for(int i=0; i<4; i++){
	            int nr = r+d[i], nc = c+d[i+1];
	            if(nr<0 || nr>=n || nc<0 || nc>=m || visited[nr][nc]) continue;
	            q.push({nr,nc});
	            visited[nr][nc] = true;
	            dist[nr][nc] = dist[r][c]+1;
	        }
	    }
	    return dist;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
