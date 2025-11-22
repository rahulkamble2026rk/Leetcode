class Solution {
public:
    int minimumOperations(vector<int>& nums)  
    {
        //currently we have 1: like 1-1 =0 have the full divisior of 3 
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int rem=nums[i]%3; 
            if(rem==1 || rem==2)
            {
                ans++;
            } 
           
        } 
        return ans;
    }
};