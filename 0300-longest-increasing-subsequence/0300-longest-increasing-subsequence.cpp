// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums)  
//     {
//         //we have to find the increasing subsequence: subsequence means either take or not take and also contain the previous element index so in the future we can take the increasing numbers only , so :
//         return LIS(nums,0, -1);   // intially take the previos index as -1
//     }  

//     int LIS(vector<int>&nums,int ind ,int prev_index) 
//     {
//         //Base condition: 
//         if(ind==nums.size())
//         {
//             return 0;
//         }
//          //either take , or not 

//          int not_take=0+LIS(nums,ind+1,prev_index); //as we does not take current element so prev index remains same 
          
//           int take=-1e9; 
//           if(prev_index==-1 || nums[ind]>nums[prev_index])
//           {
//              take=1+LIS(nums,ind+1,ind);   //current element will become the next element's prev index;
//           } 
//           return max(take,not_take);
    
//     }

// };


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums)  
//     {  
//         vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));  
//         //we wana to store the ind and prev_index , but the intailly the prev_index is getting start from the -1 , so which not feasible for us , to access the -1
//         return LIS(nums, 0, -1,dp);
//     }

//     int LIS(vector<int>& nums, int ind, int prev_index,vector<vector<int>>&dp) {
//         if (ind == nums.size()) {
//             return 0;
//         }

//         if(dp[ind][prev_index+1]!=-1)     ///Beacause if we use prev_index=-1 intiallly then that might be wrong , so prev_index+1
//         {
//             return dp[ind][prev_index+1];
//         }
//         int not_take = LIS(nums, ind + 1, prev_index,dp);
//         int take = INT_MIN;
//         if (prev_index == -1 || nums[ind] > nums[prev_index]) {
//             take = 1 + LIS(nums, ind + 1, ind,dp);
//         }

//         return dp[ind][prev_index+1]=max(take, not_take);
//     }
// }; 


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums)  
//     { 
//         vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0)); 
//         //as we cannot access the -1 index of the dp table so that's why we are using the nums.size()+1 

//         for(int ind=nums.size()-1;ind>=0;ind--)
//         {
//             for(int prev_index=ind-1;prev_index>=-1;prev_index--)
//             {
//                 int not_take = dp[ind + 1][prev_index+1];
//                 int take = INT_MIN;
//                 if (prev_index == -1 || nums[ind] > nums[prev_index])  
//                 {
//                     take = 1 + dp[ind+1][ind+1];
//                 } 
//                 dp[ind][prev_index+1]=max(take,not_take);
        
//             }
//         } 
//         return dp[0][-1+1];
//     }
// };


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums)  
//     { 
//         vector<int>next(nums.size()+1,0) ,curr(nums.size()+1,0);
        
//         for(int ind=nums.size()-1;ind>=0;ind--)
//         {
//             for(int prev_index=ind-1;prev_index>=-1;prev_index--)
//             {
//                 int not_take = next[prev_index+1];
//                 int take = INT_MIN;
//                 if (prev_index == -1 || nums[ind] > nums[prev_index])  
//                 {
//                     take = 1 + next[ind+1];
//                 } 
//                 curr[prev_index+1]=max(take,not_take);
        
//             } 
//             next=curr;
//         } 
//         return next[0];
//     }
// };
 

//4.space optimization is nothing but techique in  which keep the whole code of the tabulation as it is
//take one curr, next vector 
//in the code use the next 
//in the storing current use the curr
//replace next=curr;
//return next[-1][1];  


class Solution {
public:
    int lengthOfLIS(vector<int>& nums)  
    {  
        vector<int>dp(nums.size(),1); //Intially the length of the lis of the all number will be 1,by default   


        //comparing with the previos elements and check 

        int maxi=1;
        for(int ind=0;ind<nums.size();ind++)
        {
            for(int prev=0;prev<ind;prev++)
            {
                if(nums[prev]<nums[ind])
                {
                    dp[ind]=max(dp[ind],1+dp[prev]);
                }
            } 
            maxi=max(maxi,dp[ind]);
        } 
        return maxi; 
    }
};