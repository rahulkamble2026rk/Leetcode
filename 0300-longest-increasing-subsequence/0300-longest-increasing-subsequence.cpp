// // class Solution {
// // public:
// //     int lengthOfLIS(vector<int>& nums)  
// //     {
// //         //we have to find the increasing subsequence: subsequence means either take or not take and also contain the previous element index so in the future we can take the increasing numbers only , so :
// //         return LIS(nums,0, -1);   // intially take the previos index as -1
// //     }  

// //     int LIS(vector<int>&nums,int ind ,int prev_index) 
// //     {
// //         //Base condition: 
// //         if(ind==nums.size())
// //         {
// //             return 0;
// //         }
// //          //either take , or not 

// //          int not_take=0+LIS(nums,ind+1,prev_index); //as we does not take current element so prev index remains same 
          
// //           int take=-1e9; 
// //           if(prev_index==-1 || nums[ind]>nums[prev_index])
// //           {
// //              take=1+LIS(nums,ind+1,ind);   //current element will become the next element's prev index;
// //           } 
// //           return max(take,not_take);
    
// //     }

// // };


// // class Solution {
// // public:
// //     int lengthOfLIS(vector<int>& nums)  
// //     {  
// //         vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));  
// //         //we wana to store the ind and prev_index , but the intailly the prev_index is getting start from the -1 , so which not feasible for us , to access the -1
// //         return LIS(nums, 0, -1,dp);
// //     }

// //     int LIS(vector<int>& nums, int ind, int prev_index,vector<vector<int>>&dp) {
// //         if (ind == nums.size()) {
// //             return 0;
// //         }

// //         if(dp[ind][prev_index+1]!=-1)     ///Beacause if we use prev_index=-1 intiallly then that might be wrong , so prev_index+1
// //         {
// //             return dp[ind][prev_index+1];
// //         }
// //         int not_take = LIS(nums, ind + 1, prev_index,dp);
// //         int take = INT_MIN;
// //         if (prev_index == -1 || nums[ind] > nums[prev_index]) {
// //             take = 1 + LIS(nums, ind + 1, ind,dp);
// //         }

// //         return dp[ind][prev_index+1]=max(take, not_take);
// //     }
// // }; 


// // class Solution {
// // public:
// //     int lengthOfLIS(vector<int>& nums)  
// //     { 
// //         vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0)); 
// //         //as we cannot access the -1 index of the dp table so that's why we are using the nums.size()+1 

// //         for(int ind=nums.size()-1;ind>=0;ind--)
// //         {
// //             for(int prev_index=ind-1;prev_index>=-1;prev_index--)
// //             {
// //                 int not_take = dp[ind + 1][prev_index+1];
// //                 int take = INT_MIN;
// //                 if (prev_index == -1 || nums[ind] > nums[prev_index])  
// //                 {
// //                     take = 1 + dp[ind+1][ind+1];
// //                 } 
// //                 dp[ind][prev_index+1]=max(take,not_take);
        
// //             }
// //         } 
// //         return dp[0][-1+1];
// //     }
// // };


// // class Solution {
// // public:
// //     int lengthOfLIS(vector<int>& nums)  
// //     { 
// //         vector<int>next(nums.size()+1,0) ,curr(nums.size()+1,0);
        
// //         for(int ind=nums.size()-1;ind>=0;ind--)
// //         {
// //             for(int prev_index=ind-1;prev_index>=-1;prev_index--)
// //             {
// //                 int not_take = next[prev_index+1];
// //                 int take = INT_MIN;
// //                 if (prev_index == -1 || nums[ind] > nums[prev_index])  
// //                 {
// //                     take = 1 + next[ind+1];
// //                 } 
// //                 curr[prev_index+1]=max(take,not_take);
        
// //             } 
// //             next=curr;
// //         } 
// //         return next[0];
// //     }
// // };
 

// //4.space optimization is nothing but techique in  which keep the whole code of the tabulation as it is
// //take one curr, next vector 
// //in the code use the next 
// //in the storing current use the curr
// //replace next=curr;
// //return next[-1][1];  


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums)  
//     {  
//         vector<int>dp(nums.size(),1); //Intially the length of the lis of the all number will be 1,by default   


//         //comparing with the previos elements and check 

//         int maxi=1; 

//         //take one more vector which will store the index of the parent that ,from where it is coming , so we will go back easily 
//         vector<int>parent(nums.size()); 
//         int lastindex=0; //keep the track of the lastindex
//         for(int ind=0;ind<nums.size();ind++)
//         {    
//             parent[ind]=ind;
//             for(int prev=0;prev<ind;prev++)
//             {
//                 if(nums[prev]<nums[ind] && 1+dp[prev]>dp[ind])
//                 {
//                     dp[ind]=1+dp[prev]; 
//                     parent[ind]=prev;
//                 }
//             } 

//             if(dp[ind]>maxi)                
//             {
//                 maxi=dp[ind]; 
//                 lastindex=ind;
//             }
//             maxi=max(maxi,dp[ind]);
//         } 



//         //now recontrcuint the vector 

//         vector<int>ans; 
//         ans.push_back(nums[lastindex]); 

//         while(parent[lastindex]!=lastindex)
//         {
//             lastindex=parent[lastindex]; 
//             ans.push_back(nums[lastindex]);
//         }  

//         reverse(ans.begin(),ans.end()); 
//         for(auto it:ans)
//         {
//             cout<<it<<" ";
//         }
//         return maxi; 
//     }
// }; 


//Another approch to finding the length of the via the binary serach  

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)  
    {     
        vector<int>ans; 
        ans.push_back(nums[0]); 
     

     // 1 4 5 4 7 8 
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans.back())
            {
                ans.push_back(nums[i]);
            } 
            else 
            {
                int lower_index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin(); 
                ans[lower_index]=nums[i];
            }
        } 

        return ans.size();
    }
};