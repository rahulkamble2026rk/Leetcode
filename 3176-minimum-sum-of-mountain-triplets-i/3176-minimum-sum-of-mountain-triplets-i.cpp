class Solution {
public:
    int minimumSum(vector<int>& nums)  
    { 
        int mini=1e9;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {   
                    if(nums[i]<nums[j] && nums[k]<nums[j] && mini!=-1)
                    { 
                        mini=min(mini,(nums[i]+nums[j]+nums[k]));
                    }
                }
            }
        }   
        return mini==1e9?-1:mini;

    }
};