class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k)  
    {
        //we have to return true if all 1's are at least k places away from each other  
        vector<int>vct; 
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                vct.push_back(i);
            }
        }  
        if(vct.empty())
        {
            return true;
        }

        for(int v=0;v<vct.size()-1;v++)
        {
            if( (vct[v+1]-vct[v])-1<k) 
            {
                return false;
            }
        } 

        return true;
    }
};