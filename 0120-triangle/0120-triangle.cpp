class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)  
    {
        int n=triangle.size(); 
        int m=triangle[0].size(); 
         int sum=0;   
         vector<vector<int>>dp(n); 
        //  vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(triangle[i].size(), -1);
        }

         if(triangle.size()==1)
         {
            return triangle[0][0]; 
         }  
         return countMinpath(triangle,sum,0,0,dp);
         
    } 
    int countMinpath(vector<vector<int>>&Triangle,int& sum,int i, int j,vector<vector<int>>&dp)
    {
         
         if (i >= Triangle.size() || j >= Triangle[i].size()) {
    return 1e9; // Large value to avoid choosing this path
} 

        if(i==Triangle.size()-1)
        {
            return Triangle[i][j];
        }
          
        
         if(dp[i][j]!=-1)
         {
            return dp[i][j];
         }
         int first=countMinpath(Triangle,sum,i+1,j,dp); 
         int second=countMinpath(Triangle,sum,i+1,j+1,dp);
         return dp[i][j]=Triangle[i][j]+min(first,second);
    }
};