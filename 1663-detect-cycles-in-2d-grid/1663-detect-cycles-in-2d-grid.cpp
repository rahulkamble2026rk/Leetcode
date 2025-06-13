class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid)  
    {
        int m=grid.size(); 
        int n=grid[0].size(); 
        vector<vector<int>>visited(m,vector<int>(n,0)); 
        int size=0;
        vector<int>delrow={0,0,+1,-1}; 
        vector<int>delcol={+1,-1,0,0};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j])
                {
                    if(bfs(visited,grid[i][j],i,j,delrow,delcol,size,grid)==true)
                    {
                        return true;
                    }
                }
            }
        } 
        return false;
    } 

    bool bfs(vector<vector<int>>&visited,char original_char,int x,int y,vector<int>&delrow,vector<int>&delcol,int& size,vector<vector<char>>&grid)
    {  
          queue<pair<pair<int, int>, pair<int, int>>> q;  // {{x, y}, {parent_x, parent_y}}
         q.push({{x, y}, {-1, -1}});
        visited[x][y]=1; 

        while(!q.empty())
        {
           auto [curr, parent] = q.front();
            int curr_x = curr.first;
            int curr_y = curr.second;
            int parent_x = parent.first; 
            int parent_y = parent.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int del_x=curr_x+delrow[i]; 
                int del_y=curr_y+delcol[i];

                if(del_x>=0 && del_y>=0 && del_x<visited.size() && del_y<visited[0].size() && grid[del_x][del_y]==original_char) 
                {
                   if (!visited[del_x][del_y])
                {
                    q.push({{del_x, del_y}, {curr_x, curr_y}});
                    visited[del_x][del_y] = 1;
                    size++;
                }
                else if (del_x != parent_x || del_y != parent_y)
                {
                    // Found visited node which is not parent => cycle
                    return true;
                }
                } 
                
            }
        }
        return false;
    }
};