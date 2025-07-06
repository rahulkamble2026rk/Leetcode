// class Solution {
// public:
//     bool canPartition(vector<int>& nums) 
//     {
//         //we cannot divide the if the sum is odd 
//         int sum=accumulate(nums.begin(),nums.end(),0); 
//         if(sum%2!=0)
//         {
//             return false;
//         }   
//         int target=sum/2;
//         vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
//         return check(nums,0,sum/2,dp);
//     } 

//     bool check(vector<int>&nums,int ind,int target,vector<vector<int>>&dp)
//     {    
//         if(target==0)
//         {
//             return 1;
//         }  
//          if(ind>=nums.size())
//         {
//             return 0;
//         } 
//         if(dp[ind][target]!=-1)
//         {
//             return dp[ind][target];
//         }
        
       
//         int nottake=check(nums,ind+1,target,dp); 
//         int take=0; 
//         if(target>=nums[ind])
//         {
//             take=check(nums,ind+1,target-nums[ind],dp);
//         } 
//         return dp[ind][target]=(take||nottake);
//     }
// }; 


class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        //we cannot divide the if the sum is odd 
        int sum=accumulate(nums.begin(),nums.end(),0); 
        if(sum%2!=0)
        {
            return false;
        }    

   
        int n = nums.size();
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        // Base case: empty subset can achieve sum 0
        for (int i = 0; i <= n; i++) 
        {
            dp[i][0] = true;
        } 

         for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                // Don't take the current element
              int nottake=dp[i - 1][j];
                
                // Take the current element if possible 

                int take=false;
                if (j >= nums[i - 1])  
                {  
                     take=dp[i - 1][j - nums[i - 1]];
                } 
                dp[i][j] = nottake|| take;
            }
        } 
          return dp[n][target];
    } 

   
};