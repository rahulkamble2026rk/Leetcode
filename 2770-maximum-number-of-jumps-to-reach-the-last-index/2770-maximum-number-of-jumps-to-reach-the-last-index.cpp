// class Solution {
// public:
//     int maximumJumps(vector<int>& nums, int target)  
//     {
//         //YOU ARE intially at 0th indiex of nums and integer target 
//         // you can jump from index i to any index j such that 

//         // 0<=i<j<n 
//         //  i-> j ,  
//         // jab  
//         // int result=nums[j]-nums[i] ansd result>=-target and result<=target 

//         //maximum jumsp to reach n-1 , if there is no way return -1 : 

//          //this loop will sends the index only to the function 

//          vector<int>dp; 
//          dp.resize(nums.size(),-2); 

//          return chk(0,nums,target,dp);
//     } 

//     int chk(int ind,vector<int>nums,int target,vector<int>&dp 
// )
//     {   
//         if(ind==nums.size()-1)
//         {
//             return 0;
//         } 

//         if(dp[ind]!=-2)
//         {
//             return dp[ind];
//         }
        
//         int ans=-1; 

        
//         for(int j=ind+1;j<nums.size();j++)
//         { 
//             long long result=1LL*nums[j]-nums[ind];  

//             if(result>=-target && result<=target)
//             {
//                 int next=chk(j,nums,target,dp); 

//                 if(next!=-1)
//                 {
//                     ans=max(ans,1+next);
//                 }
//             }
            
//         } 
//         return dp[ind]=ans; 

        
//     }
// }; 

class Solution {
public:

    int maximumJumps(vector<int>& nums, int target)  
    {
        int n = nums.size();

        vector<int> dp(n, -1);

        // last index needs 0 jumps
        dp[n - 1] = 0;

        for(int ind = n - 2; ind >= 0; ind--)
        {
            for(int j = ind + 1; j < n; j++)
            {
                long long result = 1LL * nums[j] - nums[ind];

                if(result >= -target && result <= target)
                {
                    if(dp[j] != -1)
                    {
                        dp[ind] = max(dp[ind], 1 + dp[j]);
                    }
                }
            }
        }

        return dp[0];
    } 
};