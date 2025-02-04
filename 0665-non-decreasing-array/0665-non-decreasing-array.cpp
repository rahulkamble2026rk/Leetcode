class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        if(is_sorted(nums.begin(),nums.end()))
        {
            return true;
        }  
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1] )
            {  
                if(i==0||nums[i-1]<=nums[i+1])
                {
                    nums[i]=nums[i+1]; 
                    break;
                } 
                else
                {
                    nums[i+1]=nums[i];break;
                }
            }     
        } 
            if(is_sorted(nums.begin(),nums.end()))
            {
                return true; 
            } 
                return false;
    }
};