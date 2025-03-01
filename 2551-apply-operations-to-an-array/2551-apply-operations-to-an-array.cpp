class Solution {
public:
    vector<int> applyOperations(vector<int>& nums)  
    {
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]=nums[i]*2; 
                nums[i+1]=0;
            }
        } 
        int totalzero=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                totalzero++;
            }
        }  
        nums.erase(remove_if(nums.begin(), nums.end(), iszero), nums.end());
        for(int i=1;i<=totalzero;i++)
        {
            nums.push_back(0);
        } 
        return nums;
    } 
   static bool iszero(int num)
    {
        if(num==0)
        {
            return true;
        }
        return false;
    }
};