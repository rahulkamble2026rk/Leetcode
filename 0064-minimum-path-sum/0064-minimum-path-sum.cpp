
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {  
        //1.by using the Memoization:  
        int m=grid.size(); 
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return totaluniquepath(grid,0,0,dp);
    } 
    int totaluniquepath(vector<vector<int>>& obstacleGrid,int i, int j,vector<vector<int>>&dp)
    {   
         if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size()) 
        {
            return 1e9;
        } 
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1)
        {
            return obstacleGrid[i][j];
        } 
         
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right=totaluniquepath(obstacleGrid,i,j+1,dp); 
        int down=totaluniquepath(obstacleGrid,i+1,j,dp); 
        return dp[i][j]=obstacleGrid[i][j]+min(right,down);
    }
}; 
