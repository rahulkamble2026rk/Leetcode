class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)  
    {
        priority_queue<int,vector<int>,greater<int>>que; 

        
        for(int i=0;i<k;i++)
        {
            que.push(nums[i]);
        }

        for(int i=k;i<nums.size();i++)
        {
            if(nums[i]>que.top())
            {
                que.pop();
                que.push(nums[i]);
            }
        } 

        
         
         return que.top();
    }
};