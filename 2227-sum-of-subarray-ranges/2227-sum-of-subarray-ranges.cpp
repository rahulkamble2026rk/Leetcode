class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        long long ans=0; 
        int mini=INT_MAX;  
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {   
            mini=nums[i]; 
            maxi=nums[i];
            for(int j=i;j<nums.size();j++)
            {
                mini=min(mini,nums[j]); 
                maxi=max(maxi,nums[j]); 
                ans+=maxi-mini;
            }
        } 
        return ans;
    }
};