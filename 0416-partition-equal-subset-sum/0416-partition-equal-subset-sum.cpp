class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum=accumulate(nums.begin(),nums.end(),0);  
        int n=nums.size();  
        int target=sum/2; 
        if(sum%2)
        {
            return false;
        }  
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return partition(n-1,target,nums,dp);
    } 
    bool partition(int ind,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(target==0) 
        { 
            return true;
        } 
        if(ind==0)
        {
            return (nums[ind]==target);
        } 

        if(dp[ind][target]!=-1)
        {
            return dp[ind][target];
        }
        bool nottake=partition(ind-1,target,nums,dp); 
        bool take=false;
        if(target>=nums[ind])
        {
            take=partition(ind-1,target-nums[ind],nums,dp);
        } 
        return dp[ind][target]=(take||nottake);
    }
};

//tabulazation appraoch :