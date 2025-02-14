class Solution {
public: 
    bool canPartition(vector<int>& nums) 
    { 
        int sumtotal = accumulate(nums.begin(), nums.end(), 0); 
        if (sumtotal % 2) 
        {
            return false;
        }
        int target=sumtotal/2;
        vector<vector<int>>dp(nums.size() + 1, vector<int>(target + 1, 0)); 
        int n=nums.size();
        for (int i = 0; i <= n; i++) 
        {
            dp[i][0] = true;  //0th col means capacity 0ke liye 
        }  
        // Initialize 0th row to false (except dp[0][0])
        for (int j = 1; j <= target; j++) {
            dp[0][j] = false;
        } 
   
     return dpapproach(nums,target,nums.size(),dp);
        
    }  

    int dpapproach(vector<int>&nums,int target,int n,vector<vector<int>>dp)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                if(nums[i-1]<=j)
                {
                    int pi=dp[i-1][j-nums[i-1]]; 
                    int pe=dp[i-1][j]; 
                    dp[i][j] =pi||pe;
                } 
                else 
                {
                    dp[i][j]=dp[i-1][j];
                }
            } 
           
         }
          return dp[n][target];
    }

    
};
