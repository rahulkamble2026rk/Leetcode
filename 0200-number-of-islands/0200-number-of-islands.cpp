class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size(); 
        int m=grid[0].size(); 

        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<int>delrow={0,0,-1,1}; 
        vector<int>delcol={1,-1,0,0};      
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                    count++; 
                    bfs(i,j,visited,grid,delrow,delcol);
                }
            }
        } 
        return count;
    } 
    void bfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>grid,vector<int>delrow,vector<int>delcol)
    {
        visited[row][col]=1; 
        queue<pair<int,int>>que; 
        que.push({row,col}); 

        while(!que.empty())
        {
            int curr_row=que.front().first; 
            int curr_col=que.front().second; 
            que.pop();  

            for(int i=0;i<4;i++)
            {
                int newrow=curr_row+delrow[i]; 
                int newcol=curr_col+delcol[i]; 
                if(newrow>=0 && newrow<grid.size() && newcol>=0 && newcol<grid[0].size() && visited[newrow][newcol]==0 && grid[newrow][newcol]=='1')
                {
                    visited[newrow][newcol]=1; 
                    que.push({newrow,newcol});
                }
            }

        }
    }
};