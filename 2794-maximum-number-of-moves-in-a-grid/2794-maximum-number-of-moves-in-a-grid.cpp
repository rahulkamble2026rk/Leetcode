class Solution {
public: 
int maxMoves(int r,int c,vector<vector<int>>&grid,int** memo)
    {
        if(memo[r][c]!=-1)
        {
            return memo[r][c];
        }  
        int maxmoves=0;
        if(r-1>=0 && c+1<grid[0].size() && grid[r-1][c+1]>grid[r][c])
        {
            maxmoves=1+maxMoves(r-1,c+1,grid,memo);
        } 
        if(c+1<grid[0].size() && grid[r][c+1]>grid[r][c]) 
        {
            maxmoves=max(maxmoves,1+maxMoves(r,c+1,grid,memo));
        } 
        if(r+1<grid.size() && c+1<grid[0].size() && grid[r+1][c+1]>grid[r][c])
        {
            maxmoves=max(maxmoves,1+maxMoves(r+1,c+1,grid,memo));
        } 
        return memo[r][c]=maxmoves;
    }
    int maxMoves(vector<vector<int>>& grid) 
    {
        int r=grid.size(); 
        int c=grid[0].size(); 
        int** memo=new int*[r]; 
        for(int i=0;i<r;i++)
        { 
            memo[i]=new int[c];
            for(int j=0;j<c;j++)
            {
                memo[i][j]=-1;
            }
        } 
       
        int maxi=INT_MIN; 
        for(int i=0;i<r;i++)
        {
            memo[i][0]=maxMoves(i,0,grid,memo);
        }
        for(int i=0;i<r;i++)
        {
          maxi=max(maxi,memo[i][0]);
        } 
        return maxi;
    } 
    
};