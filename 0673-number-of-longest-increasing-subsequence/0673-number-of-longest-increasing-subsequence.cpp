class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)  
    {
        //same code of hte priting and finding the lis of O(N^2) : 

        vector<int>dp(nums.size(),1);  
        vector<int>count(nums.size(),1);

            // 1 3 5 4 7
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && dp[j]+1 >dp[i])  //if the current element is greater than the previos element then only we will take it  
                {
                    dp[i]=dp[j]+1; 
                    count[i]=count[j]; // copy the count as it is
                } 
                else if(nums[i]>nums[j] && dp[j]+1==dp[i] )   //add karun suddha toch result yet asel tar 
                {
                    count[i]+=count[j];
                }
            }
        }  

        int maxi=*max_element(dp.begin(),dp.end());  
        int ans=0;
        for(int it=0;it<dp.size();it++)
        {
            if(dp[it]==maxi)
            {
                ans+=count[it];
            }
        } 
        return ans;
    }
}; 



//dp[j]+1 >dp[i] , Why this line ?
//: ->  previos subsquence current madhe add kela tar previos dp[j] madhe automcatic dp[j]+1 karave lagel for checking purpose