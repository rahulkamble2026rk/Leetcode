class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> delrow = {+1, -1, 0, 0};
        vector<int> delcol = {0, 0, 1, -1};
        // 0 -> sea cell , 1->land cell
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && visited[0][i] != 1) {
                dfs(visited, grid, 0,i,delrow,delcol);
            }
            if (grid[n - 1][i] == 1 && visited[n - 1][i] != 1) {
                dfs(visited, grid, n-1,i,delrow,delcol);
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && visited[i][0] != 1) {
                dfs(visited,grid,i,0,delrow,delcol);
            }
            if (grid[i][m - 1] == 1 && visited[i][m - 1] != 1) {
                dfs(visited,grid,i,m-1,delrow,delcol);
            }
        } 
          
          int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& visited, vector<vector<int>>& grid, int row,
             int col, vector<int>& delrow, vector<int>& delcol) {
        visited[row][col] = 1;
        for (int w = 0; w < 4; w++) { 
              int newrow=row+delrow[w]; 
              int newcol=col+delcol[w];
            if (newrow >= 0 && newrow < grid.size() && newcol >= 0 &&
                newcol < grid[0].size() && visited[newrow][newcol] != 1 &&
                grid[newrow][newcol] == 1) {
                dfs(visited, grid,newrow, newcol, delrow, delcol);
            }
        }
    }
};