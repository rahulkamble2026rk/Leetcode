class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int>vct;  
       
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
                vct.push_back(nums[i]);
            }
        } 

         for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==pivot)
            {
                vct.push_back(nums[i]);
            }
        } 
         for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>pivot)
            {
                vct.push_back(nums[i]);
            }
        } 
        return vct;
    }
};