class Solution {
public:
    int lengthOfLIS(vector<int>& nums)  
    { 
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return maxlengthLIS(nums,0,-1,dp);
    }  
    int maxlengthLIS(vector<int>&nums,int ind,int prev, vector<vector<int>>&dp)
    {
        if(ind>=nums.size())
        {
            return 0;
        } 
        if(dp[ind][prev+1]!=-1)
        {
            return dp[ind][prev+1];
        }
        int len1=0+maxlengthLIS(nums,ind+1,prev,dp);  //not take  
        int len2=0;
        if(prev==-1 || nums[ind]>nums[prev])
        {
             len2=1+maxlengthLIS(nums,ind+1,ind,dp);
        } 
        return dp[ind][prev+1]=max(len1,len2);
    }

};