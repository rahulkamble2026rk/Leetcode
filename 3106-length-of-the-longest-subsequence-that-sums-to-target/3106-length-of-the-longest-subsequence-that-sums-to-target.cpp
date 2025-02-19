class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) 
    { 
        int n=nums.size(); 
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans=maxlength(n-1,target,nums,dp);   
        
        return (ans<0)?-1:ans;
    } 
    int maxlength(int ind,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(target==0)
        {
            return 0;
        }  
        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        if(ind==0)
        {
            return (nums[0]==target?1:-1e9);
        } 
        int nottake=maxlength(ind-1,target,nums,dp); 
        int take=-1e9; 
        if(target>=nums[ind])
        {
            take=1+maxlength(ind-1,target-nums[ind],nums,dp);
        }  
        return dp[ind][target]=max(nottake,take);

    }
};