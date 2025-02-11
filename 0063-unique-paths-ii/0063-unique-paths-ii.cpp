// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
//     {   
//         int m=obstacleGrid.size(); 
//         int n=obstacleGrid[0].size();  
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return count(m-1,n-1,obstacleGrid,dp);
//     } 
//     int count(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
//     {   
//         if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
//         {
//             return 0;
//         } 
//         if(i<0 || j<0)
//         {
//             return 0;
//         }  

//         if(dp[i][j]!=-1)
//         {
//             return dp[i][j];
//         }
//         if(i==0 && j==0) 
//         {
//             return 1;
//         } 
        

//         int up=count(i-1,j,obstacleGrid,dp); 
//         int left=count(i,j-1,obstacleGrid,dp); 
//         return dp[i][j]=up+left;
//     }
// }; 



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {   
        int m=obstacleGrid.size(); 
        int n=obstacleGrid[0].size();   
        vector<vector<int>>dp(m,vector<int>(n,-1)); 
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                } 
                else if(i==0 && j==0)
                {
                    dp[i][j]=1;
                } 
                else
                {    
                    int up=0;
                    int left=0;
                    if(i>=1)
                    {
                        up=dp[i-1][j];
                    } 
                    if(j>=1)
                    {
                        left=dp[i][j-1];
                    } 
                    dp[i][j]=up+left;
                }
            }
        } 
        return dp[m-1][n-1];
    }
};