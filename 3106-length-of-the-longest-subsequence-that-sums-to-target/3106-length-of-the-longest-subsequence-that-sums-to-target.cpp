// class Solution {
// public:
//     int lengthOfLongestSubsequence(vector<int>& nums, int target) 
//     { 
//         int n=nums.size(); 
//         vector<vector<int>>dp(n,vector<int>(target+1,-1));
//         int ans=maxlength(n-1,target,nums,dp);   
        
//         return (ans<0)?-1:ans;
//     } 
//     int maxlength(int ind,int target,vector<int>&nums,vector<vector<int>>&dp)
//     {
//         if(target==0)
//         {
//             return 0;
//         }  
//         if(dp[ind][target]!=-1)
//         {
//             return dp[ind][target];
//         }
//         if(ind==0)
//         {
//             return (nums[0]==target?1:-1e9);
//         } 
//         int nottake=0+maxlength(ind-1,target,nums,dp); 
//         int take=-1e9; 
//         if(target>=nums[ind])
//         {
//             take=1+maxlength(ind-1,target-nums[ind],nums,dp);
//         }  
//         return dp[ind][target]=max(nottake,take);

//     }
// }; 

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) 
    { 
        int n=nums.size(); 
        vector<vector<int>>dp(n,vector<int>(target+1,-1e9)); 

        //write the base condtion(tabulazation): 

          // Base Case: If target == 0, subsequence length is 0
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        if (nums[0] <= target) {
            dp[0][nums[0]] = 1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                int nottake=dp[i-1][j]; 
                int take=-1e9;  
                if(j>=nums[i])
                {
                    take=1+dp[i-1][j-nums[i]];
                }
                dp[i][j]=max(nottake,take);
            }
        } 
        return (dp[n-1][target]<0)?-1:dp[n-1][target];
    }
};