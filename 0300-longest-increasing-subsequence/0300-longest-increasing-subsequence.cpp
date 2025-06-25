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


class Solution {
public:
    int lengthOfLIS(vector<int>& nums)  
    {  
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));  
        //we wana to store the ind and prev_index , but the intailly the prev_index is getting start from the -1 , so which not feasible for us , to access the -1
        return LIS(nums, 0, -1,dp);
    }

    int LIS(vector<int>& nums, int ind, int prev_index,vector<vector<int>>&dp) {
        if (ind == nums.size()) {
            return 0;
        }

        if(dp[ind][prev_index+1]!=-1)     ///Beacause if we use prev_index=-1 intiallly then that might be wrong , so prev_index+1
        {
            return dp[ind][prev_index+1];
        }
        int not_take = LIS(nums, ind + 1, prev_index,dp);
        int take = INT_MIN;
        if (prev_index == -1 || nums[ind] > nums[prev_index]) {
            take = 1 + LIS(nums, ind + 1, ind,dp);
        }

        return dp[ind][prev_index+1]=max(take, not_take);
    }
};
