// class Solution {
// public:
//     int uniquePaths(int m, int n)  
//     {
//         return count(m-1,n-1);  //start from the end point of the grid 
//     } 
    
//     int count(int i,int j)
//     {
//         if(i==0 && j==0)     // 1.find the terminating , or 
//         {
//             return 1;
//         } 
         
//         if(i<0 || j<0)
//         {
//             return 0;
//         }
//         int up=count(i-1,j);    
//         int left=count(i,j-1); 
//         return up+left;
//     }
// }; 


class Solution {
public:
    int uniquePaths(int m, int n)  
    { 
        vector<vector<int>>dp(m,vector<int>(n,-1)); 

        return count(m-1,n-1,dp);  
    } 
    
    int count(int i,int j,vector<vector<int>>&dp)
    { 
        if(i<0 || j<0)
        {
            return 0;
        }
        if(i==0 && j==0)     
        {
            return 1;
        } 
          
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int up=count(i-1,j,dp);    
        int left=count(i,j-1,dp); 
        return dp[i][j]=up+left;
    }
};