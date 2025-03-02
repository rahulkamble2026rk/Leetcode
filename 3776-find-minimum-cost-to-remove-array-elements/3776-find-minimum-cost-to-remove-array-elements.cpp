class Solution {
public:
    int minCost(vector<int>& nums) 
    {
        int n=nums.size(); 
        if(n<=2)
        {
            return *max_element(nums.begin(),nums.end());
        } 
        //first idx, prev 
        vector<vector<int>>dp(n,vector<int>(n,-1)); 
        return helper(0,1,nums,dp);
    } 

    int helper(int ext,int ind,vector<int>&nums, vector<vector<int>>&dp)
    {
       //single element
        if(ind==nums.size())
        {
            return nums[ext];
        } 

        //2 elements left
        if(ind==nums.size()-1)
        {
            return max(nums[ext],nums[ind]);
        } 

        if(dp[ind][ext]!=-1)
        {
            return dp[ind][ext];
        } 
        

        int f=max(nums[ind],nums[ind+1])+helper(ext,ind+2,nums,dp); 
        int s=max(nums[ext],nums[ind+1])+helper(ind,ind+2,nums,dp); 
        int t=max(nums[ext],nums[ind])+helper(ind+1,ind+2,nums,dp); 
        return dp[ind][ext]=min({f,s,t});
    }
};