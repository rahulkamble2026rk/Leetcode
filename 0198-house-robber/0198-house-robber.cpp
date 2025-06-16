class Solution {
public:
    int rob(vector<int>& nums)  
    {    
        vector<int>dp(nums.size()+1,-1);
        if(nums.size()==1)
        {
            return nums[0];
        } 
       
       int path1= maxAmountstolen(0,nums,dp); 
       int path2=maxAmountstolen(1,nums,dp);
        return max(path1,path2); 
    } 
    int maxAmountstolen(int ind ,vector<int>&nums,vector<int>&dp)
    {       
            if(ind>=nums.size())
            {
                return 0;
            } 
            if(dp[ind]!=-1)
            {
                return dp[ind];
            }
             
            int take=nums[ind]+ maxAmountstolen(ind+2,nums,dp); 
            int skip= maxAmountstolen(ind+1,nums,dp); 
            return dp[ind]=max(take,skip);
    }
};