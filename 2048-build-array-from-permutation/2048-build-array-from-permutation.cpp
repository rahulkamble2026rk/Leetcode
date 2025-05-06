class Solution {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        vector<int>mum;
        for(int i=0;i<nums.size();i++) 
        {
            mum.push_back(nums[nums[i]]);
        } 
        return mum;
    }
};