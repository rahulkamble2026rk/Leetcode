class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        while(nums.size()!=1)
        {
            vector<int>vct; 
            for(int i=0;i<nums.size()-1;i++)
            {
                vct.push_back((nums[i]+nums[i+1])%10);
            } 
            nums=vct; 
            vct.clear();
        } 
        return nums[0];
    }
};