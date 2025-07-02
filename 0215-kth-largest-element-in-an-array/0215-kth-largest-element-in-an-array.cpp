class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)  
    {
     
        priority_queue<int>que; 
        for(auto it:nums)
        {
            que.push(it);
        } 

        int num=0;
        while(k--) 
        {
            num=que.top();  
            que.pop();
        } 
        return num;
    }
};