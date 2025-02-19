class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size(); 
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return longestLIS(n - 1, n, nums,dp);  
    } 

    int longestLIS(int ind, int prev, vector<int>& nums,vector<vector<int>>&dp)
    {
        if (ind == 0)  
        {
            if (prev == nums.size() || nums[0] < nums[prev])  
                {
                    return 1;
                }
            return 0;
        }

        if(dp[ind][prev]!=-1)
        {
            return dp[ind][prev];
        }
        int nottake = longestLIS(ind - 1, prev, nums,dp);
        int take = 0;

        if (prev==nums.size()||nums[ind] < nums[prev]) 
        {   
            take = 1 + longestLIS(ind - 1, ind, nums,dp);
        }

        return dp[ind][prev]=max(take, nottake);
    }
};
