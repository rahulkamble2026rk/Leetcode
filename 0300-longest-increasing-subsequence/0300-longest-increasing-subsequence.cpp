// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums)  
//     { 
//         vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
//         return maxlengthLIS(nums,0,-1,dp);
//     }  
//     int maxlengthLIS(vector<int>&nums,int ind,int prev, vector<vector<int>>&dp)
//     {
//         if(ind>=nums.size())
//         {
//             return 0;
//         } 
//         if(dp[ind][prev+1]!=-1)
//         {
//             return dp[ind][prev+1];
//         }
//         int len1=0+maxlengthLIS(nums,ind+1,prev,dp);  //not take  
//         int len2=0;
//         if(prev==-1 || nums[ind]>nums[prev])
//         {
//              len2=1+maxlengthLIS(nums,ind+1,ind,dp);
//         } 
//         return dp[ind][prev+1]=max(len1,len2);
//     }

// }; 


class Solution {
public:
    int lengthOfLIS(vector<int>& nums)  
    { 
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0)); 

        for(int ind=nums.size()-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                int not_take=dp[ind+1][prev+1]; 
                int take=0; 

                if(prev==-1 || nums[ind]>nums[prev])
                {
                    take=1+dp[ind+1][ind+1];
                } 
                dp[ind][prev+1]=max(take,not_take);
            }
        }
        return dp[0][0];
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