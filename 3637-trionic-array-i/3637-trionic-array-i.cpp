class Solution {
public:
    bool isTrionic(vector<int>& nums)  
    {
        if (nums.size() < 4)
        {
            return false;
        } 

        int i = 0;   
        int n = nums.size();
        
        for (i = 0; i + 1 < n && nums[i] < nums[i+1]; i++)
        {
            if (nums[i] == nums[i+1])
            {
                return false;
            }
        } 
        if (i == 0 || i >= n-2)
        {
            return false;
        } 

        for (; i + 1 < n && nums[i] > nums[i+1]; i++)
        {
            if (nums[i] == nums[i+1])
            {
                return false;
            }
        } 
        if (i == n-1 || i < 2)
        {
            return false;
        } 

        for (; i + 1 < n && nums[i] < nums[i+1]; i++) 
        {
            if (nums[i] == nums[i+1])
            {
                return false;
            }
        } 
        if (i < n-1)
        {
            return false;
        }  

        return true;
    }
};