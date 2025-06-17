// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
//     {  
//         //1.by using the recusrsion 
//         return totaluniquepath(obstacleGrid,0,0);
//     } 
//     int totaluniquepath(vector<vector<int>>& obstacleGrid,int i, int j)
//     {   
//          if( (i>=obstacleGrid.size() || j>=obstacleGrid[0].size()) ||(obstacleGrid[i][j]==1)) 
//         {
//             return 0;
//         } 
//         if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1)
//         {
//             return 1;
//         } 
        
//         int right=totaluniquepath(obstacleGrid,i,j+1); 
//         int down=totaluniquepath(obstacleGrid,i+1,j); 
//         return right+down;
//     }
// }; 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {  
        //1.by using the Memoization:  
        int m=obstacleGrid.size(); 
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return totaluniquepath(obstacleGrid,0,0,dp);
    } 
    int totaluniquepath(vector<vector<int>>& obstacleGrid,int i, int j,vector<vector<int>>&dp)
    {   
         if( (i>=obstacleGrid.size() || j>=obstacleGrid[0].size()) ||(obstacleGrid[i][j]==1)) 
        {
            return 0;
        } 
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1)
        {
            return 1;
        } 
         
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right=totaluniquepath(obstacleGrid,i,j+1,dp); 
        int down=totaluniquepath(obstacleGrid,i+1,j,dp); 
        return dp[i][j]=right+down;
    }
};