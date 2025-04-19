class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        long long count=0;  
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
           int left = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;

            
            if (left <= right) {
                count += (right - left + 1);
            }
               
        } 
        return count;
    }
};