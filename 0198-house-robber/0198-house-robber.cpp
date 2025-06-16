//1.via recursion:
// class Solution {
// public:
//     int rob(vector<int>& nums)  
//     {  
//         if(nums.size()==1)
//         {
//             return nums[0];
//         } 
       
//        int path1= maxAmountstolen(0,nums); 
//        int path2=maxAmountstolen(1,nums);
//         return max(path1,path2); 
//     } 
//     int maxAmountstolen(int ind ,vector<int>&nums)
//     {       
//             if(ind>=nums.size())
//             {
//                 return 0;
//             }
             
//             int take=nums[ind]+ maxAmountstolen(ind+2,nums); 
//             int skip= maxAmountstolen(ind+1,nums); 
//             return max(take,skip);
//     }
// };

//2.with the memoization:
// class Solution {
// public:
//     int rob(vector<int>& nums)  
//     {    
//         vector<int>dp(nums.size()+1,-1);
//         if(nums.size()==1)
//         {
//             return nums[0];
//         } 
       
//        int path1= maxAmountstolen(0,nums,dp); 
//        int path2=maxAmountstolen(1,nums,dp);
//         return max(path1,path2); 
//     } 
//     int maxAmountstolen(int ind ,vector<int>&nums,vector<int>&dp)
//     {       
//             if(ind>=nums.size())
//             {
//                 return 0;
//             } 
//             if(dp[ind]!=-1)
//             {
//                 return dp[ind];
//             }
             
//             int take=nums[ind]+ maxAmountstolen(ind+2,nums,dp); 
//             int skip= maxAmountstolen(ind+1,nums,dp); 
//             return dp[ind]=max(take,skip);
//     }
// }; 

//3.via the tabulzation: vector<int>dp ka declaration , nested loop ka declaration : 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);  // dp[0...n-1]

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }
};
