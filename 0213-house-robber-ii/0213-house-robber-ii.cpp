class Solution {
public:
    int rob(vector<int>& nums) 
    {
        //forming the two vector  
        if (nums.size() == 1) return nums[0]; 
        vector<int>vct1;  
        vector<int>vct2; 
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
            {
                vct1.push_back(nums[i]);
            } 
            if(i!=nums.size()-1)
            {
                vct2.push_back(nums[i]);
            }
        } 
        return max(maxrob(vct1),maxrob(vct2));

    } 

    int maxrob(vector<int>&nums)
    {
        int n=nums.size();  
        vector<int>dp(n,-1); 
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick=nums[i]; 
            if(i>1)
            {
                pick+=dp[i-2];
            } 
            int notpick=0+dp[i-1]; 
            dp[i]=max(pick,notpick);
        }
        return dp[n-1]; 
    }
};