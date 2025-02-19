class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {  
        int count=0;
        findcount(nums,target,count,0,0); 
        return count;
    } 
    void findcount(vector<int>&nums,int target,int& count,int index ,int sum)
    {
        if(index==nums.size())
        {
            if(sum==target)
            {
                count++;
            } 
            return;
        } 
        findcount(nums,target,count,index+1,sum+nums[index]); 
         findcount(nums,target,count,index+1,sum-nums[index]); 
    }
};