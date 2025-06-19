class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {   
        int ans=0;
        for(int i=i=0;i<nums.size();i++)
        {
            int lb=lower_bound(nums.begin(),nums.end(),nums[i])-nums.begin(); 
            int ub=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();  
            int count=ub-lb;  
            if(count==1)
            {
                ans=nums[i];
                break;
            }
        } 
        return ans;

    }
};