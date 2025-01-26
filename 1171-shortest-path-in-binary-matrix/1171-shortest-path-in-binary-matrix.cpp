class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); 
        if(grid[0][0]==0 && grid.size()==1)
        {
            return 1;
        }
        if (grid[0][0] || grid[n-1][n-1]) { 
            return -1; 
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); 
        dist[0][0] = 1; 

        queue<pair<int, pair<int, int>>> que; 
        que.push({1, {0, 0}});  

        vector<int> delrow = {-1, -1, -1, 0, 0, 1, 1, 1};  
        vector<int> delcol = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!que.empty()) {   
            auto it = que.front(); 
            int dis = it.first;
            int currow = it.second.first; 
            int curcol = it.second.second; 
            que.pop(); 

            for (int i = 0; i < 8; i++) { 
                int newrow = currow + delrow[i]; 
                int newcol = curcol + delcol[i]; 

                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n && grid[newrow][newcol] == 0 && dis + 1 < dist[newrow][newcol]) {
                    if (newrow == n - 1 && newcol == n - 1) { 
                        return dis + 1;
                    } 
                    dist[newrow][newcol] = dis + 1;
                    que.push({dis + 1, {newrow, newcol}});
                }
            }
        } 
        return -1;
    }
};
