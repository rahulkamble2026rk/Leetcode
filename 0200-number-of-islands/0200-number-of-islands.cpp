class Solution {
public:
    int numIslands(vector<vector<char>>& grid)  
    { 
        int m=grid.size(); 
        int n=grid[0].size(); 
        int islands=0; 
        vector<int>delrow={0,0,+1,-1}; 
        vector<int>delcol={+1,-1,0,0};
        vector<vector<int>>visited(m,vector<int>(n,0)); 
        for(int i=0;i<visited.size();i++)
        {
            for(int j=0;j<visited[i].size();j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    islands++;  
                    dfs(visited,grid[i][j],i,j,grid,delrow,delcol);
                }
            }
        } 
        return islands;
    } 

    void dfs(vector<vector<int>>&visited,char ch,int x,int y,vector<vector<char>>& grid,vector<int>delrow,vector<int>delcol) 
    {
            visited[x][y]=1; 
           for(int i=0;i<4;i++)
           {
            int new_x=x+delrow[i]; 
            int new_y=y+delcol[i]; 

            if(new_x>=0 && new_x<visited.size() && new_y>=0 && new_y<visited[0].size() && visited[new_x][new_y]!=1 && grid[new_x][new_y]=='1')
            {   
                /*  if we remove tehj grid[new_x][new_y]=='1' , our DFS will visit and mark water ('0') as visited.
                    You’ll end up merging land and water into one component.
                    You may incorrectly count water as part of an island.*/
                dfs(visited,grid[new_x][new_y],new_x,new_y,grid,delrow,delcol);
            }
           }
    }
};