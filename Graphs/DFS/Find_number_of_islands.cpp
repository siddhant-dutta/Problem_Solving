/*
  PROBLEM LINK : 
    https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isSafe (vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
        // if the element is land 
        // also it should not have been visited earlier
        int ROW = grid.size();
        int COL = grid[0].size();
        return (row>=0)&&(row<ROW)&&(col>=0)&&(col<COL)&&(grid[row][col] && !visited[row][col]);
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
        // implementation of dfs on a 2D matrix ..
        // Here the numbering of the nodes is according to the row and col indexes 
        // There can be only 8 neighbours of a node at max... 
        // So no need to made an adjacency list .
        // just look for valid neigbours in the 8 possible directions at each node and implement the dfs 
        
        if(visited[row][col]) return ; 
        
        visited[row][col] = true; 
        
        vector<int> rowNbr = {-1,1,0,0,-1,1,-1,1};
        vector<int> colNbr = {0,0,-1,1,-1,1,1,-1};
        
        for(int i=0; i<8; i++){
            if(isSafe(grid, row+rowNbr[i], col+colNbr[i], visited) ){
                dfs(grid, row+rowNbr[i], col+colNbr[i], visited);
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // since dfs will traverse through all possible nodes that can be reached from the starting node ... we will no when one island gets
        // traversed and so we can increase the count of islands.
        // After each dfs operation search for another starting node which has not been previously visited to start the next dfs operation 
        
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<vector<bool>> visited(ROW, vector<bool>(COL,0));
        vector<vector<int>> M (ROW, vector<int>(COL,0));
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++)
                M[i][j] = int(grid[i][j])-48;
        }
        
        int count_islands = 0;
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(M[i][j] && !visited[i][j]){
                    dfs(M, i, j, visited);
                    count_islands++;
                }
            }
        }
        return count_islands; 
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
