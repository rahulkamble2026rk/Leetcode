class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)  
    {
      int m=grid.size(); 
        int n=grid[0].size();  
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return count(m-1,n-1,grid,dp);
    } 
    int count(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
    {    
        if(i<0 || j<0)   //this part will get consider
        {
            return INT_MAX;
        }  

        if(i==0 && j==0) 
        {
            return obstacleGrid[0][0];
        }  

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        
        
        int up = (i > 0) ?count(i-1,j,obstacleGrid,dp): INT_MAX;
       int left = (j > 0) ?count(i,j-1,obstacleGrid,dp) : INT_MAX;
        return dp[i][j]=obstacleGrid[i][j]+min(up,left);
    } 
};