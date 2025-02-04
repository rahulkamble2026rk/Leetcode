class Solution {
public:
    int maxAscendingSum(vector<int>& nums)  
    {
        int maxi=nums[0]; 
        int store=0; 
        int i=0; 
        int j=i+1; 
        while(j<nums.size())
        {
            if(nums[j]>nums[i])
            {
                maxi+=nums[j];
            } 
            else
            {
                store=max(store,maxi); 
                maxi=nums[j];
            } 
            i++; 
            j++;
        }  
         store=max(store,maxi); 
        return store;
    }
};