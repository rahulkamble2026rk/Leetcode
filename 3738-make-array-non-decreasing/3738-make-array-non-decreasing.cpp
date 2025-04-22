class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) 
    {
        if(is_sorted(nums.begin(),nums.end())) 
        {
            return nums.size();
        }  
    
        int prev=-1,count=0;
        for(int i:nums)
        {
            if(i>=prev)
            {
                count++;   //this is hte monostonic stack
                prev=i;
            }
        }
        return count;
    }
};