class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
       
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        vector<int> delrow = {0, -1, 0, 1};
        vector<int> delcol = {-1, 0, 1, 0};

        int maxi = 0;

       
        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[0].size(); j++) 
            {
                if (grid[i][j] > 0 && visited[i][j] == 0) 
                {
                  
                    maxi = max(maxi, bfs(visited, i, j, delrow, delcol, grid));
                }
            }
        }
        return maxi;
    }

    int bfs(vector<vector<int>>& visited, int row, int col, vector<int>& delrow, vector<int>& delcol, vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> que;
        que.push({row, col});
        visited[row][col] = 1;

        int currentfish = grid[row][col]; 

        while (!que.empty()) {
            auto it = que.front();
            int x = it.first;
            int y = it.second;
            que.pop();

            for (int i = 0; i < 4; i++) {
                int newrow = x + delrow[i];
                int newcol = y + delcol[i];

                if (newrow >= 0 && newrow < grid.size() && newcol >= 0 && newcol < grid[0].size() &&
                    grid[newrow][newcol] > 0 && visited[newrow][newcol] == 0) {
                    currentfish += grid[newrow][newcol]; 
                    que.push({newrow, newcol});
                    visited[newrow][newcol] = 1; 
                }
            }
        }

        return currentfish;
    }
};
